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

template< class T >
struct BinaryIndexedTree{
  vector< T > data;

  BinaryIndexedTree(int sz){
	data.assign(++sz, 0);
  }

  T sum(int k){
	T ret = 0;
	for(++k; k > 0; k -= k & -k) ret += data[k];
	return (ret);
  }

  void add(int k, T x){
	for(++k; k < data.size(); k += k & -k) data[k] += x;
  }
};

struct Triple{
	i64 a, b, id;
	Triple(i64 fi, i64 si, i64 ti) : a(fi), b(si), id(ti) {}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	i64 n;
	cin >> n;
	vector<i64> a(n), b(n);
	vector<Triple> as(n, Triple(0, 0, 0)), bs(n, Triple(0, 0, 0));
	for(i64 i = 0; i < n; ++i){
		cin >> a[i] >> b[i];
		as[i] = Triple(a[i], b[i], i);
		bs[i] = Triple(a[i], b[i], i);
	}
	auto af = [](Triple &l, Triple &r){
		if(l.a == r.a) return l.b < r.b;
		else return l.a < r.a;
	};
	sort(as.begin(), as.end(), af);
	auto bf = [](Triple &l, Triple &r){
		if(l.b == r.b) return l.a < r.a;
		else return l.b > r.b;
	};
	sort(bs.begin(), bs.end(), bf);
	unordered_map<i64, i64> mp;
	for(i64 i = 0; i < n; ++i){
		mp[as[i].id] = i;
	}
	BinaryIndexedTree<i64> BIT(n + 10);
	BinaryIndexedTree<i64> cnt(n + 10);
	i64 ans = 0;
	for(i64 i = 0; i < n; ++i){
		BIT.add(mp[bs[i].id], bs[i].a);
		cnt.add(mp[bs[i].id], 1);
		//cout << i << ": " << mp[bs[i].id] << endl;
		i64 left = -1, right = n;
		while(right - left > 1){
			i64 mid = (right + left) / 2;
			if(cnt.sum(mid) == 0 || BIT.sum(mid) * 1000 / cnt.sum(mid) <= bs[i].b * 1000) left = mid;
			else right = mid;
		}
		ans = max(ans, cnt.sum(left));
	}
	cout << ans << endl;
}