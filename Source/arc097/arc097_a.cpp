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

int dx[4] = {0,1,0,-1}, dy[4] = {-1,0,1,0};
//int dx5[5] = {-1,0,0,0,1}, dy5[5] = {0,-1,0,1,0};
//int dx8[8] = {-1,0,1,1,1,0,-1,-1}, dy8[8] = {1,1,1,0,-1,-1,-1,0};
//int dx9[9] = {-1,0,1,1,1,0,-1,-1,0}, dy9[9] = {1,1,1,0,-1,-1,-1,0,0};

vector< bool > get_prime(int n){
  vector< bool > prime( n + 1, true);
  
  if(n >= 0) prime[0] = false;
  if(n >= 1) prime[1] = false;
  
  for(int i = 2; i * i <= n; i++){
    if(prime[i]){
      for(int j = i + i; j <= n; j += i) prime[j] = false;
    }
  }
  
  return(prime);
}

int main(){
    string s;
    cin >> s;
    int k;
    cin >> k;
    vector<string> slist;
    unordered_map<string, bool> mp;
    REP(i, s.length()){
        int flag = min(5, (int)s.length() - i);
        for(int j = 0; j < flag; j ++){
            string key = s.substr(i, j + 1);
            if(mp.find(key) == mp.end()){
                slist.push_back(key);
            }
            mp[key] = true;
        }
    }
    SORT(slist);
    cout << slist[k - 1] << endl;
}
