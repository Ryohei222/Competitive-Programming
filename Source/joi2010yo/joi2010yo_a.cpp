#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define SORT(v) sort(v.begin(), v.end());
#define pb(a) push_back(a)
using ll = long long;
using namespace std;

signed main(){
    int tmp, sum;
    cin >> sum;
    REP(i, 9){
        cin >> tmp;
        sum -= tmp;
    }
    cout << sum << endl;
    return 0;
}
