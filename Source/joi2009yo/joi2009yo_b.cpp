#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define SORT(v) sort(v.begin(), v.end());
#define pb(a) push_back(a)
using ll = long long;
using namespace std;

signed main(){
    vector<int> veca, vecb;
    int tmp;
    REP(i, 10){
        cin >> tmp;
        veca.pb(tmp);
    }
    REP(i, 10){
        cin >> tmp;
        vecb.pb(tmp);
    }
    SORT(veca);
    SORT(vecb);
    cout << veca[9] + veca[8] + veca[7] << " " << vecb[9] + vecb[8] + vecb[7] << endl;
}
