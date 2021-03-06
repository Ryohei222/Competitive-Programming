#pragma region
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

i64 n;
i64 a[4010];
i64 dp[4010][4010];

i64 rec(int l, int r){ // [l, r)
	if(dp[l][r] != -1) return dp[l][r];
	if(r - l == 0) return 0;
	if(r - l == 1) return a[l];
	i64 res;
	if(a[l + 1] > a[r - 1]) res = a[l] + rec(l + 2, r);
	else res = a[l] + rec(l + 1, r - 1);
	if(a[l] > a[r - 2]) res = max(res, a[r - 1] + rec(l + 1, r - 1));
	else res = max(res, a[r - 1] + rec(l, r - 2));
	dp[l][r] = res;
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		a[i + n] = a[i];
	}
	for(int i = 0; i < 4010; ++i){
		for(int j = 0; j < 4010; ++j){
			dp[i][j] = -1;
		}
	}
	i64 ans = 0;
	for(int i = 0; i < n; ++i) ans = max(ans, rec(i, i + n));
	cout << ans << endl;
}
