#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define SORT(v) sort(v.begin(), v.end());
#define pb(a) push_back(a)
using ll = long long;
using namespace std;

signed main(){
    int n, m, k;
    cin >> n >> m;
    int card[202], tmp[202];
    FOR(i, 1, 2 * n + 2){
        card[i] = i;
    }
    REP(i, m){
        cin >> k;
        if(k == 0){
            FOR(j, 1, n + 1){
                tmp[2 * j - 1] = card[j];
                tmp[2 * j] = card[n + j];
            }
        }else{
            FOR(j, 1, k + 1){
                tmp[2 * n - k + j] = card[j];
            }
            FOR(j, k + 1, 2 * n + 1){
                tmp[j - k] = card[j];
            }
        }
        FOR(j, 1, 2 * n + 1){
            card[j] = tmp[j];
        }
    }
    FOR(j, 1, 2 * n + 1){
        cout << card[j] << endl;
    }
    return 0;
}
