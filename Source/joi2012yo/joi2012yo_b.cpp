#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define SORT(v) sort(v.begin(), v.end());
#define pb push_back
using ll = long long;
using namespace std;

signed main(){
    int n, a, b, tmp, pointA, pointB, point[110];
    cin >> n;
  	REP(i, n){
    	point[i] = 0;
    }
    REP(i, n * (n - 1) / 2){
        cin >> a >> b >> pointA >> pointB;
        if(pointA > pointB){
            point[a- 1] += 3;
        }else if(pointB > pointA){
            point[b - 1] += 3;
        }else{
            point[a - 1]++;
            point[b - 1]++;
        }
    }
    int pointCount[350];
    REP(i, 350) pointCount[i] = 0;
    REP(i, n){
        pointCount[point[i]]++; //勝ち点ごとにチーム数を集計
    }
    int pointRank[350];
    int current = 1;
    for(int i = 300; i >= 0; i--){
        pointRank[i] = current;
        current += pointCount[i];
    }
    REP(i, n){
        cout << pointRank[point[i]] << endl;
    }
    return 0;
}
