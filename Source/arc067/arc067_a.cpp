#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <unordered_set>
 
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

//--- N < 1000 →　エラトステネスで素数列挙　素因数分解　約数定理

bool isprime[1001];

void hurui(){
    REP(i, 1000) isprime[i] = true;
    isprime[1] = false;
    FOR(i, 2, 1000) if(isprime[i]) for(ll j = 2 * i; j <= 1000; j += i) isprime[j] = false;
}

ll soinsu[1001];

void bunkai(ll x){
    while(x != 1){
        FOR(i, 2, 1000){
            if(x % i == 0 && isprime[i]){
                x /= i;
                soinsu[i]++;
                break;
            }
        }
    }
}

int main(){
    hurui();
    ll n;
    cin >> n;
    REP(i, 1001){
        soinsu[i] = 0;
    }
    FOR(i, 1, n + 1){
        bunkai(i);
    }
    ll ans = 1;
    REP(i, 1001){
        ans = (ans * (soinsu[i] + 1)) % MOD;
    }
    cout << ans << endl;
}
