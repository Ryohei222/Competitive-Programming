#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define rep(i, n) for(int i=0; i<(n);i++)

int main(){
    int a, b;
    cin >> a >> b;
    if((a + b)%3 && a%3 && b%3){
        cout << "Impossible" << endl;
    }else{
        cout << "Possible" << endl;
    }
    return 0;
}

