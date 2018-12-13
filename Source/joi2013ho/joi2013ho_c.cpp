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

template<class T = i64>
const T INF = numeric_limits<T>::max();
template<class T = i64>
const T SINF = numeric_limits<T>::max() / 10;
static const i64 MOD = 1000000007;

//int dx[4] = {0,1,0,-1}, dy[4] = {-1,0,1,0};
//int dx[5] = {-1,0,0,0,1}, dy[5] = {0,-1,0,1,0};
//int dx[8] = {-1,0,1,1,1,0,-1,-1}, dy[8] = {1,1,1,0,-1,-1,-1,0};
//int dx[9] = {-1,0,1,1,1,0,-1,-1,0}, dy[9] = {1,1,1,0,-1,-1,-1,0,0};


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

struct edge {
	i64 to, cost, time;
	edge(i64 to, i64 cost, i64 time) : to(to), cost(cost), time(time) {}
	bool operator<(const edge& a) const{
		return cost < a.cost;
	}
	bool operator>(const edge& a) const{
		return cost > a.cost;
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	i64 m, n, k;
	cin >> m >> n >> k;

	vector<i64> x(k + 2), y(k + 2);
	vector<unordered_map<i64, vector<P>>> mp;
	unordered_map<i64, vector<P>> mpx, mpy;
	unordered_map<i64, i64> mpv;

	i64 s, g;
	s = g = -1;
	for(i64 i = 0; i < k; ++i){
		cin >> x[i] >> y[i];
		mpx[x[i]].push_back(P(x[i], y[i]));
		mpy[y[i]].push_back(P(x[i], y[i]));
		mpv[(x[i]<<32LL) + y[i]] = i;
		if(x[i] == 1 && y[i] == 1) s = i;
		if(x[i] == m && y[i] == n) g = i;
	}

	priority_queue<edge, vector<edge>, greater<edge>> que;
	auto dist = make_v<i64>(2, k + 2);
	fill_v(dist, SINF<i64>);
	
	if(s == -1){
		mpx[1].push_back(P(1, 1));
		mpy[1].push_back(P(1, 1));
		mpv[(1LL<<32LL) + 1] = k;
		s = k;
		k++;
	}else{
		dist[1][s] = 1;
		que.emplace(edge(0, s, 1));
	}
	dist[0][s] = 0;
	que.emplace(edge(-1, s, 0));

	if(g == -1){
		mpx[m].push_back(P(m, n));
		mpy[n].push_back(P(m, n));
		mpv[(m<<32LL) + n] = k;
		g = k;
		k++;
	}

	mp.push_back(mpx);
	mp.push_back(mpy);

	while(!que.empty()){
		edge e = que.top(); que.pop();
		vector<i64> p(2);
		p[0] = x[e.to]; p[1] = y[e.to];
		if(p[0] == m && p[1] == n) continue;
		for(i64 i = 0; i < mp[e.time][p[e.time]].size(); ++i){
			P v = mp[e.time][p[e.time]][i];
			i64 vn = mpv[(v.first << 32LL) + v.second];
			if(v.first == x[e.to] && v.second == y[e.to]) continue;
			if(e.cost + abs(x[vn] - x[e.to]) + abs(y[vn] - y[e.to]) + 1 < dist[(e.time + 1) % 2][vn]){
				dist[(e.time + 1) % 2][vn] = e.cost + abs(x[vn] - x[e.to]) + abs(y[vn] - y[e.to]) + 1;
				que.emplace(edge(vn, dist[(e.time + 1) % 2][vn], (e.time + 1) % 2));
			}
		}
	}
	i64 ans = min(dist[0][g], dist[1][g]);
	if(ans == SINF<i64>) cout << -1 << endl;
	else cout << ans << endl;
	/*
	for(i64 i = 0; i < k + 2; ++i){
		cout << i << ": " << dist[0][i] << " " << dist[1][i] << endl;
	}
	*/
}