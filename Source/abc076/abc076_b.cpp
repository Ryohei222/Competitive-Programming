#include <iostream>

using namespace std;

int main(){
    int n, k;
    int answer = 1;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        if(answer > k) answer += k;
        else answer = answer * 2;
    }
    cout << answer << endl;
    return 0;
}
