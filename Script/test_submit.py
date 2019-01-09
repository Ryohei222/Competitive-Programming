import os
import pathlib
import subprocess
import sys

import lxml.html
import requests


class AtCoder:

	LOGIN_URL = 'https://atcoder.jp/login'

	def __init__(self):
		self.session = requests.Session()
		response = self.session.get(self.LOGIN_URL)
		tree = lxml.html.fromstring(response.text)
		self.csrf_token = tree.xpath('//*[@name="csrf_token"]/@value')[0]
		payload = {
			'username':os.environ.get('ATCODER_USERNAME'),
			'password':os.environ.get('ATCODER_PASSWORD'),
			'csrf_token':self.csrf_token
		}
		self.session.post(self.LOGIN_URL, data=payload)

	def get_problems(self, contest_id):
		res = self.session.get(f'https://atcoder.jp/contests/{contest_id}/submit')
		tree = lxml.html.fromstring(res.text)
		problems = tree.xpath('//*[@id="select-task"]/option/@value')
		return problems

	def get_testcase(self, contest_id, problem_id, testcase_id):
		res = self.session.get(f'https://atcoder.jp/contests/{contest_id}/tasks/{problem_id}?lang=ja')
		tree = lxml.html.fromstring(res.text) # raise Exception()
		if len(tree.xpath(f'//h3[text()="Sample Input {testcase_id}"]')) == 0:
			raise Exception()
		testcase = {
			'in':tree.xpath(f'//h3[text()="Sample Input {testcase_id}"]')[0].getnext().text,
			'out':tree.xpath(f'//h3[text()="Sample Output {testcase_id}"]')[0].getnext().text
		}
		return testcase

	def save_testcases(self, contest_id):
		problems = self.get_problems(contest_id)
		pathlib.Path('./testcase').mkdir(exist_ok=True)
		for problem_id in problems:
			testcase_id = 1
			while True:
				try:
					testcase = self.get_testcase(contest_id, problem_id, testcase_id)
				except:
					break
				for key in testcase.keys():
					path = pathlib.Path(f'./testcase/{problem_id}_{key}{testcase_id}.txt')
					path.touch()
					path.write_text(testcase[key].rstrip())
				testcase_id += 1


	def submit(self, contest_id, problem_id, submit_data, language_id):
		payload = {
			'data.TaskScreenName':problem_id,
			'data.LanguageId':language_id,
			'sourceCode':submit_data,
			'csrf_token':self.csrf_token
		}
		self.session.post(f'https://atcoder.jp/contests/{contest_id}/submit', data=payload)

def compile(filename):
	if pathlib.Path(f'./a.exe').exists():
		pathlib.Path('./a.exe').unlink()
	if pathlib.Path(f'./a.out').exists():
		pathlib.Path('./a.out').unlink()
	if pathlib.Path(f'./{filename}').exists():
		proc = subprocess.run(['g++', '-std=c++14', '-O2', filename], stdout = subprocess.PIPE, stderr = subprocess.PIPE)
		return proc.stderr.decode('utf-8')
	else:
		print('TLE')
		return 'error'

def run_test(filename):
	proc = subprocess.Popen(['./a.exe'], stdin = subprocess.PIPE, stdout = subprocess.PIPE, stderr = subprocess.PIPE)
	try:
		res = proc.communicate(input = pathlib.Path(filename).open().read().encode('utf-8'), timeout = 10)
		return res
	except subprocess.TimeoutExpired:
		proc.kill()
		exit(-1)

if __name__ == '__main__':
	args = sys.argv
	contest_id = args[1]
	problem_id = args[2]
	atcoder = AtCoder()
	atcoder.save_testcases(contest_id)
	filename = f'{problem_id}.cpp'
	if 'error' in compile(filename):
		print('failed in compile')
		exit(-1)
	else:
		print('succeeded in compile')
	testcase_id = 1
	print('---------------------------')
	flag = True
	while pathlib.Path(f'./testcase/{problem_id}_in{testcase_id}.txt').exists():
		path_in = f'./testcase/{problem_id}_in{testcase_id}.txt'
		path_out = f'./testcase/{problem_id}_out{testcase_id}.txt'
		res = run_test(path_in)[0].decode('utf-8').rstrip()
		ans = pathlib.Path(path_out).open().read()
		print(f'test{testcase_id} status:', end='')
		if res == ans:
			#cprint('AC', 'green')
			print('AC')
		else:
			#cprint('WA', 'yellow')
			print('WA')
			flag = False
		print('sample input\n', pathlib.Path(path_in).open().read())
		print('program output\n', res)
		print('sample output\n', ans)
		print('---------------------------')
		testcase_id += 1
	if flag:
		flag = input('All testcases passed. Submit this solution? (y/n): ')
		if flag == 'y':
			atcoder.submit(contest_id, f'{contest_id}_{problem_id}', pathlib.Path(f'{contest_id}_{problem_id}.cpp').open().read(), 3003)