#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define SORT(v) sort(v.begin(), v.end());
#define pb(a) push_back(a)
using ll = long long;
using namespace std;

signed main(){
    int time = 0, tmp;
    REP(i, 4){
        cin >> tmp;
        time += tmp;
    }
    cout << time / 60 << endl << time % 60 << endl;
    return 0;
}
