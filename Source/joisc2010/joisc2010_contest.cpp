#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define SORT(v) sort(v.begin(), v.end());
#define pb(a) push_back(a)
using ll = long long;
using namespace std;

#define DEFAULT_TIME -1

int point[1001]; //参加者の得点
int questPoint[11]; //各問題の配点
int cntWA[1001][11]; //WA数
int openTime[1001][11]; //最初の閲覧時間
int n, m, t, x, y, tk, nk, mk;
string state;

int main(){
    cin >> n >> m >> t >> x >> y;
    REP(i, 1001){
        point[i] = 0;
        REP(j, 11){
            cntWA[i][j] = 0;
        }
    }
    REP(i, m){
        cin >> questPoint[i + 1];
    }
    REP(i, y){
        cin >> tk >> nk >> mk >> state;
        if(state == "open"){
            openTime[nk][mk] = tk;
        }else if(state == "incorrect"){
            cntWA[nk][mk]++;
        }else{
            point[nk] += max(questPoint[mk] - (tk - openTime[nk][mk]) - 120 * cntWA[nk][mk], x);
        }
    }
    REP(i, n){
        cout << point[i + 1] << endl;
    }
}
