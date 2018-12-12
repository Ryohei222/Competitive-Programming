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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	i64 n, H;
	cin >> n >> H;
	vector<i64> w(n - 1), v(n - 1);
	i64 vs = 0;
	for(i64 i = 0; i < n - 1; ++i){
		cin >> w[i] >> v[i];
		w[i] *= i + 1;
		vs += v[i];
	}
	auto dp = make_v<i64>(n + 1, vs + 1);
	fill_v(dp, SINF<i64>);
	dp[0][0] = 0;
	for(int i = 0; i < n - 1; ++i){
		for(int j = 0; j < vs + 1; ++j){
			if(j < v[i]) {
				dp[i + 1][j] = dp[i][j];
			}else{
				dp[i + 1][j] = min(dp[i][j], dp[i][j - v[i]] + w[i]);
			}
		}
	}
	i64 ans = SINF<i64>;
	for(i64 i = H; i < vs + 1; ++i){
		ans = min(ans, dp[n - 1][i]);
	}
	if(ans == SINF<i64>) cout << -1 << endl;
	else cout << ans << endl;
}