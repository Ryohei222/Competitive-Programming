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

	def submit(self, contest_id, problem_id, submit_data, language_id):
		payload = {
			'data.TaskScreenName':problem_id,
			'data.LanguageId':language_id,
			'sourceCode':submit_data,
			'csrf_token':self.csrf_token
		}
		self.session.post(f'https://beta.atcoder.jp/contests/{contest_id}/submit', data=payload)


if __name__ == '__main__':

	contest_id, problem_id = sys.argv[1], sys.argv[2]
	atcoder = AtCoder()
	path = pathlib.Path(f'./{problem_id}.cpp')
	f = open(path)
	source = f.read()
	atcoder.submit(contest_id, problem_id, source, 3003)