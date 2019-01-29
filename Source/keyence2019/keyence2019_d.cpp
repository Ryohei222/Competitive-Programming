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

const int MAX = 510000;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long long per(int n, int r){
    if (n < r) return 0;
    if (n < 0 || r < 0) return 1;
    return fac[n] * finv[n - r] % MOD;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	i64 n, m;
	cin >> n >> m;
	vector<i64> a(n), b(m);
	vector<P> sum;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	for(int i = 0; i < m; ++i){
		cin >> b[i];
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	if(n < m){
		swap(n, m);
		swap(a, b);
	}
	for(int i = 0; i < n; ++i){
		sum.push_back(P(a[i], i));
	}
	for(int i = 0; i < m; ++i){
		sum.push_back(P(b[i], i + 1000));
	}
	sort(sum.begin(), sum.end());
	for(int i = 1; i < n; ++i){
		if(a[i] == a[i - 1]){
			cout << 0 << endl;
			return 0;
		}
	}
	for(int i = 1; i < m; ++i){
		if(b[i] == b[i - 1]){
			cout << 0 << endl;
			return 0;
		}
	}
	int tmp = 0;
	unordered_map<i64, bool> mp;
	for(int i = 0; i < n; ++i){
		if(a[i] == b[tmp]){
			mp[a[i]] = true;
			tmp++;
		}else if(a[i] < b[i]){
			mp[b[i]] = false;
			i--;
			tmp++;
		}else{
			mp[a[i]] = false;
		}
	}
	for(int i = tmp; i < m; ++i){
		mp[b[tmp]] = false;
	}
	i64 ans = 1;
	i64 acnt = 0;
	i64 bcnt = 0;
	i64 cnt = 0;
	COMinit();
	for(int k = 0; k < n + m; ++k){
		cout << ans << endl;
		if(mp[sum[k].first]){
			if(sum[k].second >= 1000){
				ans = (ans * per(sum[k].first - cnt - 1, n - acnt - 1)) % MOD;
				bcnt++;
				cnt += n - acnt;
			}else{
				ans = (ans * per(sum[k].first - cnt - 1, m - bcnt - 1)) % MOD;
				acnt++;
				cnt += m - bcnt;
			}
		}else{
			if(sum[k].second >= 1000){
				ans = ((ans * per(sum[k].first - cnt - 1, n - acnt - 1)) % MOD) * (n - acnt) % MOD;
				bcnt++;
				cnt += n - acnt;
			}else{
				ans = ((ans * per(sum[k].first - cnt - 1, m - bcnt - 1)) % MOD) * (m - bcnt) % MOD;
				acnt++;
				cnt += m - bcnt;
			}
		}
	}
	cout << ans << endl;
}

/*
129 147     151 158     167 168 169     175 176     178 179 180 181 182
		150         159 167     169 173 175 176 177 178 179 180 181 182
		*/