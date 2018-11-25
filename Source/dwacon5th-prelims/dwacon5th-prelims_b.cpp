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
#define SORT(v) sort(v.begin(),v.end());
#define pb push_back
#define mp make_pair
#define np next_permutation
#define pq priority_queue

//int dx4[4] = {0,1,0,-1}, dy4[4] = {-1,0,1,0};
//int dx5[5] = {-1,0,0,0,1}, dy5[5] = {0,-1,0,1,0};
//int dx8[8] = {-1,0,1,1,1,0,-1,-1}, dy8[8] = {1,1,1,0,-1,-1,-1,0};
//int dx9[9] = {-1,0,1,1,1,0,-1,-1,0}, dy9[9] = {1,1,1,0,-1,-1,-1,0,0};

//-----end of template-----//

ll RepeatSquaring(ll N, ll P){
    if(P==0) return 1;
    if(P%2==0){
        ll t = RepeatSquaring(N, P/2);
        return t*t;
    }
    return N * RepeatSquaring(N, P-1);
}

int main(){
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    vector<ll> s(n + 1);
    REP(i, n) cin >> a[i];
    s[0] = a[0];
    FOR(i, 1, n) s[i] += s[i - 1] + a[i];
    vector<ll> sorted(n * (n + 1 / 2));
    int c = 0;
    REP(i, n){
        FOR(j, i, n){
            if(i == 0) sorted[c] = s[j];
            else sorted[c] = s[j] - s[i];
            ++c;
        }
    }
    sort(sorted.begin(), sorted.end(), greater<ll>());
    ll up = 40;
    while(1){
        ll flag = RepeatSquaring(2, 40);
        int left = -1;
        int right = sorted.size();
        vector<ll> newsorted;
        while (right - left > 1) {
            int mid = left + (right - left) / 2;
            if (sorted[mid] >= flag) right = mid;
            else left = mid;
        }
        if(right + 1 >= k){

        }
    }
}
