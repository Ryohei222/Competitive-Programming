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

i64 dx[4] = {0,1,0,-1}, dy[4] = {-1,0,1,0};
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
	cin >> m >> n;

	i64 cnt = 1;
	vector<P> home(30);
	auto a = make_v<i64>(n, m);

	for(i64 i = 0; i < n; ++i){
		for(i64 j = 0; j < m; ++j){
			cin >> a[i][j];
			if(a[i][j] == 1){
				a[i][j] = cnt;
				home[cnt] = P(i, j);
				cnt++;
			}else if(a[i][j] == 2){
				a[i][j] = 0;
				home[0] = P(i, j);
			}else{
				a[i][j] = -1;
			}
		}
	}

	home[cnt] = home[0];
	cnt++;

	auto dp = make_v<i64>(1<<(cnt + 1), cnt);
	fill_v(dp, 0);
	dp[1][0] = 1;
	for(i64 i = 1; i < 1<<cnt; ++i){
		for(i64 j = 0; j < cnt; ++j){
			if(!(i & 1<<j)) continue;
			i64 x = home[j].first, y = home[j].second;
			for(i64 f = 0; f < 4; ++f){
				i64 nx = x + dx[f], ny = y + dy[f];
				while(0 <= nx && nx < n && 0 <= ny && ny < m){
					if(a[nx][ny] >= 1){
						if(i & 1<<a[nx][ny]) break;
						else dp[i | 1<<a[nx][ny]][a[nx][ny]] += dp[i][j];
					}else if(__builtin_popcountll(i) == cnt - 1 && a[nx][ny] == 0){
						dp[i | 1<<cnt][cnt] += dp[i][j];
					}
					nx += dx[f];
					ny += dy[f];
				}
			}
		}
	}

	cout << dp[1<<cnt][cnt] << endl;
}