#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define SORT(v) sort(v.begin(), v.end());
#define pb(a) push_back(a)
using ll = long long;
using namespace std;

int main(){
    ll friendCount[501];
    int n, m, a, b, cnt;
    bool friendList[501][501], answer[501];
    REP(i, 501){
        friendCount[i] = 0;
        answer[i] = false;
        REP(j, 501){
            friendList[i][j] = false;
        }
    }
    cin >> n >> m;
    REP(i, m){
        cin >> a >> b;
        friendList[a][b] = true;
        friendList[b][a] = true;
        friendCount[a]++;
        friendCount[b]++;
    }
    cnt = (int)friendCount[1];
    int i = 2;
    while(cnt){
        if(friendList[1][i]){
            answer[i] = true;
            FOR(j, 1, n + 1){
                if(friendList[i][j]){
                    answer[j] = true;
                }
            }
            cnt--;
        }
        i++;
    }
    int num = 0;
    FOR(i, 2, 501){
        if(answer[i]){
            num++;            
        }
    }
    cout << num << endl;
}
