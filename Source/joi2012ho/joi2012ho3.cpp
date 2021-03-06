#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> P;
static const int INF = 1000010000;
static const int NIL = -1;
static const int MOD = 1000000007;
 
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define SORT(v) sort(v.begin(), v.end());
#define pb push_back
#define mp make_pair
#define np next_permutation
#define pq priority_queue
 
int gcd(int a, int b) { int c; while (b != 0) { c = a%b; a = b; b = c; }return a; }
int lcm(int a, int b) { int c = gcd(a, b); a /= c; return a*b; }
int nCr(int a, int b) { int i, r = 1; for (i = 1; i <= b; i++) { r *= (a + 1 - i); r /= i; }return r; }
int pow(int a, int b) { int i, r = 1; for (i = 1; i <= b; i++) { r *= a; }return r; }
long long llpow(long long a, long long b) { long long i, r = 1; for (i = 1; i <= b; i++) { r *= a; }return r; }
long long llgcd(long long a, long long b) { long long c; while (b != 0) { c = a%b; a = b; b = c; }return a; }
long long lllcm(long long a, long long b) { long long c = llgcd(a, b); a /= c; return a*b; }
long long llnCr(long long a, long long b) { long long i, r = 1; for (i = 1; i <= b; i++) { r *= (a + 1 - i); r /= i; }return r; }
 
//int dx4[4] = {0,1,0,-1}, dy4[4] = {-1,0,1,0};
//int dx5[5] = {-1,0,0,0,1}, dy5[5] = {0,-1,0,1,0};
//int dx8[8] = {-1,0,1,1,1,0,-1,-1}, dy8[8] = {1,1,1,0,-1,-1,-1,0};
//int dx9[9] = {-1,0,1,1,1,0,-1,-1,0}, dy9[9] = {1,1,1,0,-1,-1,-1,0,0};

struct edge{
    int to, cost;
};

const int MAX_N = 3010;

int main(){
    int n, t, s;
    cin >> n >> t >> s;
    int dp1[MAX_N][MAX_N], dp2[MAX_N][MAX_N], a[MAX_N], b[MAX_N];
    REP(i, MAX_N){
        dp1[0][i] = dp1[i][0] = dp2[0][i] = dp2[i][0] = 0;
    }
    FOR(i, 1, n + 1){
        cin >> a[i] >> b[i];
    }
    FOR(i, 1, n + 1) REP(j, s + 1){
        dp1[i][j] = dp1[i - 1][j];
        if(j - b[i] >= 0){
            dp1[i][j] = max(dp1[i][j], dp1[i - 1][j - b[i]] + a[i]);
        }
    }
    FOR(i, 1, n + 1) REP(j, t - s + 1){
        dp2[i][j] = dp2[i - 1][j];
        if(j - b[n + 1 - i] >= 0){
            dp2[i][j] = max(dp2[i][j], dp2[i - 1][j - b[n + 1 - i]] + a[n + 1 - i]);
        }
    }
    int ans = 0;
    REP(i, n + 1){
        ans = max(ans, dp1[i][s] + dp2[n - i][t - s]);
        //cout << dp1[i][s] << " " << dp2[n - i][t - s] << endl;
    }
    cout << ans << endl;
}
