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
    i64 from, to, cost;
    edge(i64 from, i64 to, i64 cost) : from(from), to(to), cost(cost) {}
};

struct ndata{
    i64 node, dist, state, pass;
    ndata(i64 node, i64 dist, i64 state, i64 time) : node(node), dist(dist), state(state), pass(pass) {}
    bool operator<(const ndata& rhs) const{
        return dist < rhs.dist;
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
    G = vector<vector<edge> >(n);

    for(i64 i = 0; i < m; ++i){
        cin >> a[i] >> b[i] >> d[i];
        a[i]--; b[i]--;
        G[a[i]].push_back(edge(a[i], b[i], d[i]));
        G[b[i]].push_back(edge(b[i], a[i], d[i]));
    }

    

}