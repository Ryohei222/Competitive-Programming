#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define SORT(v) sort(v.begin(), v.end());
#define pb(a) push_back(a)
using ll = long long;
using namespace std;

signed main(){
    int a[100], tmp;
    FOR(i, 1, 31){
        a[i] = i;
    }
    REP(i, 28){
        cin >> tmp;
        a[tmp] = 0;
    }
    tmp = 0;
    int i = 1;
    while(tmp != 2){
        if(a[i] == i){
            cout << i << endl;
            tmp++;
        }
        i++;
    }
    return 0;
}
