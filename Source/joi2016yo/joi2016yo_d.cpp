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

#define EAST 1
#define WEST 2

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    ll n, t, q;
    cin >> n >> t >> q;
    vector<ll> a(n), d(n), x(q);
    REP(i, n) cin >> a[i] >> d[i];
    REP(i, q) cin >> x[i];

    vector<ll> coltime(n), pos(n);
    ll cnt = 0;
    ll pre = -1 * INF;
    
    REP(i, n){
        if(cnt == 0 && d[i] == WEST){
            if(abs(pre - a[i]) < t){
                pos[i] = pre;
                coltime[i] = abs(pre - a[i]);
            }else{
                pos[i] = a[i] - t;
                coltime[i] = t;
            }
            continue;
        }
        if(d[i] == WEST){
            ll cpos = (a[i - 1] + a[i]) / 2;
            coltime[i] = abs(cpos - a[i]);
            pos[i] = a[i] - min(coltime[i], t);
            FOR(j, 1, cnt + 1){
                coltime[i - j] = abs(cpos - a[i - j]);
                pos[i - j] = a[i - j] + min(coltime[i - j], t);
            }
            cnt = 0;
            pre = cpos;
        }else{
            cnt++;
        }
    }
    REP(i, q){
        cout << pos[x[i] - 1] << endl;
    }
}