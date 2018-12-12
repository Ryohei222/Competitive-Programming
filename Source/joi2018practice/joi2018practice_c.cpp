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
    int h, w;
    cin >> h >> w;
    vector<vector<int> > a;
    a = vector<vector<int> >(h, vector<int>(w, 0));
    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j){
            cin >> a[i][j];
        }
    }

    int ans = INF;

    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j){
            int tmp = 0;
            for(int x = 0; x < h; ++x){
                for(int y = 0; y < w; ++y){
                    tmp += 
                }
            }
        }
    }
}