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

int dx4[4] = {0,1,0,-1}, dy4[4] = {-1,0,1,0};
//int dx5[5] = {-1,0,0,0,1}, dy5[5] = {0,-1,0,1,0};
//int dx8[8] = {-1,0,1,1,1,0,-1,-1}, dy8[8] = {1,1,1,0,-1,-1,-1,0};
//int dx9[9] = {-1,0,1,1,1,0,-1,-1,0}, dy9[9] = {1,1,1,0,-1,-1,-1,0,0};

//-----end of template-----//
 
int main() {
    // 入力
    ll dp[31][31], a[31][31], dist[31][31];
    ll h, w;
    cin >> h >> w;
    REP(i, 31) {
        REP(j, 31) {
            dist[i][j] = -1;
        }
    }
    REP(i, h) {
        REP(j, w) {
            cin >> a[i][j];
        }
    }

    dist[0][0] = 0; // (0, 0)までの距離は0
    dp[0][0] = 0; // (0, 0)までのコストは0
    queue<P> que;
    que.push(P(0, 0)); // (0, 0)からスタート

    while (!que.empty()) {
        auto p = que.front(); que.pop();
        int x = p.first; int y = p.second; // もともといたマス

        REP(i, 4) {
            int nx = x + dx4[i]; int ny = y + dy4[i]; //四近傍で回す
            if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue; // 領域内か判定
            ll cost = dp[x][y] + (dist[x][y] * 2 + 1) * a[nx][ny]; // https://twitter.com/6Lgug/status/1066718346509348864

            // 行っていないマスもしくは行っているけど現在のコストのほうが少ないなら更新
            if (dist[nx][ny] == -1 || dp[nx][ny] > cost) {
                dp[nx][ny] = cost;
                dist[nx][ny] = dist[x][y] + 1; // 距離は前のマスまでの距離+1なので
                que.push(P(nx, ny));
                continue;
            }

            // コストが同じでも距離が短いなら更新((nx, ny)以降のマスまでの最小コストが減りうるので)
            if(dp[nx][ny] == cost && dist[nx][ny] > dist[x][y] + 1) {
                dist[nx][ny] = dist[x][y] + 1;
                que.push(P(nx, ny));
            }
        }
    }
    cout << dp[h - 1][w - 1] << endl; // 出力
}