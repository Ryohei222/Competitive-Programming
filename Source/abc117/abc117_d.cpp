#pragma region include, macro
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
#pragma endregion

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	i64 n, k;
	cin >> n >> k;
	vector<i64> v(60, 0), a(n);
	for(i64 i = 0; i < n; ++i){
		cin >> a[i];
		for(i64 j = 0; j < 60; ++j){
			if(a[i] & (1LL<<j)) v[j]++;
		}
	}
	auto val = make_v<i64>(2, 60);
	for(i64 i = 0; i < 60; ++i){
		val[0][i] = (1LL<<i) * v[i];
		val[1][i] = (1LL<<i) * (n - v[i]);
	}
	for(i64 i = 0; i < 60; ++i){
		if((1LL<<i) > k) break;
		if(((1LL<<i) & k) == 0) continue;
		i64 s0, s1;
		s0 = s1 = 0;
		for(i64 j = i - 1; j >= 0; --j){
			s0 += max(val[0][j], val[1][j]);
			if(((1LL<<j) & k) == 0){
				s1 += val[0][j];
			}else{
				s1 += max(val[0][j], val[1][j]);
			}
		}
		s0 += val[0][i];
		s1 += val[1][i];
		if(s0 > s1){
			i64 nk = 0;
			for(i64 j = 0; j < 60; ++j){
				if(((1LL<<j) & k) == 0){
				}else{
					if(val[0][j] <= val[1][j]){
						nk += (1LL<<j);
					}
				}
			}
			k = nk;
		}
	}
	i64 ans = 0;
	for(i64 i = 0; i < n; ++i){
		ans += k ^ a[i];
	}
	cout << ans << endl;
}