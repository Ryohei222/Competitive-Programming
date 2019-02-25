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

int dp[310][310];
string s;

int rec(int l, int r){
	if(dp[l][r] != -1) return dp[l][r];
	if(r - l + 1 <= 2) return 0;
	if(r - l + 1 == 3){
		if(s.substr(l, 3) == "iwi") return 3;
		else return 0;
	}
	int ret = 0;
	if((r - l + 1) % 3 == 0 && s[l] == 'i' && s[r] == 'i'){
		for(int i = l + 1; i < r; ++i){
			if(s[i] == 'w' && i - l - 1 == rec(l + 1, i - 1) && r - i - 1 == rec(i + 1, r - 1)) ret = r - l + 1;
		}
	}
	for(int i = l; i < r; ++i){
		ret = max(ret, rec(l, i) + rec(i + 1, r));
	}
	dp[l][r] = ret;
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	for(int i = 0; i < 310; ++i){
		for(int j = 0; j < 310; ++j){
			dp[i][j] = -1;
		}
	}
	cout << rec(0, s.length() - 1) / 3 << endl;
}