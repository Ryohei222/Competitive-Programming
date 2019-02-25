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

i64 p[101], q[101], r[101], b[101];

i64 gcd(i64 a, i64 b){
	if(a < b) return gcd(b, a);
	i64 r;
	while(r = a % b){
		a = b;
		b = r;
	}
	return b;
}

i64 rec(i64 s){
	if(r[s] == 0 && b[s] == 0){
		return p[s] + q[s];
	}else if(r[s] == 0){
		i64 x = rec(b[s]);
		i64 r = x * p[s] * q[s] / gcd(p[s] * x, q[s]);
		return r / p[s] + r / q[s];
	}else if(b[s] == 0){
		i64 x = rec(r[s]);
		i64 r = x * p[s] * q[s] / gcd(p[s], q[s] * x);
		return r / p[s] + r / q[s];
	}else{
		i64 x = rec(b[s]);
		i64 y = rec(r[s]);
		i64 r = x * y * p[s] * q[s] / gcd(x * p[s], y * q[s]);
		return r / p[s] + r / q[s];
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	i64 n;
	cin >> n;
	vector<i64> cnt(n + 1, 0);
	for(i64 i = 1; i <= n; ++i){
		cin >> p[i] >> q[i] >> r[i] >> b[i];
		i64 g = gcd(p[i], q[i]);
		p[i] /= g;
		q[i] /= g;
		cnt[r[i]]++;
		cnt[b[i]]++;
	}
	i64 root;
	for(i64 i = 1; i <= n; ++i){
		if(cnt[i] == 0) root = i;
	}
	cout << rec(root) << endl;
}