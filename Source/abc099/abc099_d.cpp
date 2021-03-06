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
static const ll MOD = 998244353;
 
#define FOR(i, a, b) for(ll i = (a); i < (b); ++i)
#define REP(i, n) for(ll i = 0; i < (n); ++i)
#define SORT(v) sort(v.begin(), v.end());
#define pb push_back
#define mp make_pair
#define np next_permutation
#define pq priority_queue

//int dx[4] = {0,1,0,-1}, dy[4] = {-1,0,1,0};
//int dx5[5] = {-1,0,0,0,1}, dy5[5] = {0,-1,0,1,0};
//int dx8[8] = {-1,0,1,1,1,0,-1,-1}, dy8[8] = {1,1,1,0,-1,-1,-1,0};
//int dx9[9] = {-1,0,1,1,1,0,-1,-1,0}, dy9[9] = {1,1,1,0,-1,-1,-1,0,0};


int main(){

    int n, c;
    cin >> n >> c;

    int d[50][50];
    REP(i, c) REP(j, c) cin >> d[i][j];

    int color[510][510];
    REP(i, n) REP(j, n) cin >> color[i + 1][j + 1];

    int s[3][40];

    REP(i, 3) REP(j, 40) s[i][j] = 0;

    FOR(i, 1, n + 1) FOR(j, 1, n + 1){
        s[(i + j) % 3][color[i][j] - 1]++;
    }

    int sans[3][40];

    REP(k, 3){
        REP(i, c){
            sans[k][i] = 0;
            REP(j, c){
                sans[k][i] += d[j][i] * s[k][j];
            }
        }
    }
   
    vector<P> v;
    REP(i, c){
        v.push_back(P(sans[2][i], i));
    }
    SORT(v);

    int ans = INF;

    REP(i, c) REP(j, c){
        if(i == j) continue;
        P tmp;
        if(v[0].second == i || v[0].second == j){
            if(v[1].second == i || v[1].second == j){
                tmp = v[2];
            }else{
                tmp = v[1];
            }
        }else{
            tmp = v[0];
        }

        if(ans > tmp.first + sans[0][i] + sans[1][j]){
            ans = tmp.first + sans[0][i] + sans[1][j];
        }
    }

    cout << ans << endl;

}

// 1 1 1 1 2 3 4
// 0 -1 -2 -3 -4 -4 -4
