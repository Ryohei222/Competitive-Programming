#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> P;
static const int INF = 1000010000;
static const int MOD = 1000000007;
 
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define SORT(v) sort(v.begin(), v.end());
#define pb push_back
#define mp make_pair
#define np next_permutation
#define pq priority_queue

//int dx4[4] = {0,1,0,-1}, dy4[4] = {-1,0,1,0};
//int dx5[5] = {-1,0,0,0,1}, dy5[5] = {0,-1,0,1,0};
//int dx8[8] = {-1,0,1,1,1,0,-1,-1}, dy8[8] = {1,1,1,0,-1,-1,-1,0};
//int dx9[9] = {-1,0,1,1,1,0,-1,-1,0}, dy9[9] = {1,1,1,0,-1,-1,-1,0,0};

int main(){
	int n, k;
	cin >> n >> k;
	vector<ll> a;
	REP(i, n){
		ll tmp;
		cin >> tmp;
		a.pb(tmp);
	}
	SORT(a);
	int head = -1, tail = n;
	while(tail - head > 1){
		bool dp[5010][5010];
		REP(i, 5010) REP(j, 5010) dp[i][j] = false;
		int mid = (head + tail) / 2;
		REP(i, n){
			REP(j, k){
				if(i == 0){
					if(a[0] < k && mid != 0) dp[1][a[0]] = true;
					dp[1][0] = true;
					break;
				}
				if(i == mid) dp[i + 1][j] |= dp[i][j];
				else{
					if(j + a[i] < k) dp[i + 1][j + a[i]] = dp[i][j];
					dp[i + 1][j] |= dp[i][j];
				}
			}
		}
		bool flag = false;
		if(a[mid] >= k){
			tail = mid;
		}else{
			FOR(i, k - a[mid], k){
				flag = dp[n][i] || flag;
			}
			if(flag){
				tail = mid;
			}else{
				head = mid;
			}
		}
	}
	cout << (head + tail + 1) / 2 << endl;
	/*
	n ^ 2 * k = 10 ^ 2 * (10^3) * 3 = 10^11
	600点解法を考える
	・ai >= kが成り立つときは自明に必要
	・ai < kについて以下の条件
	・とりあえずaiを含むいい集合Siがあるとして
		Si - ai < k ⇒ aiは必要
		Si>=kを満たす最小のSiを求めればいいのでは
			→?これなんだっけ→蟻本をみる
			ん　これ小さい方から足しておくだけでは にぶたんでN + NlogN
			N * N これ嘘じゃん
			ai以外のaで k - ai <= S < k を作れるか
		N * 
	*/
 /* 解説を見ます*/
}

