#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
 
using namespace std;
 
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define pb push_back

struct link{
    int num;
    struct link *before, *next;
};

struct link *nil;
const int MAX_N = 100010;

int main(){
    string a, b, c;
    cin >> a >> b >> c;
    if(a[a.length() - 1] == b[0] && b[b.length() - 1] == c[0]){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}
