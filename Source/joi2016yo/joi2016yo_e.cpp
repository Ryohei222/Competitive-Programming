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
typedef pair<ll, ll> P;
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
//int dx8[8] = {-1,0,1,1,1,0,-1,-1}, dy8[8] = {1,1,1,0,-1,-1,-1,0};
//int dx9[9] = {-1,0,1,1,1,0,-1,-1,0}, dy9[9] = {1,1,1,0,-1,-1,-1,0,0};

//-----end of template-----//

#define SAFE 0
#define DANGER 1
#define ZOMBIE 2

struct edge{
    ll from, to;
    edge(ll from, ll to) : from(from), to(to) {}
};

struct wedge{
    ll from, to, cost;
    wedge(ll from, ll to, ll cost) : from(from), to(to), cost(cost) {}
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, m, k, s, p, q;
    cin >> n >> m >> k >> s >> p >> q;

    vector<vector<edge> > edges;
    edges = vector<vector<edge> >(n + 1, vector<edge>(0));
    vector<ll> a(m), b(m);
    vector<ll> c(k);

    REP(i, k){
        cin >> c[i];
        edges[0].push_back(edge(0, c[i]));
        edges[c[i]].push_back(edge(c[i], 0));
    }

    REP(i, m){
        int na, nb;
        cin >> na >> nb;
        a[i] = na;
        b[i] = nb;
        edges[na].push_back(edge(na, nb));
        edges[nb].push_back(edge(nb, na));
    }

    vector<ll> dist(n + 1);
    fill(dist.begin(), dist.end(), INF);

    queue<P> que;
    que.push(P(0, -1));
    while(que.size() != 0){
        P p = que.front(); que.pop();
        ll node = p.first;
        ll cost = p.second;
        if(dist[node] <= cost) continue;
        dist[node] = cost;
        REP(i, edges[node].size()){
            edge e = edges[node][i];
            if(dist[e.to] > cost + 1){
                que.push(P(e.to, cost + 1));
            }
        }
    }

    vector<int> state(n + 1);
    REP(i, k){
        state[c[k]] = ZOMBIE;
    }
    FOR(i, 1, n + 1){
        if(state[i] != ZOMBIE){
            if(dist[i] <= s) state[i] = DANGER;
            else state[i] = SAFE;
        }
    }
    vector<vector<wedge> > G;
    G = vector<vector<wedge> >(n + 1, vector<wedge>(0));
    REP(i, m){
        int u = a[i], v = b[i];
        if(state[u] == ZOMBIE || state[v] == ZOMBIE) continue;
        if(state[v] == SAFE) G[u].push_back(wedge(u, v, p));
        else G[u].push_back(wedge(u, v, q));
    }

    fill(dist.begin(), dist.end(), INF);
    priority_queue<P, vector<P>, greater<P> > pque;
    dist[1] = 0;
    pque.emplace(0, 1);
    while(!pque.empty()){
        auto p = pque.top(); pque.pop();
        ll d = p.first;
        ll idx = p.second;
        if(dist[idx] < d) continue;
        REP(i, G[idx].size()){
            wedge e = G[idx][i];
            ll ncost = d + e.cost;
            if(dist[e.to] <= ncost) continue;
            dist[e.to] = ncost;
            pque.push(P(dist[e.to], e.to));
        }
    }

    cout << dist[n] << endl;
}