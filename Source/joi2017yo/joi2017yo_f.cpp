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

#define COLD 0
#define NORMAL 1
#define HOT 2

struct edge{
    ll from, to, cost;
    edge(ll from, ll to, ll cost) : from(from), to(to), cost(cost) {}
};

struct ndata{
    ll node, dist, state, time;
    ndata(ll node, ll dist, ll state, ll time) : node(node), dist(dist), state(state), time(time) {}
    bool operator<(const ndata& rhs) const{
        return dist < rhs.dist;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, x;
    cin >> n >> m >> x;
    vector<int> a(m), b(m), d(m), t(n);
    REP(i, n) cin >> t[i];

    vector<vector<edge> > G;
    G = vector<vector<edge> >(n);

    REP(i, m){
        cin >> a[i] >> b[i] >> d[i];
        a[i]--; b[i]--;
        G[a[i]].push_back(edge(a[i], b[i], d[i]));
        G[b[i]].push_back(edge(b[i], a[i], d[i]));
    }

    vector<ll> state(n);
    vector<vector<ll> > dist;
    dist = vector<vector<ll> >(3, vector<ll>(n, INF));
    dist[t[0]][0] = 0;
    priority_queue<ndata> que;
    if(t[0] == NORMAL){
        que.push(ndata(0, 0, NORMAL, 0));
    }else{
        que.push(ndata(0, 0, t[0], x));
    }

    while(!que.empty()){
        ndata p = que.top(); que.pop();
        ll d = p.dist, v = p.node, cstate = p.state, ptime = p.time;
        for(auto e : G[v]){
            int next_v = e.to, next_state = t[e.to];
            if(cstate == next_state || cstate == NORMAL){
                if(dist[next_state][next_v] <= d + e.cost) continue;
                dist[next_state][next_v] = d + e.cost;
                if(next_state == NORMAL){
                    que.push(ndata(next_v, dist[next_state][next_v], next_state, 0));
                }else{
                    que.push(ndata(next_v, dist[next_state][next_v], next_state, x));
                }
            }else if(next_state != NORMAL){
                if(dist[next_state][next_v] <= d + e.cost) continue;
                if(e.cost >= p.time){
                    dist[next_state][next_v] = d + e.cost;
                    que.push(ndata(next_v, dist[next_state][next_v], next_state, x));
                }else{
                    continue;
                }
            }else{
                if(e.cost >= p.time){
                    if(dist[next_state][next_v] <= d + e.cost) continue;                    
                    dist[next_state][next_v] = d + e.cost;
                    que.push(ndata(next_v, dist[next_state][next_v], next_state, 0));
                }else{
                    if(dist[cstate][next_v] <= d + e.cost) continue;                    
                    dist[cstate][next_v] = d + e.cost;
                    que.push(ndata(next_v, dist[next_state][next_v], cstate, p.time - e.cost));
                }
            }
        }
    }

    int ans = INF;
    REP(i, 3){
        if(dist[i][n - 1] == -1 * INF) continue;
        else{
            if(dist[i][n - 1] < ans) ans = dist[i][n - 1];
        }
    }

    REP(i, n){
        cout << "0:" << dist[0][i] << " 1:" << dist[1][i] << " 2:" << dist[2][i] << endl;
    }

    cout << ans << endl;

}