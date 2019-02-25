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
	i64 k;
	cin >> k;
	for(i64 i = 1998; i >= 2; --i){
		if(k % i != 0 || 1000000 * (2000 - i) * i < k) continue;
		vector<i64> ans;
		if(i % 2 == 1){
			ans.push_back(2);
			ans.push_back(-1);
			ans.push_back(-1);
			i64 t = i - 3;
			for(int j = 0; j < t; ++j){
				if(j % 2 == 0) ans.push_back(1);
				else ans.push_back(-1);
			}
		}else{
			for(int j = 0; j < i; ++j){
				if(j % 2 == 0) ans.push_back(1);
				else ans.push_back(-1);
			}
		}
		i64 cnt = i;
		i64 tmp = k / i;
		while(true){
			if(tmp == 0) break;
			if(tmp >= 1000000){
				ans.push_back(1000000);
				tmp -= 1000000;
			}else{
				ans.push_back(tmp);
				tmp = 0;
			}
			++cnt;
		}
		for(int j = 0; j < ans.size(); ++j) cout << ans[j] << " ";
		return 0;
	}
}