import requests
import re
import urllib
import os
import sys
import lxml.html
import pathlib
# from bs4 import BeautifulSoup

LOGIN_URL = 'https://beta.atcoder.jp/login'

def get_session():
	s = requests.Session()
	r = s.get(LOGIN_URL)
	cookie = urllib.parse.unquote(r.headers['Set-Cookie'])
	pat = re.compile('csrf_token:.*=\x00')
	csrf_token = pat.search(cookie).group(0)[11:-1]
	payload = {
		'username': os.environ.get('AtCoder_username'),
		'password': os.environ.get('AtCoder_password'),
		'csrf_token': csrf_token
	}
	s.post(LOGIN_URL, data=payload)
	return s

if __name__ == '__main__':

	args = sys.argv
	session = get_session()
	res = session.get(f'https://beta.atcoder.jp/contests/{args[1]}/tasks/{args[2]}?lang=ja')
	tree = lxml.html.fromstring(res.text)
	cnt = 1
	pathlib.Path('./testcase').mkdir(exist_ok=True)

	while True:
		if len(tree.xpath(f'//h3[text()="Sample Input {cnt}"]')) == 0:
			break
		input_data = tree.xpath(f'//h3[text()="Sample Input {cnt}"]')[0].getnext().text
		output_data = tree.xpath(f'//h3[text()="Sample Output {cnt}"]')[0].getnext().text
		path = pathlib.Path(f'./testcase/{args[2]}_in{cnt}.txt')
		path.touch()
		path.write_text(input_data.rstrip())
		path = pathlib.Path(f'./testcase/{args[2]}_out{cnt}.txt')
		path.touch()
		path.write_text(output_data.rstrip())
		cnt += 1

	print(f'Successfully downloaded {cnt - 1} testcases')