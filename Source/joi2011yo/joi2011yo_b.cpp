#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define SORT(v) sort(v.begin(), v.end());
#define pb(a) push_back(a)
using ll = long long;
using namespace std;

signed main(){
    string search, str;
    int n, answer = 0;
    cin >> search >> n;
    REP(i, n){
        cin >> str;
        str = str + str;
        if(str.find(search) != std::string::npos){
            answer++;
        }
    }
    cout << answer << endl;
    return 0;
}
