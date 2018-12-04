/*
verified in https://onlinejudge.u-aizu.ac.jp/solutions/problem/DSL_1_A/review/3270863/kobaryo222/C++14
*/

#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

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

struct edge {
  i64 from, to, cost;
  edge(i64 to, i64 cost) : from(-1), to(to), cost(cost) {}
  edge(i64 src, i64 to, i64 cost) : from(src), to(to), cost(cost) {}
};

//-----end of template-----//

template<class T>
struct UnionFind{
    vector<T> par;
    void init(T n){
        par = vector<T>(n, 0);
        for(T i = 0; i < n; ++i) par[i] = i;
    }
    void unite(T x, T y){
        x = find(x);
        y = find(y);
        if(x != y) par[x] = y;
    }
    T find(T x){
        if(par[x] == x){
            return x;
        }else{
            return par[x] = find(par[x]);
        }
    }
    bool same(T x, T y){
        return find(x) == find(y);
    }
};

int main(){
    i64 n, q;
    cin >> n >> q;
    UnionFind<i64> uf;
    uf.init(n);
    for(i64 i = 0; i < q; ++i){
        i64 com, x, y;
        cin >> com >> x >> y;
        if(com == 0) uf.unite(x, y);
        else cout << uf.same(x, y) << endl;
    }
}