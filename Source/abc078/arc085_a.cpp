#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define SORT(v) sort(v.begin(), v.end());
#define pb(a) push_back(a)
using ll = long long;
using namespace std;

int main(){
    ll n, m;
    cin >> n >> m;
    ll hyaku = 100 * (n - m);
    ll sen = 1900 * m;
    cout << pow(2, m) * (hyaku + sen) << endl;
}
