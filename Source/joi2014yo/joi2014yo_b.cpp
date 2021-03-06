#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define SORT(v) sort(v.begin(), v.end());
#define pb(a) push_back(a)
using ll = long long;
using namespace std;

#define INF 1050

signed main(){
    int tmp, n, m, a, vote[1050], rank[1050];
    cin >> n >> m;
    REP(i, 1050){
        rank[i] = INF;
        vote[i] = 0;
    }
    REP(i, n){
        cin >> a;
        for(int j = a; j < 1050; j++){
            if(rank[j] < i){
                break;
            }
            rank[j] = i;
        }
    }
    REP(i, m){
        cin >> tmp;
        vote[rank[tmp]]++;
    }
    int max = 0, id = 0;
    REP(i, n){
        if(max < vote[i]){
            max = vote[i];
            id = i;
        }
    }
    cout << id + 1 << endl;
    return 0;
}
