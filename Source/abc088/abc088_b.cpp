#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <cstring>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
static const int INF = 1000010000;
static const int MOD = 100000;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define SORT(v) sort(v.begin(), v.end());
#define pb push_back
#define mp make_pair
#define np next_permutation
#define pq priority_queue

int dx[4] = {0,1,0,-1}, dy[4] = {-1,0,1,0};
//int dx5[5] = {-1,0,0,0,1}, dy5[5] = {0,-1,0,1,0};
//int dx8[8] = {-1,0,1,1,1,0,-1,-1}, dy8[8] = {1,1,1,0,-1,-1,-1,0};
//int dx9[9] = {-1,0,1,1,1,0,-1,-1,0}, dy9[9] = {1,1,1,0,-1,-1,-1,0,0};

struct edge {
	int u, v;
	ll cost;
};

int main() {
	int n;
	vector<int> a;
	cin >> n;
	REP(i, n) {
		int tmp;
		cin >> tmp;
		a.pb(tmp);
	}
	sort(a.begin(), a.end(), greater<int>());
	int suma, sumb;
	suma = sumb = 0;
	REP(i, n) {
		if (i % 2 == 0) suma += a[i];
		else sumb += a[i];
	}
	cout << suma - sumb << endl;
}
