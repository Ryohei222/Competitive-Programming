#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define SORT(v) sort(v.begin(), v.end());
#define pb(a) push_back(a)
using ll = long long;
using namespace std;


int main(){
    ll n, m, answer = 0, now = 0, flag = 0;
    string s;
    cin >> n >> m >> s;
    while(now < m){
        if(flag >= 2 * n && flag % 2 == 0 && s[now] == 'I'){
            answer++;
          	flag++;
        }else if(flag % 2 == 0){
            if(s[now] == 'O'){
                flag = 0;
            }else{
                flag++;
            }
        }else{
            if(s[now] == 'I'){
                flag = 1;
            }else{
                flag++;
            }
        }
        now++;
    }
    cout << answer << endl;
}
