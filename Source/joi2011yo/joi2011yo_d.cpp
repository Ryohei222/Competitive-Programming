#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define SORT(v) sort(v.begin(), v.end());
#define pb(a) push_back(a)
using ll = long long;
using ull = unsigned long long;
using namespace std;

int main(){
    int n, now;
    ull answer[100][21];
    REP(i, 21){
        REP(j, 100){
            answer[j][i] = 0;
        }
    }
    cin >> n >> now;
    answer[1][now] = 1;
    FOR(i, 2, n){
        cin >> now;
        REP(j, 21){
            if(j + now <= 20 && answer[i - 1][j] != 0){
                answer[i][j + now] += answer[i - 1][j];
            }
            if(j - now >= 0 && answer[i - 1][j] != 0){
                answer[i][j - now] += answer[i - 1][j];
            }
        }
    }
    cin >> now;
    cout << answer[n - 1][now] << endl;
}
