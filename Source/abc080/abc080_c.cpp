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
 
typedef long long i64;
typedef pair<i64, i64> P;
static const i64 INF = 1000010000;
static const i64 MOD = 1000000007;

//int dx[4] = {0,1,0,-1}, dy[4] = {-1,0,1,0};
//int dx[5] = {-1,0,0,0,1}, dy[5] = {0,-1,0,1,0};
//int dx[8] = {-1,0,1,1,1,0,-1,-1}, dy[8] = {1,1,1,0,-1,-1,-1,0};
//int dx[9] = {-1,0,1,1,1,0,-1,-1,0}, dy[9] = {1,1,1,0,-1,-1,-1,0,0};

//-----end of template-----//

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int> > f;
    vector<vector<int> > p;
    f = vector<vector<int> >(n, vector<int>(10, 0));
    p = vector<vector<int> >(n, vector<int>(10, 0));

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < 10; ++j){
            cin >> f[i][j];
        }
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < 10; ++j){
            cin >> p[i][j];
        }
    }

    int ans = -1 * INF;

    for(int i = 1; i < 1 << 10; ++i){
        bitset<10> bs(i);
        int tmp = 0;
        for(int idx = 0; idx < n; ++idx){
            int cnt = 0;
            for(int j = 0; j < 10; ++j){
                if(bs[j] && (f[idx][j] == 1)){
                    cnt++;
                }
            }
            tmp += p[idx][cnt];
        }
        ans = max(ans, tmp);
    }

    cout << ans << endl;
}