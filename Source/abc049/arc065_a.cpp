#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define SORT(v) sort(v.begin(), v.end());
#define pb(a) push_back(a)
using ll = long long;
using namespace std;
 
int main(){
    string s;
    cin >> s;
    int p = 0;
    bool flag;
    string t = "";
    string dic[6] = { "dreameraser", "dreamerase", "dreamer", "dream", "eraser", "erase"};
    while(s != t){
        flag = true;
        REP(i, 6){
            if(s.substr(p, dic[i].length()) == dic[i]){
                t += dic[i];
                p += dic[i].length();
                flag = false;
                break;
            }
        }
        if(flag){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}
