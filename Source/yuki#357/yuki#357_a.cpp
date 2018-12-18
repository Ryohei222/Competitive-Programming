#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	vector<int> item1(m), item2(m), score(m);
	for(int i = 0; i < m; ++i) cin >> item1[i] >> item2[i] >> score[i];

	vector<int> dp(1 << n, 0);
	for(int i = 0; i < (1 << n) - 1; ++i){ // 11....1110までループ
		for(int j = 0; j < n; ++j){
			if(i & (1 << j)) continue; // 品物jがすでに配置されている(集合iに含まれている)ならばスキップする
			int sum = 0; // 品物jを追加した時に増える得点
			for(int k = 0; k < m; ++k){
				if((i & (1 << item1[k])) && item2[k] == j){ // 品物item1[k]がすでに配置されていて、item2[k]が追加する品物(品物j)ならば得点を追加する
					sum += score[k];
				}
			}
			dp[i | (1 << j)] = max(dp[i | (1 << j)], dp[i] + sum);
		}
	}

	cout << dp[(1 << n) - 1] << endl;
}