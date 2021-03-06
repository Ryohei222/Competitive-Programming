#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
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

//int dx4[4] = {0,1,0,-1}, dy4[4] = {-1,0,1,0};
//int dx5[5] = {-1,0,0,0,1}, dy5[5] = {0,-1,0,1,0};
//int dx8[8] = {-1,0,1,1,1,0,-1,-1}, dy8[8] = {1,1,1,0,-1,-1,-1,0};
//int dx9[9] = {-1,0,1,1,1,0,-1,-1,0}, dy9[9] = {1,1,1,0,-1,-1,-1,0,0};

int main(){
	int a, b, c;
	cin >> a >> b >> c;
	if(a <= b && c <= b){
		swap(a, b);
	}else if(a <= c && b <= c){
		swap(a, c);
	}
	if(b <= c){
		swap(b, c);
	}
	int ans = 200;
	int x = a - b;
	if((a - x - c) % 2 == 0){
		ans = min(ans, x + (a - x - c) / 2);
	}else{
		ans =  min(ans, x + (a - x - c + 1) / 2 + 1);
	}
	cout << ans << endl;
}
