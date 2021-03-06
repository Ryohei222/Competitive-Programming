#include <iostream>
#include <vector>
#include <algorithm>
#define ll unsigned long long int

using namespace std;

ll gcd(ll a, ll b){
    if(b == 0) return a;
    else return gcd(b, a % b);
}

ll lcm(ll a, ll b){
    return(a / gcd(a, b) * b);
}

int main(){
    int n;
    ll answer, temp;
    cin >> n;
    for(int i = 0; i < n; i++){
        if(i == 0){
            cin >> answer;
        }else{
            cin >> temp;
            answer = lcm(answer, temp);
        }
    }
    cout << answer << endl;
    return 0;
}
