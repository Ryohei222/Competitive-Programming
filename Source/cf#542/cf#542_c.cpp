#pragma region include, macro
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
	int n;
	cin >> n;
	int ax, ay, bx, by;
	cin >> ax >> ay >> bx >> by;
	--ax; --ay; --bx; --by;
	vector<string> v(n);
	for(int i = 0; i < n; ++i) cin >> v[i];
	// bfs bfs rekkyo rekkyo
	queue<P> que;
	que.push(P(ax, ay));
	vector<vector<bool>> same1 = vector<vector<bool>>(n, vector<bool>(n, false));
	same1[ax][ay] = true;
	while(!que.empty()){
		P t = que.front(); que.pop();
		int nx = t.first;
		int ny = t.second;
		for(int i = 0; i < 4; ++i){
			int x = nx + dx[i];
			int y = ny + dy[i];
			if(x < 0 || y < 0 || x >= n || y >= n) continue;
			if(v[x][y] == '0' && !same1[x][y]){
				same1[x][y] = true;
				que.push(P(x, y));
			}
		}
	}
	if(same1[bx][by]){
		cout << 0 << endl;
		return 0;
	}
	que.push(P(bx, by));
	vector<vector<bool>> same2 = vector<vector<bool>>(n, vector<bool>(n, false));
	same2[bx][by] = true;
	while(!que.empty()){
		P t = que.front();
		que.pop();
		int nx = t.first;
		int ny = t.second;
		for(int i = 0; i < 4; ++i){
			int x = nx + dx[i];
			int y = ny + dy[i];
			if(x < 0 || y < 0 || x >= n || y >= n) continue;
			if(v[x][y] == '0' && !same2[x][y]){
				same2[x][y] = true;
				que.push(P(x, y));
			}
		}
	}
	int ans = SINF<int>;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			for(int x = 0; x < n; ++x){
				for(int y = 0; y < n; ++y){
					if(same1[i][j] && same2[x][y]){
						ans = min((i - x) * (i - x) + (j - y) * (j - y), ans);
					}
				}
			}
		}
	}
	cout << ans << endl;
}