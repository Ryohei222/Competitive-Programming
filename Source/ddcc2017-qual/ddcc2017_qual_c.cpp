#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <unordered_set>
#include <bitset>
 
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

//int dx4[4] = {0,1,0,-1}, dy4[4] = {-1,0,1,0};
//int dx5[5] = {-1,0,0,0,1}, dy5[5] = {0,-1,0,1,0};
//int dx8[8] = {-1,0,1,1,1,0,-1,-1}, dy8[8] = {1,1,1,0,-1,-1,-1,0};
//int dx9[9] = {-1,0,1,1,1,0,-1,-1,0}, dy9[9] = {1,1,1,0,-1,-1,-1,0,0};

int main(){
    int n, c;
    cin >> n >> c;
    vector<int> l(n);
    REP(i, n){
        cin >> l[i];
    }
    int cnt = n - 1;
    int ans = 0;
    bool flag = false;
    SORT(l);
    REP(i, n){
        if(flag) break;
        while(1){
            if(cnt <= i){
                flag = true;
                break;
            }else if(l[i] + l[cnt] + 1 <= c){
                ans += 1;
                cnt--;
                break;
            }else{
                cnt--;
            }
        }
    }
    cout << n - ans << endl;
}

