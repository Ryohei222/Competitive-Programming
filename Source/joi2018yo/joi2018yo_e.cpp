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

	i64 n, m;
	cin >> n >> m;
	vector<i64> a(n + 10), l(m), r(m);
	vector<P> sorted(m);
	for(i64 i = 0; i < n; ++i) cin >> a[i + 1];
	for(i64 i = 0; i < m; ++i){
		cin >> l[i] >> r[i];
		sorted[i] = P(l[i], r[i]);
	}
	sort(sorted.begin(), sorted.end());
	vector<i64> min_index(n + 10, -1);
	i64 cnt = 0;
	for(i64 i = 0; i < m; ++i){
		cnt = max(cnt, sorted[i].first);
		while(sorted[i].second >= cnt){
			min_index[cnt] = sorted[i].first;
			cnt++;
		}
	}
	vector<i64> dp(n + 10, 0);
	for(i64 i = 1; i < n + 1; ++i){
		if(min_index[i] == -1){
			dp[i] = dp[i - 1] + a[i];
		}else{
			dp[i] = max(dp[i - 1], dp[min_index[i] - 1] + a[i]);
		}
	}
	//for(i64 i = 1; i < n + 1; ++i) cout << i << ": " << min_index[i] << endl;
	cout << dp[n] << endl;
}