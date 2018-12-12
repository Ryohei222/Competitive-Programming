#include <iostream>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;

int main(){
    int n, d, k;
    int L[10000], R[10000];
    int S[100], T[100];
    cin >> n >> d >> k;
    rep(i, d) cin >> L[i] >> R[i];
    rep(i, k) cin >> S[i] >> T[i];
    int j;
    rep(j, k){
        rep(i, d){
            if((L[i] <= S[j]) && (S[j] <= R[i])){
                if((L[i] <= T[j]) && (T[j] <= R[i])){
                    i++;
                    cout << i << endl;
                    break;
                }else if(T[j] < L[i]){
                    S[j] = L[i];
                }else{
                    S[j] = R[i];
                }
            }
        }
    }
}
