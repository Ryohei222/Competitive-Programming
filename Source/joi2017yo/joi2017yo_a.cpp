#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define SORT(v) sort(v.begin(), v.end());
#define pb(a) push_back(a)
using ll = long long;
using namespace std;

int main(){
    int a, b , c, d, e;
    cin >> a >> b >> c >> d >> e;
    int answer = 0;
    while(1){
        if(a == b){
            break;
        }
        if(a < 0){
            answer += c;
            a++;
        }else if(a == 0){
            answer += d + e;
            a++;
        }else if(a < b){
            answer += e;
            a++;
        }
    }
    cout << answer << endl;
    return 0;
}
