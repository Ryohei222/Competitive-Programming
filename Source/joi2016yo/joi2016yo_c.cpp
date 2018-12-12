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

#define W 0
#define B 1
#define R 2

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    REP(i, n) cin >> s[i];
    vector<vector<int> > cost;
    cost = vector<vector<int> >(3, vector<int>(n, 0));
    REP(i, n){
        int w, b, r;
        w = b = r = 0;
        REP(j, m){
            if(s[i][j] == 'W') w++;
            if(s[i][j] == 'B') b++;
            if(s[i][j] == 'R') r++;
        }
        cost[W][i] = m - w;
        cost[B][i] = m - b;
        cost[R][i] = m - r;
    }
    REP(k, 3){
        FOR(i, 1, n) cost[k][i] += cost[k][i - 1];
    }
    int ans = 100000000;
    REP(i, n - 2){
        FOR(j, i + 1, n - 1){
            ans = min(ans, cost[W][i] + cost[B][j] - cost[B][i] + cost[R][n - 1] - cost[R][j]);
        }
    }
    cout << ans << endl;
}