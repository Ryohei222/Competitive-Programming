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
static const int INF = 1000010000;
static const int MOD = 1000000007;
 
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define SORT(v) sort(v.begin(), v.end());

//int dx[4] = {0,1,0,-1}, dy[4] = {-1,0,1,0};
//int dx[5] = {-1,0,0,0,1}, dy[5] = {0,-1,0,1,0};
//int dx[8] = {-1,0,1,1,1,0,-1,-1}, dy[8] = {1,1,1,0,-1,-1,-1,0};
//int dx[9] = {-1,0,1,1,1,0,-1,-1,0}, dy[9] = {1,1,1,0,-1,-1,-1,0,0};

//-----end of template-----//

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    i64 n, k;
    cin >> n >> k;

    vector<i64> a(k);
    for(i64 i = 0; i < k; ++i){
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<i64> len(2 * n + 1, 0);
    i64 pre = -1, idx = 0, ans = 0;

    for(int i = 0; i < k; ++i){
        if(i == 0 && a[i] == 0){
            continue;
        }
        if
    }
}