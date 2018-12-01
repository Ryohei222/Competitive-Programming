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

//int dx[4] = {0,1,0,-1}, dy[4] = {-1,0,1,0};
//int dx[5] = {-1,0,0,0,1}, dy[5] = {0,-1,0,1,0};
//int dx[8] = {-1,0,1,1,1,0,-1,-1}, dy[8] = {1,1,1,0,-1,-1,-1,0};
//int dx[9] = {-1,0,1,1,1,0,-1,-1,0}, dy[9] = {1,1,1,0,-1,-1,-1,0,0};

//-----end of template-----//

struct edge{
    ll from, to;
    edge(ll from, ll to) : from(from), to(to) {}
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, k;
    cin >> n >> k;
    vector<ll> c(n), r(n), a(k), b(k);
    REP(i, n) cin >> c[i] >> r[i];

    vector<vector<edge> > G;
    G = vector<vector<edge> >(n);

    REP(i, k){
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
        G[a[i]].push_back(edge(a[i], b[i]));
        G[b[i]].push_back(edge(b[i], a[i]));
    }
    vector<vector<ll> > dist;
    dist = vector<vector<ll> >(n, vector<ll>(n, INF));

    REP(i, n){
        queue<P> que;
        dist[i][i] = 0;
        que.push(P(i, 0));
        while(!que.empty()){
            P p = que.front(); que.pop();
            ll v = p.first;
            ll d = p.second;
            for(auto e : G[v]){
                if(dist[i][e.to] == INF){
                    dist[i][e.to] = d + 1;
                    que.push(P(e.to, dist[i][e.to]));
                }
            }
        }
    }

    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push(P(0, 0)); // P(cost, node)
    vector<ll> cost(n, -1);
    while(!pq.empty()){
        auto p = pq.top(); pq.pop();
        ll d = p.first, v = p.second;
        cost[v] = d;
        if(v == n - 1){
            break;
        }
        REP(i, n){
            if(i == v || dist[v][i] > r[v]) continue;
            else if(cost[i] == -1 || cost[i] > cost[v] + c[v]){
                cost[i] = d + c[v];
                pq.push(P(cost[i], i));
            }
        }
    }

    cout << cost[n - 1] << endl;

    /*REP(i, n){
        cout << dist[0][i] << endl;
    }*/
}