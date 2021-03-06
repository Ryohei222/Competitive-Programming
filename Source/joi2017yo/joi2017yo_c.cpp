#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define SORT(v) sort(v.begin(), v.end());
#define pb(a) push_back(a)
using ll = long long;
using namespace std;

int main(){
    int n, m, d, k, answer = 0;
    cin >> n >> m >> d;
    char map[110][110];
    REP(i, n){
        cin >> map[i];
    }
    REP(i, n){
        REP(j, m - d + 1){
            k = 0;
            while(1){
                if(k == d){
                    answer++;
                    break;
                }else if(map[i][j + k] == '#'){
                    break;
                }else{
                    k++;
                }
            }
        }
    }
    REP(i, m){
        REP(j, n - d + 1){
            k = 0;
            while(1){
                if(k == d){
                    answer++;
                    break;
                }else if(map[j + k][i] == '#'){
                    break;
                }else{
                    k++;
                }
            }
        }
    }
    cout << answer << endl;
    return 0;
}
