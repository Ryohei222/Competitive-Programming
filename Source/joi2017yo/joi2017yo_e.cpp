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
 
typedef long long i64;
typedef pair<i64, i64> P;
static const i64 INF = 200000010000;
static const i64 MOD = 1000000007;

//int dx[4] = {0,1,0,-1}, dy[4] = {-1,0,1,0};
//int dx[5] = {-1,0,0,0,1}, dy[5] = {0,-1,0,1,0};
//int dx[8] = {-1,0,1,1,1,0,-1,-1}, dy[8] = {1,1,1,0,-1,-1,-1,0};
//int dx[9] = {-1,0,1,1,1,0,-1,-1,0}, dy[9] = {1,1,1,0,-1,-1,-1,0,0};

//-----end of template-----//

#define SAFE 0
#define DANGER 1
#define ZOMBIE 2

struct edge {
  i64 from, to, cost;
  edge(i64 to, i64 cost) : from(-1), to(to), cost(cost) {}
  edge(i64 src, i64 to, i64 cost) : from(src), to(to), cost(cost) {}
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    i64 n, m, k, s, p, q;
    cin >> n >> m >> k >> s >> p >> q;

    vector<vector<edge> > G(n + 1);
    vector<i64> a(m), b(m);

    for(int i = 0; i < k; ++i){
        i64 tmp;
        cin >> tmp;
        G[0].push_back(edge(0, tmp, 0));
        G[tmp].push_back(edge(tmp, 0, 0));
    }

    for(int i = 0; i < m; ++i){
        cin >> a[i] >> b[i];
        G[a[i]].push_back(edge(a[i], b[i], 1));
        G[b[i]].push_back(edge(b[i], a[i], 1));
    }

    vector<i64> dist(n + 1, INF);
    queue<P> que;
    que.push(P(0, 0));
    while(!que.empty()){
        P p = que.front(); que.pop();
        i64 v = p.first, d = p.second;
        for(auto e : G[v]){
            if(dist[e.to] > d + e.cost){
                dist[e.to] = d + e.cost;
                que.push(P(e.to, dist[e.to]));
            }
        }
    }

    vector<i64> state(n + 1, 0);
    for(int i = 0; i < n + 1; ++i){
        if(dist[i] == 0){
            state[i] = ZOMBIE;
        }else if(dist[i] <= s){
            state[i] = DANGER;
        }else{
            state[i] = SAFE;
        }
    }

    vector<vector<edge> > Gd(n + 1);

    for(int i = 0; i < m; ++i){
        i64 na = a[i], nb = b[i];
        if(state[na] == ZOMBIE || state[nb] == ZOMBIE) continue;
        if(nb == n){
            Gd[na].push_back(edge(na, nb, 0));
        }else if(state[nb] == SAFE){
            Gd[na].push_back(edge(na, nb, p));
        }else{
            Gd[na].push_back(edge(na, nb, q));
        }
        if(na == n){
            Gd[nb].push_back(edge(nb, na, 0));
        }else if(state[na] == SAFE){
            Gd[nb].push_back(edge(nb, na, p));
        }else{
            Gd[nb].push_back(edge(nb, na, q));
        }
    }

    vector<i64> cost(n + 1, INF);
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.emplace(P(0, 1));
    cost[1] = 0;
    while(!pq.empty()){
        P p = pq.top(); pq.pop();
        i64 d = p.first, v = p.second;
        if(cost[v] < d) continue;
        for(auto e : Gd[v]){
            if(cost[e.to] > d + e.cost){
                cost[e.to] = d + e.cost;
                pq.emplace(P(cost[e.to], e.to));
            }
        }
    }

    cout << cost[n] << endl;
}
