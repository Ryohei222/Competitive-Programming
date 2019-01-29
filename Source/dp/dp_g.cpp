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

	vector<i64> x(m), y(m);
	vector<vector<edge> > G(n + 1);
	vector<bool> used(n + 1, false);

	for(int i = 0; i < m; ++i){
		cin >> x[i] >> y[i];
		G[x[i]].push_back(edge(x[i], y[i], 1));
		used[x[i]] = true;
	}

	for(int i = 0; i < n; ++i){
		if(used[i + 1]) G[0].push_back(edge(0, i + 1, 0));
	}

	vector<i64> dist(n + 1);
	fill_v(dist, -1 * SINF<i64>);
	dist[0] = 0;

	queue<i64> que;
	que.push(0);

	while(!que.empty()){
		i64 u = que.front(); que.pop();
		for(i64 i = 0; i < G[u].size(); ++i){
			i64 v = G[u][i].to;
			if(dist[u] + G[u][i].cost > dist[v]){
				dist[v] = dist[u] + G[u][i].cost;
				que.push(v);
			}
		}
	}

	i64 ans = -1;
	for(i64 i = 0; i < n; ++i) ans = max(ans, dist[i + 1]);
	cout << ans << endl;

}