#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define SORT(v) sort(v.begin(), v.end());
#define pb(a) push_back(a)
using ll = long long;
using namespace std;

signed main(){
    string str;
    int joi = 0, ioi = 0;
    cin >> str;
    REP(i, str.length() - 2){
        if(str[i] == 'J' && str[i + 1] == 'O' && str[i + 2] == 'I'){
            joi++;
        }else if(str[i] == 'I' && str[i + 1] == 'O' && str[i + 2] == 'I'){
            ioi++;
        }
    }
    cout << joi << endl << ioi << endl;
    return 0;
}
