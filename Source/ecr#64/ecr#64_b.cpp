#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cctype>
#include <climits>
#include <bitset>
#include <bits/stdc++.h>
#define ld long double
#define ll long long int
#define ull unsigned long long int
#define rep(i, n) for (i = 0; i < n; i++)
#define fin(ans) cout << (ans) << endl
#define INF INT_MAX
#define vvi vector<vector<int>>
#define vvc vector<vector<char>>
#define vvs vector<vector<string>>
using namespace std;
const long long LLINF = 1LL << 60;
int cf, cb, n;
vector<int> ans;
int mincost = INF;
int dfs(int place, vector<pair<int, int>> v, vector<int> dir, int cost){
	int i;
	bool ch = true, go;
	if (place == n - 1){
		rep(i, n) if (v[i].second == 0) ch = false;
		if (ch && cost < mincost){
			ans.clear();
			rep(i, dir.size()) ans.push_back(dir[i]);
			mincost = cost;
			return 0;
		}
	}
	if (dir.size() >= 7)return 0;
	for (i = place + 1; i < v.size(); i++) v[i].first = 1 - v[i].first;
	rep(i, n){
		if (i == place) continue;
		if (v[i].first == 1){
			dir.push_back(i);
			go = false;
			if (v[i].second == 0){
				v[i].second = 1;
				go = true;
			}
			dfs(i, v, dir, (place > i) ? cost + cb : cost + cf);
			if (go) v[i].second = 0;
			dir.pop_back();
		}
	}
	return 0;
}

int main(void){
	int i;
	string a;
	cin >> n >> cf >> cb >> a;
	vector<int> dir;
	vector<pair<int, int>> v(n, make_pair(0, 0));
	rep(i, n) v[i] = (a[i] == 's') ? make_pair(1, 0) : make_pair(0, 0);
	dir.push_back(n - 1);
	rep(i, n - 1){
		if (v[i].first == 1){
			dir.push_back(i);
			v[i].second = 1;
			dfs(i, v, dir, cb);
			v[i].second = 0;
			dir.pop_back();
		}
	}
	rep(i, ans.size() - 1) cout << ans[i] + 1 << " ";
	cout << ans[ans.size() - 1] + 1 << endl;
	return 0;
}