#include <iostream>
#include <string>
#include <stdio.h>
#include <ctype.h>

using namespace std;

signed main(){
    string f, s, t;
    cin >> f >> s >> t;
    cout << (char)toupper(f[0]) << (char)toupper(s[0]) << (char)toupper(t[0]) << endl;
}
