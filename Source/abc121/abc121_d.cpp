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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	i64 a, b;
	cin >> a >> b;
	--a;
	bitset<63> bsa(a);
	bitset<63> bsb(b);
	vector<i64> cnta(63), cntb(63);
	for(i64 i = 0; i < 63; ++i){
		i64 x, y;
		x = y = 0;
		for(i64 j = 0; j < 63; ++j){
			if(bsa[j]){
				if(j < i) y += (1LL << j);
				if(j > i) x += (1LL << (j - i - 1));
			}
		}
		if(i != 0 && x != 0) cnta[i] += x * (1LL << (i - 1));
		if(i == 0) cnta[i] += (a + 1) / 2;
		if(bsa[i] && i != 0){
			cnta[i] += y + 1;
		}
	}
	for(i64 i = 0; i < 63; ++i){
		i64 x, y;
		x = y = 0;
		for(int j = 0; j < 63; ++j){
			if(bsb[j]){
				if(j < i) y += (1LL << j);
				if(j > i) x += (1LL << (j - i - 1));
			}
		}
		if(i != 0 && x != 0) cntb[i] += x * (1LL << (i - 1));
		if(i == 0) cntb[i] += (b + 1) / 2;
		if(bsb[i] && i != 0){
			cntb[i] += y + 1;
		}
	}
	i64 ans = 0;
	for(i64 i = 0; i < 63; ++i){
		if((cntb[i] - cnta[i]) % 2 == 1) ans += 1LL << i;
	}
	cout << ans << endl;
}
/*
x y
10100
01110
b[0] 100
b[1] 10000 - 1110 +
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	i64 a, b;
	cin >> a >> b;
	--a;
	bitset<63> bsa(a);
	bitset<63> bsb(b);
	vector<i64> cnta(63), cntb(63);
	for(i64 i = 0; i < 63; ++i){
		i64 x, y;
		x = y = 0;
		for(i64 j = 0; j < 63; ++j){
			if(bsa[j]){
				if(j < i) y += (1LL << j);
				if(j > i) x += (1LL << (j - i - 1));
			}
		}
		if(i != 0 && x != 0) cnta[i] += (x - 1) * (1LL << (i - 1));
		if(i == 0) cnta[i] += (a + 1) / 2;
		if(bsa[i]){
			cnta[i] += y;
		}
	}
	for(i64 i = 0; i < 63; ++i){
		i64 x, y;
		x = y = 0;
		for(int j = 0; j < 63; ++j){
			if(bsb[j]){
				if(j < i) y += (1LL << j);
				if(j > i) x += (1LL << (j - i - 1));
			}
		}
		if(i != 0 && x != 0) cntb[i] += (x - 1) * (1LL << (i - 1));
		if(i == 0) cntb[i] += (b + 1) / 2;
		if(bsb[i]){
			cntb[i] += y;
		}
	}
	i64 ans = 0;
	for(i64 i = 0; i < 63; ++i){
		if((cntb[i] - cnta[i]) % 2 == 1) ans += 1LL << i;
	}
	cout << ans << endl;
}
*/