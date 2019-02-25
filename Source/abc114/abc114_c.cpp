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

int t[3] = {3, 5, 7};
string n;

int rec(int k, bool flag, vector<bool> flags){
	if(k == n.length()){
		int cnt = 0;
		for(int i = 0; i < 3; ++i) if(flags[i]) cnt++;
		if(cnt == 3) return 1;
		else return 0;
	}
	int sum = 0;
	if(flag){
		for(int i = 0; i < 3; ++i){
			vector<bool> tmp = flags;
			tmp[i] = true;
			sum += rec(k + 1, true, tmp);
		}
	}else{
		for(int i = 0; i < 3; ++i){
			vector<bool> tmp = flags;
			tmp[i] = true;
			if((n[k] - '0') > t[i]){
				sum += rec(k + 1, true, tmp); 
			}else if((n[k] - '0') == t[i]){
				sum += rec(k + 1, false, tmp);
				break;
			}
		}
	}
	return sum;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	vector<bool> flag(3, false);
	int ans = 0;
	for(int i = 0; i < n.length() - 1; ++i){
		if(i == 0) ans += rec(i, false, flag);
		else ans += rec(i, true, flag);
	}
	cout << ans << endl;
}