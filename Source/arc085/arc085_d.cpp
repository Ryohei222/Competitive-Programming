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
	int n, q;
	cin >> n;
	vector<int> b(n);
	for(int i = 0; i < n; ++i) cin >> b[i];
	cin >> q;
	vector<vector<int>> op(n, vector<int>());
	for(int i = 0; i < q; ++i){
		int nl, nr;
		cin >> nl >> nr;
		--nl; --nr;
		op[nl].push_back(nr);
	}
	vector<int> dp(n + 1, SINF<int>);
	dp[0] = 0;
	vector<int> wa(n + 1, 0);
	for(int i = 0; i < n; ++i) wa[i + 1] = wa[i] + b[i];
	for(int i = 0; i < n; ++i){
		if(b[i] == 0) dp[i + 1] = min(dp[i], dp[i + 1]);
		else dp[i + 1] = min(dp[i] + 1, dp[i + 1]);
		for(int j = 0; j < op[i].size(); ++j){
			int r = op[i][j];
			int cost = r - i + 1 - (wa[r + 1] - wa[i]);
			dp[r + 1] = min(dp[r + 1], dp[i] + cost);
		}
	}
	cout << dp[n] << endl;
}