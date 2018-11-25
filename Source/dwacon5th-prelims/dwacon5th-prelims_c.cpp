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

int main(){
    int n, q;
    cin >> n;
    string s;
    cin >> s;
    cin >> q;
    vector<int> wa(n);
    wa[0] = 0;
    FOR(i, 1, n){
        if(s[i] == 'M') wa[i] = wa[i - 1] + 1;
        else wa[i] = wa[i - 1];
    }
    vector<ll> cwa(n);
    vector<ll> ccount(n);
    REP(i, n){
        if(i < 2){
            cwa[i] = ccount[i] = 0;
        }
        if(s[i] == 'C'){
            cwa[i] = cwa[i - 1] + wa[i - 1];
            ccount[i] = ccount[i - 1] + 1;
        }else{
            cwa[i] = cwa[i - 1];
            ccount[i] = ccount[i - 1];
        }
    }
    REP(i, q){
        int k;
        cin >> k;
        ll ans = 0;
        REP(i, n - 2){
            if(s[i] == 'D'){
                ans += cwa[min(i + k - 1, n - 1)] - cwa[i] - wa[i] * (ccount[min(i + k - 1, n - 1)] - ccount[i]);
            }
        }
        cout << ans << endl;
    }
}