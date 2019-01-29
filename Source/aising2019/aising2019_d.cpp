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

int dsolve(vector<string> s){
	int ans = 0;
	for(int i = 0; i < h; ++i){
		for(int j = 0; j < w; ++j){
			queue<P> que;
			que.push(P(i, j));
			auto used = make_v<bool>(h, w);
			used[i][j] = true;
			int sum  = 0;
			while(!que.empty()){
				P tmp = que.front(); que.pop();
				int x = tmp.first, y = tmp.second;
				for(int k = 0; k < 4; ++k){
					int nx = x + dx[k];
					int ny = y + dy[k];
					if(0 > nx || 0 > ny || h <= nx || w <= ny) continue;
					if(!used[nx][ny] && (s[x][y] != s[nx][ny])){
						que.push(P(nx, ny));
						used[nx][ny] = true;
						if(s[i][j] != s[nx][ny]) sum++;
					}
				}
			}
			ans += sum;
		}
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int h, w;
	cin >> h >> w;
	vector<string> s(h);
	int ans = 0;
	for(int i = 0; i < h; ++i) cin >> s[i];
	for(int i = 0; i < h; ++i){
		for(int j = 0; j < w; ++j){
			queue<P> que;
			que.push(P(i, j));
			auto used = make_v<bool>(h, w);
			used[i][j] = true;
			int sum  = 0;
			while(!que.empty()){
				P tmp = que.front(); que.pop();
				int x = tmp.first, y = tmp.second;
				for(int k = 0; k < 4; ++k){
					int nx = x + dx[k];
					int ny = y + dy[k];
					if(0 > nx || 0 > ny || h <= nx || w <= ny) continue;
					if(!used[nx][ny] && (s[x][y] != s[nx][ny])){
						que.push(P(nx, ny));
						used[nx][ny] = true;
						if(s[i][j] != s[nx][ny]) sum++;
					}
				}
			}
			ans += sum;
		}
	}
	cout << ans / 2 << endl;
}
