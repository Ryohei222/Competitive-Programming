#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_set>
#include <bitset>
#include <cmath>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
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

// dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - w[i]] + v[i])

int main(){
    int n; cin >> n;
    string str; cin >> str;
    ll wa[3][100010];
    REP(i, 3) fill(wa[i], wa[i] + 100010, 0);
    REP(i, n){
        char c = str[i];
        if(c == 'J') wa[0][i] = 1;
        if(c == 'O') wa[1][i] = 1;
        if(c == 'I') wa[2][i] = 1;
        if(i != 0){
            REP(j, 3){
                wa[j][i] += wa[j][i - 1];
                //cout << wa[j][i] << " ";
            }
            //cout << endl;
        }
    }
    ll ans = 0, tj = 0, to = 0, ti = 0, titmp = 0;
    REP(i, n){
        if(str[i] == 'O'){
            ti += wa[2][n - 1] - wa[2][i];
            tj += wa[0][i];
        }
        if(i != 0){
            if(to < wa[0][i - 1] * (wa[2][n - 1] - wa[2][i - 1])){
                titmp = i;
                to = wa[0][i - 1] * (wa[2][n - 1] - wa[2][i - 1]); 
            }
        }
    }
    ans = max(tj, max(ti, to));
    if(ans == to){
        str = str.substr(0, titmp) + 'O' + str.substr(titmp, n - titmp);
    }else if(ans == ti){
        str = 'J' + str;
    }else{
        str = str + 'I'; 
    }
    n++;
    REP(i, n){
        char c = str[i];
        wa[0][i] = wa[1][i] = wa[2][i] = 0;
        if(c == 'J') wa[0][i] = 1;
        if(c == 'O') wa[1][i] = 1;
        if(c == 'I') wa[2][i] = 1;
        if(i != 0) REP(j, 3) wa[j][i] += wa[j][i - 1];
    }
    ans = 0;
    FOR(i, 1, n){
        if(str[i] == 'O'){
            ans += wa[0][i - 1] * (wa[2][n - 1] - wa[2][i - 1]);
        }
    }
    //cout << str << endl;
    cout << ans << endl;
}

