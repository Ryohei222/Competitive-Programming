#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
 
typedef long long ll;
 
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) for(int i = 0; i < (n); ++i)

int main(){
    ll n, m;
    cin >> n >> m;
    ll cnt = 0;
    REP(i, n){
        cnt += (i + 1) * (i + 1);
        cnt %= m;
    }
    cout << cnt << endl;
}

