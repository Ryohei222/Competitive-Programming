#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <unordered_set>
#include <bitset>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
static const int INF = 1000010000;
static const int NIL = -1;
static const int MOD = 1000000007;
 
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define SORT(v) sort(v.begin(), v.end());
#define pb push_back
#define mp make_pair
#define np next_permutation
#define pq priority_queue
 
int gcd(int a, int b) { int c; while (b != 0) { c = a%b; a = b; b = c; }return a; }
int lcm(int a, int b) { int c = gcd(a, b); a /= c; return a*b; }
int nCr(int a, int b) { int i, r = 1; for (i = 1; i <= b; i++) { r *= (a + 1 - i); r /= i; }return r; }
int pow(int a, int b) { int i, r = 1; for (i = 1; i <= b; i++) { r *= a; }return r; }
long long llpow(long long a, long long b) { long long i, r = 1; for (i = 1; i <= b; i++) { r *= a; }return r; }
long long llgcd(long long a, long long b) { long long c; while (b != 0) { c = a%b; a = b; b = c; }return a; }
long long lllcm(long long a, long long b) { long long c = llgcd(a, b); a /= c; return a*b; }
long long llnCr(long long a, long long b) { long long i, r = 1; for (i = 1; i <= b; i++) { r *= (a + 1 - i); r /= i; }return r; }
 
//int dx4[4] = {0,1,0,-1}, dy4[4] = {-1,0,1,0};
//int dx5[5] = {-1,0,0,0,1}, dy5[5] = {0,-1,0,1,0};
int dx8[8] = {-1,0,1,1,1,0,-1,-1}, dy8[8] = {1,1,1,0,-1,-1,-1,0};
//int dx9[9] = {-1,0,1,1,1,0,-1,-1,0}, dy9[9] = {1,1,1,0,-1,-1,-1,0,0};

int main(){
    // a , b <= 500
    // a == b 10 100
    // a + 1 == b || b + 1 == a odd
    // a > b
    //white - a
    //black - b
    /*
    .#.#.
    .....
    .###.
    .#.#.
    .###.    
    */
    int a, b;
    cin >> a >> b;
    char mas[100][100];
    if(a < b){
        REP(i, 100) REP(j, 100){
            mas[i][j] = '.';
        }
        int cnt = a - 1;
        for(int i = 1; i < 99; i += 4){
            if(cnt == 0) break;
            for(int j = 1; j < 99; j+= 4){
                if(cnt == 0) break;
                REP(k, 8){
                    int nx = i + dx8[k];
                    int ny = j + dy8[k];
                    mas[nx][ny] = '#';
                }
                cnt--;
            }
        }
        cnt = b - (a - 1);
        int x = ((a + 24) / 25) * 4 + 1, y = 0;        
        while(cnt){
            if(mas[x][y] == '.' && mas[x + 1][y] == mas[x - 1][y] && mas[x][y + 1] == mas[x][y - 1] && mas[x + 1][y] == mas[x][y + 1] && mas[x + 1][y] == '.'){
                mas[x][y] = '#';
                cnt--;
                y++;
            }
            y++;
            if(y >= 99){
                x += 2;
                y = 0;
            }
        }
    }else{
        REP(i, 100) REP(j, 100){
            mas[i][j] = '#';
        }
        int cnt = b - 1;
        for(int i = 1; i < 99; i += 4){
            if(cnt == 0) break;
            for(int j = 1; j < 99; j+= 4){
                if(cnt == 0) break;
                REP(k, 8){
                    int nx = i + dx8[k];
                    int ny = j + dy8[k];
                    mas[nx][ny] = '.';
                }
                cnt--;
            }
        }
        cnt = a - (b - 1);
        int x = ((b + 24) / 25) * 4 + 1, y = 0;
        while(cnt){
            if(mas[x][y] == '#' && mas[x + 1][y] == mas[x - 1][y] && mas[x][y + 1] == mas[x][y - 1] && mas[x + 1][y] == mas[x][y + 1] && mas[x + 1][y] == '#'){
                mas[x][y] = '.';
                cnt--;
                y++;
            }
            y++;
            if(y >= 99){
                y = 0;
                x += 2;
            }
        }
    }
    cout << "100 100" << endl;
    REP(i, 100){
        REP(j, 100){
            cout << mas[i][j];
        }
        cout << endl;
    }
    return 0;
}
