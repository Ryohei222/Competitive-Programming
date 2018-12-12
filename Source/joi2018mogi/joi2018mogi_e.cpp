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

struct edge {
  i64 from, to, cost;
  edge(i64 to, i64 cost) : from(-1), to(to), cost(cost) {}
  edge(i64 src, i64 to, i64 cost) : from(src), to(to), cost(cost) {}
};

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

template< typename Monoid >
struct SegmentTree
{
  using F = function< Monoid(Monoid, Monoid) >;
 
  int sz;
  vector< Monoid > seg;
 
  const F f;
  const Monoid M1;
 
  SegmentTree(int n, const F f, const Monoid &M1) : f(f), M1(M1)
  {
    sz = 1;
    while(sz < n) sz <<= 1;
    seg.assign(2 * sz, M1);
  }
 
  void set(int k, const Monoid &x)
  {
    seg[k + sz] = x;
  }
 
  void build()
  {
    for(int k = sz - 1; k > 0; k--) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }
 
  void update(int k, const Monoid &x)
  {
    k += sz;
    seg[k] = x;
    while(k >>= 1) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }
 
  Monoid query(int a, int b)
  {
    Monoid L = M1, R = M1;
    for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if(a & 1) L = f(L, seg[a++]);
      if(b & 1) R = f(seg[--b], R);
    }
    return f(L, R);
  }
 
  Monoid operator[](const int &k) const
  {
    return seg[k + sz];
  }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

	i64 n, m;
	cin >> n >> m;
	vector<i64> a(n);

	SegmentTree<i64> segMax(n, [](i64 a, i64 b){return max(a, b);}, -1);
	SegmentTree<i64> segMin(n, [](i64 a, i64 b){return min(a, b);}, SINF<i64>);
	for(i64 i = 0; i < n; ++i){
		cin >> a[i];
		segMax.set(i, a[i]);
		segMin.set(i, a[i]);
	}
	segMax.build();
	segMin.build();
	auto dp = make_v<i64>(1010, 1010);
	fill_v(dp, -1 * SINF<i64>);
	for(i64 i = 0; i < 1010; ++i) dp[0][i] = 0;
	for(i64 i = 1; i < n + 1; ++i){
		for(i64 j = 1; j < m + 1; ++j){
			for(i64 k = 0; k < i + 1; ++k){
				dp[i][j] = max(dp[i][j], dp[i - k][j - 1] + segMax.query(i - k, i) - segMin.query(i - k, i));
			}
		}
	}
	cout << dp[n][m] << endl;
}