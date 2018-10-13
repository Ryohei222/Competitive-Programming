#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define SORT(v) sort(v.begin(), v.end());
#define pb(a) push_back(a)
using ll = long long;
using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    char c;
    bool cans[1000];
    REP(i, n){
        cin >> c;
        if(c == '0'){
            cans[i] = false;
        }else{
            cans[i] = true;
        }
    }
    ll t, ans = 0;
    REP(i, n){
        cin >> t;
        if(cans[i] && (int)x < t){
            ans += (int)x;
        }else{
            ans += t;
        }
    }
    cout << ans << endl;
}
