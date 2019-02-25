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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(m), b(m);
	vector<vector<int> > st(n);
	for(int i = 0; i < m; ++i){
		cin >> a[i] >> b[i];
		--a[i]; --b[i];
		st[a[i]].push_back(b[i]);
	}
	vector<int> mi(n), cnt(n);
	for(int i = 0; i < n; ++i){
		cnt[i] = st[i].size();
		if(cnt[i] == 0) continue;
		int x = n;
		for(int j = 0; j < cnt[i]; ++j){
			if(st[i][j] > i) x = min(x, st[i][j] - i);
			else x = min(x, st[i][j] + n - i);
		}
		mi[i] = x;
	}	
	for(int i = 0; i < n; ++i){
		i64 ans = 0;
		i64 j = i, c = 0;
		while(c != n){
			ans = max(ans, c + n * (cnt[j] - 1) + mi[j]);
			j = (j + 1) % n;
			++c;
		}
		cout << ans << " ";
	}
}