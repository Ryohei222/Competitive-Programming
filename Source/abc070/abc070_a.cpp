#include <iostream>

using namespace std;

int main(){
    int input;
    cin >> input;
    int reversed = input / 100 + (input % 10) * 100 + (input / 10) % 10 * 10;
    if(input == reversed){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}
