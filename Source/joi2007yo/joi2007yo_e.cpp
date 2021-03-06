#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define SORT(v) sort(v.begin(), v.end());
#define pb(a) push_back(a)
using ll = long long;
using namespace std;

int a, b, c, p, m, k, r, n, cntnonpass = 0, cntpass = 0, beforecnt = 0;
int parts[400], nonp[1000], nonm[1000], nonk[1000];

int main(){
    cin >> a >> b >> c >> n;
    REP(i, 400){
        parts[i] = 2;
    }
    REP(i, n){
        cin >> p >> m >> k >> r;
        if(r){
            parts[p] = parts[m] = parts[k] = 1;
        }else{
            nonp[cntnonpass] = p;
            nonm[cntnonpass] = m;
            nonk[cntnonpass] = k;
            if(parts[p] == 1 && parts[m] == 1){
                parts[k] = 0;
            }else if(parts[m] == 1 && parts[k] == 1){
                parts[p] = 0;
            }else if(parts[k] == 1 && parts[p] == 1){
                parts[m] = 0;
            }
            cntnonpass++;
        }
    }
    while(1){
        REP(i, cntnonpass){
            p = nonp[i]; m = nonm[i]; k = nonk[i];
            cntpass++;
            if(parts[p] == 1 && parts[m] == 1){
                parts[k] = 0;
            }else if(parts[m] == 1 && parts[k] == 1){
                parts[p] = 0;
            }else if(parts[k] == 1 && parts[p] == 1){
                parts[m] = 0;
            }else{
                cntpass--;
            }
        }
        if(cntpass == beforecnt){
            break;
        }else{
            beforecnt = cntpass;
            cntpass = 0;
        }
    }
    FOR(i, 1, a + b + c + 1){
        cout << parts[i] << endl;
    }
}
