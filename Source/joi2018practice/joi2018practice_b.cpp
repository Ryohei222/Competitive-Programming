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
    int n;
    cin >> n;
    int ans = 0, cnt = 0;
    for(int i = 0; i < n; ++i){
        int a;
        cin >> a;
        if(a == 0){
            ans = max(ans, cnt);
            cnt = 0;
        }else{
            ++cnt;
        }
    }
    cout << max(cnt, ans) + 1 << endl;
}