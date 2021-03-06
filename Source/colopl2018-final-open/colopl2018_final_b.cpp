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
    string s;
    cin >> s;
    string ans = "a";
    REP(i, 100010) ans += 'a';
    int i = 0;
    int j = 0;
    stack<char> st;
    while(i != s.length()){
        if(s[i] == '*' || s[i] == '/' || s[i] == '+' || s[i] == '-'){
            st.push(s[i]);
        }else if(s[i] == ','){
            ans[j] = st.top();
            j++;
        }else if(s[i] == ')'){
            st.pop();
            ans[j] = s[i];
            j++;
        }else{
            ans[j] = s[i];
            j++;
        }
        i++;
    }
    cout << ans.substr(0, j) << endl;
}
