#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main(){
    int ascii = 97;
    string str;
    string search_str;
    char x[50];
    cin >> str;
    while(1){
        if(ascii == 123){
            cout << "None" << endl;
            break;
        }
        int n = sprintf(x,"%c", ascii);
        search_str = (string)x;
        if(str.find(search_str) == -1){
            cout << search_str << endl;
            break;
        }
        ascii++;
    }
    return 0;
}
