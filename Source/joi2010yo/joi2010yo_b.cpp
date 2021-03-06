#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define SORT(v) sort(v.begin(), v.end());
#define pb(a) push_back(a)
using ll = long long;
using namespace std;

signed main(){
    int cnt = 0, map[1002], dice[1001], n, m, tmp, now = 1;
    cin >> n >> m;
    map[1] = 0;
    REP(i, n){
        cin >> map[i + 1];
    }
    REP(i, m){
        cin >> dice[i];
    }
    while(now < n){
        now += dice[cnt];
        cnt++;
        if(now >= n){
            break;
        }else{
            now += map[now];
        }
    }
    cout << cnt << endl;
    return 0;
}
