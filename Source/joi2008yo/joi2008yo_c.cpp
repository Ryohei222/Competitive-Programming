#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define SORT(v) sort(v.begin(), v.end());
#define pb(a) push_back(a)
using ll = long long;
using namespace std;

signed main(){
    int currentCard = 1, n, tmp, cntTaro, cntHanako, turn = 0; 
    bool taro[210];
    bool hanako[210];    
    cin >> n;
    cntTaro = n;
    cntHanako = n;
    FOR(i, 0, 2 * n + 1){
        taro[i] = false;
        hanako[i] = false;
    }
    REP(i, n){
        cin >> tmp;
        taro[tmp] = true;
    }
    FOR(i, 1, 2 * n + 1){
        if(taro[i] == false){
            hanako[i] = true;
        }
    }
    while(1){
        if(cntHanako == 0 || cntTaro == 0){
            break;
        }
        if(turn == 0){
            tmp = currentCard;
            while(1){
                if(tmp == 2 * n + 1){
                    currentCard = 1;
                    turn = 1;
                    break;
                }
                if(taro[tmp]){
                    cntTaro--;
                    currentCard = tmp + 1;
                    turn = 1;
                    taro[tmp] = false;
                    break;
                }else{
                    tmp++;
                }
            }
        }else{
            tmp = currentCard;
            while(1){
                if(tmp == 2 * n + 1){
                    currentCard = 1;
                    turn = 0;
                    break;
                }else if(hanako[tmp]){
                    cntHanako--;
                    currentCard = tmp + 1;
                    turn = 0;
                    hanako[tmp] = false;
                    break;
                }else{
                    tmp++;
                }
            }
        }
    }
    cout << cntHanako << endl << cntTaro << endl;
    return 0;
}
