#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define SORT(v) sort(v.begin(), v.end());
#define pb(a) push_back(a)
using ll = long long;
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int cost = 0, tmp, min = 0, minCost = 0, a, b;
    REP(i, m){
        cin >> a >> b;
        if(a >= n){
        }else if(min < (b - n)){
            min = b - n;
            cost += minCost;
            minCost = b - n;
        }else{
            cost += b - n;
        }
    }
    cout << cost << endl;
    return 0;
}
