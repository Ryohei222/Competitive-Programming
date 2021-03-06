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
typedef pair<int, int> P;
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


// dijikstra
/* int V;
vector<edge> G[10];
int d[10];

void dijkstra(int s){
    priority_queue<P, vector<P>, greater<P>> que;
    fill(d, d + V + 1, INF);
    d[s] = 0;
    que.push(P(0, s));

    while(!que.empty()){
        P p = que.top(); que.pop();
        int v = p.second;
        if(d[v] < p.first) continue;
        REP(i, G[v].size()){
            edge e = G[v][i];
            if(d[e.to] > d[v] + e.cost){
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}
*/

int main(){
    int n, m;
    cin >> n >> m;
    bool ee[51][51];
    vector<P> bridge;
    REP(i, 51){
        REP(j, 51){
            ee[i][j] = false;
        }
    }
    REP(i, m){
        int a, b;
        cin >> a >> b;
        ee[a][b] = ee[b][a] = true;
        bridge.pb(P(a, b));
    }
    int ans = 0;
    REP(i, m){
        bool visit[51];
        REP(j, 51){
            visit[j] = false;
        }
        queue<int> que;
        que.push(1);
        visit[1] = true;
        auto t = bridge[i];
        int x = t.first, y = t.second;
        ee[x][y] = ee[y][x] = false;
        while(!que.empty()){
            int p = que.front(); que.pop();
            FOR(j, 1, n + 1){
                if(ee[p][j] && visit[j] == false){
                    visit[j] = true;
                    que.push(j);
                }
            }
        }
        bool flag = false;
        FOR(i, 1, n + 1){
            if(flag) break;
            if(visit[i] == false){
                ans++;
                flag = true;
            }
        }
        ee[x][y] = ee[y][x] = true;
    }
    cout << ans << endl;
}

