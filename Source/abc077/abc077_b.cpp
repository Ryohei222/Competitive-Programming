#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define SORT(v) sort(v.begin(), v.end());
#define pb(a) push_back(a)
using ll = long long;
using namespace std;

signed main(){
    ll input, i = 1;
    cin >> input;
    while(1){
        if(i * i > input){
            i--;
            break;
        }
        i++;
    }
  	ll answer = i * i;
    cout << answer << endl;
    return 0;
}
