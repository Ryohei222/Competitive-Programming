#include <iostream>
#define NUM 1000000007
 
using namespace std;
 
int main(){
    string a, b;
    int i,n;
    int flag = 1;
    long long answer = 3;
    cin >> n >> a >> b;
    for(i = 0; i < n; i++){
        if(a[i] == b[i]){
            if(flag * i){
                answer = answer * 2 % NUM;
            }
            flag = 1;
        }else{
            if(flag){
                answer = answer * 2 % NUM;
            }else{
                answer = answer * 3 % NUM;
            }
            flag = 0;
            i++;
        }
    }
    cout << answer << endl;
}

