#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define SORT(v) sort(v.begin(), v.end());
#define pb(a) push_back(a)
using ll = long long;
using namespace std;

signed main(){
    int n, m, j, target[110], tmp, targetScore, score[110];
    cin >> n >> m;
    REP(i, n){
        score[i] = 0;
    }
    REP(i, m){
        cin >> target[i];
    }
    REP(i, m){
        targetScore = n;
        REP(j, n){
            cin >> tmp;
            if(tmp == target[i]){
                score[j]++;
                targetScore--;
            }
        }
        score[target[i] - 1] += targetScore;
    }
    REP(i, n){
        cout << score[i] << endl;
    }
    return 0;
}
