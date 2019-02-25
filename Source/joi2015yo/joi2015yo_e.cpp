#pragma region includes, macros
#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <map>
#include <set>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <stdlib.h>

using namespace std;
 
typedef long long i64;
typedef pair<i64, i64> P;

template<class T>
const T INF = numeric_limits<T>::max();
template<class T>
const T SINF = numeric_limits<T>::max() / 10;
static const i64 MOD = 1000000007;

//int dx[4] = {0,1,0,-1}, dy[4] = {-1,0,1,0};
//int dx[5] = {-1,0,0,0,1}, dy[5] = {0,-1,0,1,0};
int dx[8] = {-1,0,1,1,1,0,-1,-1}, dy[8] = {1,1,1,0,-1,-1,-1,0};
//int dx[9] = {-1,0,1,1,1,0,-1,-1,0}, dy[9] = {1,1,1,0,-1,-1,-1,0,0};

struct edge {
	i64 from, to, cost;
	edge(i64 to, i64 cost) : from(-1), to(to), cost(cost) {}
	edge(i64 src, i64 to, i64 cost) : from(src), to(to), cost(cost) {}
};

template<typename T>
vector<T> make_v(size_t a){return vector<T>(a);}

template<typename T,typename... Ts>
auto make_v(size_t a,Ts... ts){
	return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));
}

template<typename T,typename V>
typename enable_if<is_class<T>::value==0>::type
fill_v(T &t,const V &v){t=v;}

template<typename T,typename V>
typename enable_if<is_class<T>::value!=0>::type
fill_v(T &t,const V &v){
	for(auto &e:t) fill_v(e,v);
}

#pragma endregion

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    i64 h, w;
    cin >> h >> w;
    vector<vector<int>> mas(h, vector<int>(w, 0));
    vector<vector<bool>> used(h, vector<bool>(w, false));
    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j){
            char c;
            cin >> c;
            if(c == '.') used[i][j] = true;
            else mas[i][j] = (int)c - (int)'0';
        }
    }
    vector<vector<bool>> tused = used;
    queue<P> que;
    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j){
            if(used[i][j]) continue;
            int cnt = 0;
            for(int k = 0; k < 8; ++k){
                int nx = i + dx[k];
                int ny = j + dy[k];
                if(used[nx][ny]) cnt++;
            }
            if(cnt >= mas[i][j]){
                que.push(P(i, j));
                tused[i][j] = true;
            }
        }
    }
    if(que.size() == 0){
        cout << 0 << endl;
        return 0;
    }
    int ans = 1;
    while(1){
        bool flag = true;
        queue<P> tque;
        used = tused;
        while(!que.empty()){
            P p = que.front(); que.pop();
            for(int n = 0; n < 8; ++n){
                int x = p.first + dx[n];
                int y = p.second + dy[n];
                if(used[x][y] || tused[x][y]) continue;
                int cnt = 0;
                for(int k = 0; k < 8; ++k){
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if(nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
                    if(used[nx][ny]){
                        ++cnt;
                    }
                }
                if(cnt >= mas[x][y]){
                    tque.push(P(x, y));
                    tused[x][y] = true;
                    flag = false;
                }
            }
        }
        if(flag) break;
        que = tque;
        ++ans;
    }
    cout << ans << endl;
}