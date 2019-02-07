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
	int n, m;
	cin >> n >> m;
	vector<vector<P>> data(n);
	vector<int> k(n);
	for(int i = 0; i < n; ++i){
		cin >> k[i];
		for(int j = 0; j < k[i]; ++j){
			int x, d;
			cin >> x >> d;
			data[i].push_back(P(x, d));
		}
	}
	int dp[160][80][10];
	for(int i = 0; i < 160; ++i){
		for(int j = 0; j < 80; ++j){
			for(int g = 0; g < 10; ++g){
				dp[i][j][g] = SINF<int>;
			}
		}
	}
	for(int i = 0; i < 10; ++i) dp[0][0][i] = 0;
	for(int i = 0; i < n - 1; ++i){
		for(int j = 0; j < k[i]; ++j){
			for(int v = 0; v < m; ++v){ // v = 今まで使った1つ鳥羽市
				for(int g = 0; g < k[i + 1]; ++g){
					int cost = (data[i][j].second + data[i + 1][g].second) * (abs(data[i][j].first - data[i + 1][g].first));
					dp[i + 1][v][g] = min(dp[i + 1][v][g], dp[i][v][j] + cost);
				}
				if(i == n - 2) continue;
				for(int g = 0; g < k[i + 2]; ++g){
					int cost = (data[i][j].second + data[i + 2][g].second) * (abs(data[i][j].first - data[i + 2][g].first));
					dp[i + 2][v + 1][g] = min(dp[i + 2][v + 1][g], dp[i][v][j] + cost);
				}
			}
		}
	}
	int res = SINF<int>;
	for(int i = 0; i < 80; ++i){
		for(int j = 0; j < k[n - 1]; ++j){
			res = min(res, dp[n - 1][i][j]);
		}
	}
	cout << res << endl;
}