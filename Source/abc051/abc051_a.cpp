#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
 
typedef long long ll;
 
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) for(int i = 0; i < (n); ++i)

int main(){
    string str;
    cin >> str;
    REP(i, str.length()){
        if(str[i] == ',') cout << " ";
        else cout << str[i];
    }
    cout << endl;
}

