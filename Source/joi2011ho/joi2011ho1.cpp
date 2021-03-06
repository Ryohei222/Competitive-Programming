#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define SORT(v) sort(v.begin(), v.end());
#define pb(a) push_back(a)
using ll = long long;
using namespace std;

int main(){
    int dpj[1010][1010], dpo[1010][1010], dpi[1010][1010];
    memset(dpj, sizeof(dpj), 0);
    memset(dpo, sizeof(dpo), 0);
    memset(dpi, sizeof(dpi), 0);
    int m, n , k;
    char tmp;
    cin >> m >> n >> k;
    FOR(i, 1, m + 1){
        FOR(j, 1, n + 1){
            cin >> tmp;
            if(tmp == 'J'){
                dpj[i][j]++;
            }else if(tmp == 'O'){
                dpo[i][j]++;
            }else{
                dpi[i][j]++;
            }
            dpj[i][j] += dpj[i][j - 1] + dpj[i - 1][j] - dpj[i - 1][j - 1];
            dpo[i][j] += dpo[i][j - 1] + dpo[i - 1][j] - dpo[i - 1][j - 1]; 
            dpi[i][j] += dpi[i][j - 1] + dpi[i - 1][j] - dpi[i - 1][j - 1];                  
        }
    }
    int a, b, c, d;
    REP(i, k){
        cin >> a >> b >> c >> d;
        cout << dpj[c][d] + dpj[a - 1][b - 1] - dpj[a - 1][d] - dpj[c][b - 1] << " " << dpo[c][d] + dpo[a - 1][b - 1] - dpo[a - 1][d] - dpo[c][b - 1] <<  " " << dpi[c][d] + dpi[a - 1][b - 1] - dpi[a - 1][d] - dpi[c][b - 1] << endl;
    }
}
