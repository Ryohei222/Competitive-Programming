#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define SORT(v) sort(v.begin(), v.end());
#define pb(a) push_back(a)
using ll = long long;
using namespace std;

signed main(){
    int time[3], tmp;
    REP(i, 3){
        time[i] = 0;
        cin >> tmp;
        time[i] -= tmp * 60 * 60;
        cin >> tmp;
        time[i] -= tmp * 60;
        cin >> tmp;
        time[i] -= tmp;
        cin >> tmp;
        time[i] += tmp * 60 * 60;
        cin >> tmp;
        time[i] += tmp * 60;
        cin >> tmp;
        time[i] += tmp;
    }
    REP(i, 3){
        tmp = 0;
        while(time[i] >= 3600){
            tmp++;
            time[i] -= 3600;
        }
        cout << tmp << " ";
        tmp = 0;
        while(time[i] >= 60){
            tmp++;
            time[i] -= 60;
        }
        cout << tmp << " ";
        tmp = 0;
        while(time[i] >= 1){
            tmp++;
            time[i] --;
        }
        cout << tmp << endl;
    }
    return 0;
}
