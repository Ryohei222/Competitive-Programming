#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define SORT(v) sort(v.begin(), v.end());
#define pb(a) push_back(a)
using ll = long long;
using namespace std;

signed main(){
    int pasta = 2001, juice = 2001, tmp;
    REP(i, 3){
        cin >> tmp;
        if(pasta > tmp){
            pasta = tmp;
        }
    }
    REP(i, 2){
        cin >> tmp;
        if(juice > tmp){
            juice = tmp;
        }
    }
    cout << pasta + juice - 50 << endl;
    return 0;
}
