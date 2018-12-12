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
    int h, w, d;
    cin >> h >> w >> d;

    int a[310][310];
    int x[100010], y[100010];

    REP(i, h) REP(j, w){
        cin >> a[i][j];
        x[a[i][j]] = i;
        y[a[i][j]] = j;
    }

    int q;
    cin >> q;
    int l[100010], r[100010];
    
    REP(i, q){
        cin >> l[i] >> r[i];
    }

    vector<vector<int>> dist;
    dist = vector<vector<int>>(d + 1, vector<int>((h * w + d) / d, 0)); 

    FOR(i, 1, d + 1){
        dist[i][0] = 0;
        int num = i;
        FOR(j, 1, (h * w + d) / d){
            int tmp = num + d;
            dist[i][j] = dist[i][j - 1] + abs(x[tmp] - x[num]) + abs(y[tmp] - y[num]);
            num = tmp;
        }
    }

    REP(k, q){
        int tmp = l[k] % d;
        if(tmp == 0) tmp = d;
        if(l[k] - tmp == 0){
            cout << dist[tmp][(r[k] - tmp) / d] << endl;
        }else{
            cout << dist[tmp][(r[k] - tmp) / d] - dist[tmp][(l[k] - tmp) / d] << endl;
        }
    }
}
