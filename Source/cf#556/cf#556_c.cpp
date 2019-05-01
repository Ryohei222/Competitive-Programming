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
 
typedef int64_t i64;
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

// 多重vectorを可変引数テンプレートで http://beet-aizu.hatenablog.com/entry/2018/04/08/145516
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
//

#pragma endregion

vector< bool > get_prime(int n){
  vector< bool > prime( n + 1, true);
  
  if(n >= 0) prime[0] = false;
  if(n >= 1) prime[1] = false;
  
  for(int i = 2; i * i <= n; i++){
    if(prime[i]){
      for(int j = i + i; j <= n; j += i) prime[j] = false;
    }
  }
  
  return(prime);
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	i64 n;
	cin >> n;
	vector<bool> is_prime = get_prime(2 * n + 10);
	vector<i64> a(n);
	int cnt1, cnt2;
	cnt1 = cnt2 = 0;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		if(a[i] == 1) ++cnt1;
		else ++cnt2;
	}
	vector<i64> b;
	i64 now = 0, cnt = 0;
	for(int i = 0; i < n; ++i){
		if(cnt1 == 0){
			b.push_back(2);
			now += 2;
		}else if(cnt2 == 0){
			b.push_back(1);
			now += 1;
		}else{
			if(is_prime[now + 2]){
				b.push_back(2);
				now += 2;
				--cnt2;
			}else if(is_prime[now + 1]){
				b.push_back(1);
				now += 1;
				--cnt1;
			}else{
				b.push_back(2);
				now += 2;
				--cnt2;
			}
		}
		if(is_prime[now]) cnt++;
	}
	for(int i = 0; i < n; ++i) cout << b[i] << ' ';
	cout << endl;
}