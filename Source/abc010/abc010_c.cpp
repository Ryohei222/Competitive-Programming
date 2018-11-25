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

//-----end of template-----//

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> f(n);
    vector<int> c(m, 0);
    vector<vector<int>> l;
    l = vector<vector<int>>(m, vector<int>(0));
    REP(i, n){
        cin >> f[i];
        l[f[i]].push_back(i);
    }
    vector<int> dp(n, 0);
    REP(i, n){
        if(i == 0){
            dp[i] = 1;
            c[f[i]]++;
        }else if(c[f[i]] == 0){
            dp[i] = dp[i - 1] * 2;
        }else{
            dp[i] = dp[l[f[i]][c[f[i]]-1]] + (dp[i - 1] - dp[l[f[i]][c[f[i]]-1]]) * 2;
        }
    }
    cout << dp[n - 1] << endl;
}