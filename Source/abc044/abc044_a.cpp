#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define SORT(v) sort(v.begin(), v.end());
#define pb(a) push_back(a)
using ll = long long;
using namespace std;

int main(){
    int n, k, x, y;
    cin >> n >> k >> x >> y;
    if(n > k) cout << x * k + (n - k) * y << endl;
    if(n <= k) cout << x * n << endl;
    return 0; 
}
