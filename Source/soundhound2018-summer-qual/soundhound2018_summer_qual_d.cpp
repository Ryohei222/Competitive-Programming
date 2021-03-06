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
typedef pair<ll, ll> P;
typedef pair<ll, P> PP;
static const int INF = 1000010000;
static const ll MOD = 998244353;
 
#define FOR(i, a, b) for(ll i = (a); i < (b); ++i)
#define REP(i, n) for(ll i = 0; i < (n); ++i)
#define SORT(v) sort(v.begin(), v.end());
#define pb push_back
#define mp make_pair
#define np next_permutation
#define pq priority_queue

//int dx[4] = {0,1,0,-1}, dy[4] = {-1,0,1,0};
//int dx5[5] = {-1,0,0,0,1}, dy5[5] = {0,-1,0,1,0};
//int dx8[8] = {-1,0,1,1,1,0,-1,-1}, dy8[8] = {1,1,1,0,-1,-1,-1,0};
//int dx9[9] = {-1,0,1,1,1,0,-1,-1,0}, dy9[9] = {1,1,1,0,-1,-1,-1,0,0};


ll V;
struct edge{ ll to, cost; };
ll d[2][100010];
vector<edge> G[2][100010];

ll dijkstra(ll s, ll flag){
    priority_queue<P, vector<P>, greater<P> > que;
    que.push(P(0, s));

    while(!que.empty()){
        P p = que.top();que.pop();
        ll v = p.second;
        if(d[flag][v] < p.first) continue;

        //vと繋がっている頂点についてコストが下がるかどうかを調べる
        FOR(i, 0, G[flag][v].size()){
            edge e = G[flag][v][i];
            if(d[flag][e.to] > d[flag][v] + e.cost){
                d[flag][e.to] = d[flag][v] + e.cost;
                que.push(P(d[flag][e.to], e.to));
            }
        }
    }
}

int main(){
    ll n, m, s, t;
    cin >> n >> m >> s >> t;
    s--; t--;
    REP(i, m){
        ll u, v, a, b;
        cin >> u >> v >> a >> b;
        edge e;
        u--; v--;
        e.to = v; e.cost = a;
        G[0][u].push_back(e);
        e.to = u; e.cost = a;
        G[0][v].push_back(e);
        e.to = v; e.cost = b;
        G[1][u].push_back(e);
        e.to = u; e.cost = b;
        G[1][v].push_back(e);
    }
    REP(k, 2){
        REP(i, n){
            d[k][i] = 1e+15;
        }
    }
    d[0][s] = 0;
    d[1][t] = 0;
    dijkstra(s, 0);
    dijkstra(t, 1);
    ll ans[100010];
    ll c = 1e+15;
    for(ll i = n - 1; i >= 0; i--){
        if(i == n - 1){
            ans[i] = c - (d[0][i] + d[1][i]);
        }else{
            ans[i] = max(ans[i + 1], c - (d[0][i] + d[1][i]));
        }
    }
    REP(i, n){
        cout << ans[i] << endl;
    }
}
