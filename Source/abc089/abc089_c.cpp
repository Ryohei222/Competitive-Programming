#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>
 
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
 
int dx4[4] = {0,1,0,-1}, dy4[4] = {-1,0,1,0};
//int dx5[5] = {-1,0,0,0,1}, dy5[5] = {0,-1,0,1,0};
//int dx8[8] = {-1,0,1,1,1,0,-1,-1}, dy8[8] = {1,1,1,0,-1,-1,-1,0};
//int dx9[9] = {-1,0,1,1,1,0,-1,-1,0}, dy9[9] = {1,1,1,0,-1,-1,-1,0,0};


int main(){
    ll ans = 0;
    int n;
    cin >> n;
    ll a[200];
    REP(i, 200) a[i] = 0;
    REP(i, n){
        string s;
        cin >> s;
        a[s[0]]++;
    }
    a[0] = a['M'];
    a[1] = a['A'];
    a[2] = a['R'];
    a[3] = a['C'];
    a[4] = a['H'];
    REP(i, 5){
        REP(j, 5){
            if(i >= j) continue;
            REP(k, 5){
                if(j >= k || i >= k) continue;
                ans += a[i] * a[j] * a[k];
            }
        }
    }
    cout << ans << endl;
}
