#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define SORT(v) sort(v.begin(), v.end());
#define pb(a) push_back(a)
using ll = long long;
using namespace std;

ll nzyo(ll o){
    ll ans = 1;
    REP(i, o){
        ans *= 2;
    }
    return ans;
}

string roop(string str, ll x){
    string ans;
    REP(i, (int)x){
        ans += str;
    }
    return ans;
}

ll n, k;

int main(){
    cin >> n >> k;
    ll height = nzyo(n);
    ll mheight = height;
    ll remain = height;
    if(height / 2 >= k){
        remain /= 2;
        cout << roop("J", remain) + roop("O", remain) << endl;
        return 0;
    }
    while(1){
        height /= 2;
        if(mheight - height < k){
            remain -= height;
            cout << roop("I", height);
        }else{
            if(remain == 1){
                cout << "J" << endl;
            }else{
                cout << roop("J", remain / 2) + roop("O", remain / 2) << endl;
            }
            break;
        }
    }
}
