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
 
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define SORT(v) sort(v.begin(), v.end());

//int dx[4] = {0,1,0,-1}, dy[4] = {-1,0,1,0};
//int dx[5] = {-1,0,0,0,1}, dy[5] = {0,-1,0,1,0};
//int dx[8] = {-1,0,1,1,1,0,-1,-1}, dy[8] = {1,1,1,0,-1,-1,-1,0};
//int dx[9] = {-1,0,1,1,1,0,-1,-1,0}, dy[9] = {1,1,1,0,-1,-1,-1,0,0};

//-----end of template-----//

bool is_prime[1000];

void sieve(int n) {
    int res = 0;
    fill(is_prime, is_prime + 1000, true);
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i <= n; ++i) {
        if(!is_prime[i]) continue;
        for(int j = 2 * i; j <= n; j += i) is_prime[j] = false;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;

    sieve(1000);
    vector<int> p(101, 0);
    p[1] = 1;

    for(int i = 1; i < n + 1; ++i){
        int tmp = i;
        for(int j = 2; j < 100; ++j){
            if(tmp <= 1) break;
            if(!is_prime[j]) continue;
            else if(tmp % j == 0){
                tmp /= j;
                p[j]++;
                j--;
            }
        }
    }

    i64 ans = 0;
    for(int i = 0; i < 100; i++){
        if(p[i] >= 74){
            ans += 1;
        }
        if(p[i] >= 24){
            for(int j = i + 1; j < 100; j++) if(p[j] >= 2){
                ans += 1;
            }
        }
        if(p[i] >= 14){
            for(int j = i + 1; j < 100; j++) if(p[j] >= 4){
                ans += 1;
            }
        }
        if(p[i] >= 4){
            for(int j = i + 1; j < 100; j++) if(p[j] >= 14){
                ans += 1;
            }
            for(int j = i + 1; j < 100; j++){
                if(p[j] >= 2) for(int k = j + 1; k < 100; k++) if(p[k] >= 4){
                    ans += 1;
                }
            }
            for(int j = i + 1; j < 100; j++){
                if(p[j] >= 4) for(int k = j + 1; k < 100; k++) if(p[k] >= 2){
                    ans += 1;
                }
            }
        }
        if(p[i] >= 2){
            for(int j = i + 1; j < 100; j++) if(p[j] >= 24){
                ans += 1;
            }
            for(int j = i + 1; j < 100; j++){
                if(p[j] >= 4) for(int k = j + 1; k < 100; k++) if(p[k] >= 4){
                    ans += 1;
                }
            }
        }
        cout << ans << endl;
    }
}

/*
a ^ 74
a ^ 2 * b ^ 24
a ^ 4 * b ^ 14
a ^ 2 * b ^ 4 * c ^ 4
*/