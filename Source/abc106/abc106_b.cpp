#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <cstring>
#include <unordered_set>
#include <unordered_map>

using namespace std;
 
typedef long long ll;
typedef pair<int, int> P;
static const ll INF = 1000010000;
static const ll MOD = 1000000007;
 
#define FOR(i, a, b) for(ll i = (a); i < (b); ++i)
#define REP(i, n) for(ll i = 0; i < (n); ++i)
#define SORT(v) sort(v.begin(), v.end());
#define pb push_back
#define mp make_pair
#define np next_permutation

//int dx[4] = {0,1,0,-1}, dy[4] = {-1,0,1,0};
//int dx5[5] = {-1,0,0,0,1}, dy5[5] = {0,-1,0,1,0};
//int dx8[8] = {-1,0,1,1,1,0,-1,-1}, dy8[8] = {1,1,1,0,-1,-1,-1,0};
//int dx9[9] = {-1,0,1,1,1,0,-1,-1,0}, dy9[9] = {1,1,1,0,-1,-1,-1,0,0};

#define all(c) (c).begin(), (c).end()

struct graph {
  int L, R;
  vector<vector<int>> adj;
  graph(int L, int R) : L(L), R(R), adj(L+R) { }
  void add_edge(int u, int v) {
    adj[u].push_back(v+L);
    adj[v+L].push_back(u);
  }
  int maximum_matching() {
    vector<int> visited(L), mate(L+R, -1);
    function<bool(int)> augment = [&](int u) { // DFS
      if (visited[u]) return false;
      visited[u] = true;
      for (int w: adj[u]) {
        int v = mate[w];
        if (v < 0 || augment(v)) {
          mate[u] = w;
          mate[w] = u;
          return true;
        }
      }
      return false;
    };
    int match = 0;
    for (int u = 0; u < L; ++u) {
      fill(all(visited), 0);
      if (augment(u)) ++match;
    }
    return match;
  }
};

int main(){
	int n;
  cin >> n;
  int ans = 0;
  REP(i, n){
    int k = i + 1;
    if(k % 2 == 0) continue;
    int cnt = 0;
    REP(i, k){
      if(k % (i + 1) == 0) cnt++;
    }
    if(cnt == 8) ans++;
  }
  cout << ans << endl;
}
