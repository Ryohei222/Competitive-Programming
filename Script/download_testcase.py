import requests
import os
import lxml.html
import pathlib
import sys


class AtCoder:

	LOGIN_URL = 'https://beta.atcoder.jp/login'

	def __init__(self):
		self.session = requests.Session()
		response = self.session.get(self.LOGIN_URL)
		tree = lxml.html.fromstring(response.text)
		self.csrf_token = tree.xpath('//*[@name="csrf_token"]/@value')[0]
		payload = {
			'username':os.environ.get('AtCoder_username'),
			'password':os.environ.get('AtCoder_password'),
			'csrf_token':self.csrf_token
		}
		self.session.post(self.LOGIN_URL, data=payload)

	def get_problems(self, contest_id):
		res = self.session.get(f'https://beta.atcoder.jp/contests/{contest_id}/submit')
		tree = lxml.html.fromstring(res.text)
		problems = tree.xpath('//*[@id="select-task"]/option/@value')
		return problems

	def get_testcase(self, contest_id, problem_id, testcase_id):
		res = self.session.get(f'https://beta.atcoder.jp/contests/{contest_id}/tasks/{problem_id}?lang=ja')
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
		self.session.post(f'https://beta.atcoder.jp/contests/{contest_id}/submit', data=payload)


if __name__ == '__main__':

	contest_id = sys.argv[1]
	atcoder = AtCoder()
	atcoder.save_testcases(contest_id)
