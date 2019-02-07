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

#pragma endregion

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	i64 r;
	cin >> r;
	for(i64 k = 0; k < 2; ++k){
		i64 w, h, x, y;
		cin >> w >> h >> x >> y;
		i64 level[500][500];
		vector<i64> ulv;
		for(i64 i = 0; i < h; ++i){
			for(i64 j = 0; j < w; ++j){
				cin >> level[i][j];
				ulv.push_back(level[i][j]);
			}
		}
		sort(ulv.begin(), ulv.end());
  		ulv.erase(unique(ulv.begin(), ulv.end()), ulv.end());
		unordered_map<i64, i64> mp;
		for(i64 i = 0; i < ulv.size(); ++i) mp[ulv[i]] = i;
		vector<vector<P>> pos(ulv.size());
		for(i64 i = 0; i < h; ++i){
			for(i64 j = 0; j < w; ++j){
				pos[mp[level[i][j]]].push_back(P(i, j));
			}
		}
		vector<vector<bool>> used(500, vector<bool>(500, false));
		for(i64 i = 0; i < ulv.size(); ++i){
			for(i64 j = 0; j < pos[i].size(); ++j){
				P p = pos[i][j];
				i64 cnt = 0;
				i64 nx = p.first, ny = p.second;
				if(used[nx][ny]) continue;
				queue<P> que;
				for(int g = 0; g < 4; ++g){
					int tx = nx + dx[g];
					int ty = ny + dy[g];
					if(used[tx][ty] && level[tx][ty] < level[nx][ny]){
						que.push(P(nx, ny));
					}
				}
				while(!que.empty()){
					p = que.front();
					nx = p.first; ny = p.second;
					if(used[nx][ny]) continue;
					used[nx][ny] = true;
					cnt++;
					for(int g = 0; g < 4; ++g){
						int tx = nx + dx[g];
						int ty = ny + dy[g];
						if(used[tx][ty]) continue;
						if(level[tx][ty] <= ulv[i]){
							que.push(P(tx, ty));
						}
					}
				}
			}
		}
	}
}