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

//-----end of template-----//

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	i64 l, n;
	cin >> l >> n;
	vector<i64> x(n);
	for(i64 i = 0; i < n; ++i) cin >> x[i];
	sort(x.begin(), x.end());
	i64 left, right, c;
	left = 1; right = n - 1; c = x[0];
	i64 cnt = 1;
	i64 sum = x[0];
	while(cnt != n){
		if(left == right){
			if(c > x[left]){
				sum += max(l - c + x[left], c - x[right]);
			}else{
				sum += max(x[left] - c, c + l - x[right]);
			}
		}else if(c > x[left]){
			if(l - c + x[left] >= c - x[right]){
				sum += l - c + x[left];
				c = x[left];
				left++;
			}else{
				sum += c - x[right];
				c = x[right];
				right--;
			}
		}else{
			if(x[left] - c >= c + l - x[right]){
				sum += x[left] - c;
				c = x[left];
				left++;
			}else{
				sum += c + l - x[right];
				c = x[right];
				right--;
			}
		}
		cnt++;
	}
	i64 ans = sum;
	left = 0; right = n - 2; c = x[n - 1];
	cnt = 1;
	sum = l - x[n - 1];
	while(cnt != n){
		if(left == right){
			if(c > x[left]){
				sum += max(l - c + x[left], c - x[right]);
			}else{
				sum += max(x[left] - c, c + l - x[right]);
			}
		}else if(c > x[left]){
			if(l - c + x[left] >= c - x[right]){
				sum += l - c + x[left];
				c = x[left];
				left++;
			}else{
				sum += c - x[right];
				c = x[right];
				right--;
			}
		}else{
			if(x[left] - c >= c + l - x[right]){
				sum += x[left] - c;
				c = x[left];
				left++;
			}else{
				sum += c + l - x[right];
				c = x[right];
				right--;
			}
		}
		cnt++;
	}
	cout << ans << endl;
	cout << sum << endl;
}