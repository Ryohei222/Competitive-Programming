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

template<class T>
const T INF = numeric_limits<T>::max();
template<class T>
const T SINF = numeric_limits<T>::max() / 10;
static const i64 MOD = 1000000007;

//int dx[4] = {0,1,0,-1}, dy[4] = {-1,0,1,0};
//int dx[5] = {-1,0,0,0,1}, dy[5] = {0,-1,0,1,0};
//int dx[8] = {-1,0,1,1,1,0,-1,-1}, dy[8] = {1,1,1,0,-1,-1,-1,0};
//int dx[9] = {-1,0,1,1,1,0,-1,-1,0}, dy[9] = {1,1,1,0,-1,-1,-1,0,0};

template<typename T>
vector<T> make_v(size_t a){return vector<T>(a);}

template<typename T,typename... Ts>
auto make_v(size_t a,Ts... ts){
    return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));
}

template<typename T,typename V>
typename enable_if<is_class<T>::value==0>::type
fill_v(T &t,const V &v){t=v;}

template<typename T,typename V>
typename enable_if<is_class<T>::value!=0>::type
fill_v(T &t,const V &v){
    for(auto &e:t) fill_v(e,v);
}

//-----end of template-----//

#define COLD 0
#define NORMAL 1
#define HOT 2

struct edge{
    i64 to, cost, state, elasped;
    edge(i64 to, i64 cost) : to(to), cost(cost) {}
    edge(i64 to, i64 cost, i64 state, i64 elasped) : to(to), cost(cost), state(state), elasped(elasped) {}
    bool operator<(const edge& rhs) const {
        return cost < rhs.cost;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    i64 n, m, x;
    cin >> n >> m >> x;
    vector<i64> a(m), b(m), d(m), t(n);
    for(i64 i = 0; i < n; ++i) cin >> t[i];

    vector<vector<edge> > G;
    vector<vector<edge> > 
    G = vector<vector<edge> >(n);

    for(i64 i = 0; i < m; ++i){
        cin >> a[i] >> b[i] >> d[i];
        a[i]--; b[i]--;
        G[a[i]].push_back(edge(b[i], d[i]));
        G[b[i]].push_back(edge(a[i], d[i]));
    }

    for(i64 i = 0; i < n; ++i){
        cin >> t[i];
    }

    auto dist = make_v<i64>(3, n);
    auto elasped_time = make_v<i64>(3, n);
    fill_v(dist, SINF<i64>);
    fill_v(elasped_time, -1 * SINF<i64>);

    priority_queue<edge, vector<edge> > que;
    que.push(edge(0, 0, COLD, 0));

    while(!que.empty()){
        edge p = que.top(); que.pop();
        if(dist[p.state][p.to] <= p.cost && elasped_time[p.state][p.to] >= p.elasped) continue;
        dist[p.state][p.to] = min(dist[p.state][p.to], p.cost);
        elasped_time[p.state][p.to] = max(elasped_time[p.state][p.to], p.elasped);
        for(i64 i = 0; i < G[p.to].size(); ++i){
            edge e = G[p.to][i];
            if(e.to == ) // なにもわからない
            if((t[p.to] == HOT && t[e.to] == COLD) || (t[p.to] == COLD && t[e.to] == HOT)){
                if(p.elasped + e.cost < x) continue;
                que.push(edge(e.to, p.cost + e.cost, t[e.to], 0));
            }else if(t[e.to] == NORMAL){
                que.push(edge(e.to, p.cost + e.cost, p.state, p.elasped + e.cost));
            }else{
                que.push(edge(e.to, p.cost + e.cost, t[e.to], 0));
            }
        }
    }

    cout << min({dist[COLD][n - 1], dist[NORMAL][n - 1], dist[HOT][n - 1]}) << endl;
}

// どういうときにpushすればいいのか？
// 冷静に考えると各頂点について
// HOT COLD - distが小さいか elaspedが大きいかでpush
// (state == HOT || state == COLD) && (dist[node] > dist + cost || elasped_time < elasped || (dist[node] == dist + cost && elasped_time < elasped))) 的な