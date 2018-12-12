#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <map>
#include <set>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <stdlib.h>

using namespace std;
 
typedef long long ll;
typedef pair<int, int> P;
static const int INF = 1000010000;
static const int MOD = 1000000007;
 
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define SORT(v) sort(v.begin(), v.end());
#define pb push_back
#define mp make_pair
#define np next_permutation
#define pq priority_queue

//int dx4[4] = {0,1,0,-1}, dy4[4] = {-1,0,1,0};
//int dx5[5] = {-1,0,0,0,1}, dy5[5] = {0,-1,0,1,0};
int dx[8] = {-1,0,1,1,1,0,-1,-1}, 
    dy[8] = {1,1,1,0,-1,-1,-1,0};
//int dx9[9] = {-1,0,1,1,1,0,-1,-1,0}, dy9[9] = {1,1,1,0,-1,-1,-1,0,0};

//-----end of template-----//

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int h, w;
    cin >> h >> w;
    vector<string> s(h), next_s;
    REP(i, h) cin >> s[i];

    queue<P> current, next;

    REP(i, h) REP(j, w){
        if(s[i][j] != '.' && s[i][j] != '9') current.push(P(i, j));
    }
    next_s = move(s);

    int ans = 0;

    while(current.size() > 0){
        s = next_s;
        while(current.size() > 0){
            auto p = current.front(); current.pop();
            int x = p.first, y = p.second;
            int cnt = 0;
            bool flag = true;
            if(s[x][y] == '.' || s[x][y] == '9') continue;
            REP(k, 8){
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(s[nx][ny] == '.') cnt++;
            }
            if(s[x][y] - '0' <= cnt){
                flag = false;
                next_s[x][y] = '.';
                REP(k, 8){
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if(!(s[nx][ny] == '.' || s[nx][ny] == '9' || next_s[nx][ny] == '.' || next_s[nx][ny] == '9')){
                        next.push(P(nx, ny));
                    }
                }
            }
        }
        ans++;
        cout << next.size() << endl;
        current = move(next);
    }

    cout << ans << endl;
}