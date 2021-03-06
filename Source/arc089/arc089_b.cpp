#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <unordered_set>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> P;
static const int INF = 1000010000;
static const int NIL = -1;
static const int MOD = 1000000007;
 
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define SORT(v) sort(v.begin(), v.end());
#define RSORT(v) sort(v.begin(), v.end(), greater<int>);
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

struct dt{
    int t, x, y;
};

int main(){
    int n, k;
    cin >> n >> k;
    int mas[2][1002][1002]; // mas[0][x][y]は白
    int d[2][1002][1002];
    REP(s, 2) REP(i, 1002) REP(j, 1002){
        d[s][i][j] = mas[s][i][j] = 0;
    }
    REP(i, n){
        int x, y;
        char c;
        cin >> x >> y >> c;
        if(c == 'W'){
            if((x / k + y / k) % 2 == 0) mas[0][x % k + 1][y % k + 1]++;
            else mas[1][x % k + 1][y % k + 1]++;
        }else{
            if((x / k + y / k) % 2 == 0) mas[1][x % k + 1][y % k + 1]++;
            else mas[0][x % k + 1][y % k + 1]++;
        }
    }
    REP(s, 2){
        FOR(i, 1, k + 1){
            FOR(j, 1, k + 1){
                d[s][i][j] = mas[s][i][j] + d[s][i - 1][j] + d[s][i][j - 1] - d[s][i - 1][j - 1];
            }
        }
    }
    int ans = 0;
    FOR(i, 1, k + 1){
        FOR(j, 1, k + 1){
            ans = max(ans, d[0][k][k] - d[0][i][k] - d[0][k][j] + d[0][i][j] * 2 + d[1][i][k] + d[1][k][j] - d[1][i][j] * 2);
            ans = max(ans, d[1][k][k] - d[1][i][k] - d[1][k][j] + d[1][i][j] * 2 + d[0][i][k] + d[0][k][j] - d[0][i][j] * 2);            
        }
    }
    cout << ans << endl;
}

