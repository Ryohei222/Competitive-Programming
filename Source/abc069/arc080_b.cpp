#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <cstring>
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

//int dx[4] = {0,1,0,-1}, dy[4] = {-1,0,1,0};
//int dx5[5] = {-1,0,0,0,1}, dy5[5] = {0,-1,0,1,0};
//int dx8[8] = {-1,0,1,1,1,0,-1,-1}, dy8[8] = {1,1,1,0,-1,-1,-1,0};
//int dx9[9] = {-1,0,1,1,1,0,-1,-1,0}, dy9[9] = {1,1,1,0,-1,-1,-1,0,0};

int main(){
    int h, w, n, x = 0;
    int a[10010];
    int c[110][110]; // = vector<vector<int>> vi(110, vector<int>(110)); たぶん
    cin >> h >> w >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    int index = 0;
    REP(i, h){
        if(i % 2 == 0){
            REP(j, w){
                if(a[index] == 0) index++;
                c[i][j] = index + 1;
                a[index]--;
            }
        }else{
            for(int j = w - 1; j >= 0; j--){
                if(a[index] == 0) index++;
                c[i][j] = index + 1;
                a[index]--;
            }
        }
    }
    REP(i, h){
        REP(j, w) cout << c[i][j] << " ";
        cout << endl;
    }   
    return 0;
}
// O(HW)
