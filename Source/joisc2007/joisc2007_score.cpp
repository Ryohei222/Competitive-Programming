#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define SORT(v) sort(v.begin(), v.end());
#define pb(a) push_back(a)
using ll = long long;
using namespace std;

signed main(){
    int i, n, j, rank = 1;
    int score[100010], chohuku[101], output[100010];
    REP(i, 101){
        chohuku[i] = 0;
    }
    cin >> n;
    REP(i, n){
        cin >> score[i];
        chohuku[score[i]]++;
    }
    for(i = 100; i > -1; i--){
        REP(j, n){
            if(score[j] == i){
                output[j] = rank;
            }
        }
        rank += chohuku[i];
    }
    REP(i, n){
        cout << output[i] << endl;
    }
    return 0;
}
