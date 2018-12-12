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

	i64 n;
	cin >> n;
	vector<i64> a(n);
	for(i64 i = 0; i < n; ++i){
		cin >> a[i];
		if(i != 0 && a[i] == a[i - 1]){
			i--; n--;
		}
	}
	if(n == 1 && a[0] == 0){
		cout << 0 << endl;
		return 0;
	}
	vector<P> sorted;
	for(i64 i = 0; i < n; ++i){
		sorted.push_back(P(a[i], i + 2));
	}
	sort(sorted.begin(), sorted.end(), greater<P>());
	unordered_map<i64, vector<P>> mp;
	i64 cnt = 0;
	for(i64 i = 0; i < n; ++i){
		if(i == 0){
			mp[cnt].push_back(sorted[i]);
		}else{
			if(sorted[i].first == sorted[i - 1].first){
				mp[cnt].push_back(sorted[i]);
			}else{
				cnt++;
				mp[cnt].push_back(sorted[i]);
			}
		}
		if(i == n - 1 && mp[cnt][0].first != 0){
			cnt++;
			mp[cnt] = {P(0, 1), P(0, n + 2)};
		}
	}
	vector<bool> used(n + 10, false);
	i64 tmp, ans;
	tmp = ans = 0;
	for(i64 i = 0; i < cnt + 1; ++i){
		for(i64 j = 0; j < mp[i].size(); ++j){
			i64 num = mp[i][j].second;
			if(used[num - 1] && used[num + 1]) tmp--;
			else if(!used[num - 1] && !used[num + 1]) tmp++;
			used[num] = true;
		}
		ans = max(ans, tmp);
	}
	cout << ans << endl;
}