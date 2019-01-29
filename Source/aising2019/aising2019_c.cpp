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

int dx[4] = {0,1,0,-1}, dy[4] = {-1,0,1,0};
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

int h, w;

#define BLACK '#'
#define WHITE '.'

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	i64 h, w;
	cin >> h >> w;
	vector<string> s(h);
	bool used[400][400];
	for(i64 i = 0; i < 400; ++i) for(i64 j = 0; j < 400; ++j) used[i][j] = false;
	i64 ans = 0;
	for(i64 i = 0; i < h; ++i) cin >> s[i];
	for(i64 i = 0; i < h; ++i) for(i64 j = 0; j < w; ++j){
		if(used[i][j]) continue;
		vector<i64> cnt(200, 0);
		queue<P> que;
		que.push(P(i, j));
		cnt[s[i][j]]++;
		used[i][j] = true;
		while(!que.empty()){
			P t = que.front(); que.pop();
			i64 x = t.first;
			i64 y = t.second;
			for(i64 k = 0; k < 4; ++k){
				i64 nx = x + dx[k];
				i64 ny = y + dy[k];
				if(nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
				if((s[nx][ny] != s[x][y]) && !used[nx][ny]){
					que.push(P(nx, ny));
					cnt[s[nx][ny]]++;
					used[nx][ny] = true;
				}
			}
		}
		ans += cnt[WHITE] * cnt[BLACK];
	}
	cout << ans << endl;
}