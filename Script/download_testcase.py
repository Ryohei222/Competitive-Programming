import sys
import requests
import re
from bs4 import BeautifulSoup
from getpass import getpass

'''
This code is written by kutimotitokura, keidaroo => https://github.com/kutimoti/AtCoderSubmitter.vim/blob/master/pythonx/AtCoderSubmitter.py 
'''

session = requests.Session()
is_logged_in = False

def LoginSession(payload):
    """
    ログインしてセッション情報ををsessionに格納する

    Parameters
    ----------
        payload : dict
            ユーザー名とパスワード
    """
    r = session.get('https://beta.atcoder.jp/login')
    soup = BeautifulSoup(r.text,"html.parser")
    csrf_token = soup.find(attrs = {'name' : 'csrf_token'}).get('value')
    payload['csrf_token'] = csrf_token
    session.post('https://beta.atcoder.jp/login' , data = payload)

def Login(username,password):
    """
    username, passwordを受け取ってLoginSession()を実行

    Parameters
    ----------
        username : str
            ユーザー名
        password : str
            パスワード
    """
    payload = {
        'username' : username,
        'password' : password
    }
    LoginSession(payload)
    is_logged_in = True

def DownLoadSamples(contest_id, problem_id):
    """
    指定された問題のテストケースをダウンロードします
    Parameters
    ----------
        contest_id : str
        problem_id : str
    Returns
    ----------
        status : int
            ページが見つかれば0、そうでなければ-1を返します
    """

    url = "https://beta.atcoder.jp/contests/%s/tasks/%s" % (contest_id, problem_id)
    res = session.get(url)

"""
def Submit(contest_id,problem_id,source):
    submit_page = session.get('https://beta.atcoder.jp/contests/%s/submit' % contest_id)
    submit_data = {
        'data.TaskScreenName': problem_id,
        'data.LanguageId' : 3003, # This means C++14 (gcc)
        'sourceCode' : source
    }
    soup = BeautifulSoup(submit_page.text,"lxml")
    csrf_token = soup.find(attrs = {'name' : 'csrf_token'}).get('value')
    submit_data['csrf_token'] = csrf_token
    result = session.post('https://beta.atcoder.jp/contests/%s/submit' % contest_id ,data = submit_data)
    #return result.status_code == requests.codes.ok

def SubmitCode(contest_id,problem_id):
    source = '\n'.join(vim.eval('getline(0,"$")'))
    if Submit(contest_id,problem_id,source) == 1:
        vimecho('Submit')

def ShowSubmissions(url,args):
    soup = BeautifulSoup(session.get(url , data = args).text,"html.parser")
    trs = soup.find("tbody").find_all("tr")
    vim.command('new ACSubmission')
    vim.command('setlocal buftype=nowrite ')
    for tr in trs:
        judge = tr.find(attrs = {'class' : re.compile('label label')}).text
        score = tr.find(attrs = {'class' : 'text-right submission-score'}).text
        problem = tr.find("a" , href = re.compile('tasks')).text
        user = tr.find("a" , href = re.compile('users')).text
        vim.current.buffer.append('{0} = [{1} - {2}] @{3}'.format(problem , judge , score , user))
"""

if __name__ == "__main__":
    username = input("username: ")
    password = getpass("password: ")
    Login(username, password)
    