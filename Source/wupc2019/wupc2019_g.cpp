#pragma region includes, macros
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
 
typedef int64_t i64;
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
	i64 n, m;
	cin >> n >> m;
	vector<i64> a(m);
	for(int i = 0; i < m; ++i) cin >> a[i];
	vector<vector<i64>> wa(n, (vector<i64>(n, 0)));
	vector<i64> cnt(n, 0);
	for(int i = 0; i < m; ++i){
		int k = a[i];
		for(int j = 0; j < n; ++j){
			if(j != k) wa[k][j] += cnt[j];
		}
		++cnt[k];
	}
	vector<i64> dp(1<<n, SINF<i64>);
	dp[0] = 0;
	for(int S = 1; S < 1<<n; ++S){
		for(int i = 0; i < n; ++i){
			if(S & (1<<i)){
				i64 cost = 0;
				for(int j = 0; j < n; ++j){
					if((S & (1<<j)) == 0) cost += wa[i][j];
				}
				dp[S] = min(dp[S], dp[S & ~(1<<i)] + cost);
			}
		}
	}
	cout << dp[(1<<n) - 1] << endl;
}

/*
dp[S] := 集合Sの定食まで提供した時の不満度の総和
dp[S] = min(dp[S\k] + cost[k] | k & S == 0)
wa[i][j] = 定食iの各要素より前にある定食jの数の総和
*/