#include <stdio.h>
#include <string.h>

int main(){
    char str[5];
    int i;
    scanf("%s", str);
    int y = 0;
    int a = 0;
    int h = 0;
    int o = 0;
    for(i = 0; i < 5; i++){
        if('y' == str[i]){
            y++;
        }else if('a' == str[i]){
            a++;
        }else if('h' == str[i]){
            h++;
        }else if('o' == str[i]){
            o++;
        }else{
            printf("NO");
            return 0;
        }
    }
    if(y == 1 && a == 1 && h == 1 && o == 2){
        printf("YES");
    }else{
        printf("NO");
    }
    return 0;
}
