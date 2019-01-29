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
#include <climits>
#include <random>


using namespace std;
 
typedef long long i64;
typedef pair<i64, i64> P;

template<class T>
const T INF = numeric_limits<T>::max();
template<class T>
const T SINF = numeric_limits<T>::max() / 10;
static const i64 MOD = 1000000007;

int dx[4] = {0,1,0,-1}, dy[4] = {-1,0,1,0};
//int dx[5] = {-1,0,0,0,1}, dy[5] = {0,-1,0,1,0};
//int dx[8] = {-1,0,1,1,1,0,-1,-1}, dy[8] = {1,1,1,0,-1,-1,-1,0};
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

//-----end of template-----//

class xor128{
public:
    static constexpr unsigned min(){ return 0u; }   // 乱数の最小値
    static constexpr unsigned max(){ return INT_MAX; } // 乱数の最大値
    unsigned operator()(){ return random(); }
    xor128();
    xor128(unsigned s){ w=s; }  // 与えられたシードで初期化
private:
    unsigned x=123456789u,y=362436069u,z=521288629u,w;
    unsigned random();
};

xor128::xor128(){
    // シードが与えられない時は、
    // システムのハードウェアエントロピーソースからシードを生成
    std::random_device rd; 
    w=rd();

    for(int i=0;i<10;i++){  // 数回空読み(不要?)
        random();
    }
}
unsigned xor128::random(){
    unsigned t;
    t = x ^ (x << 11);
    x = y; y = z; z = w;
    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
}

int h, w;

#define BLACK '#'
#define WHITE '.'

int csolve(vector<string> s){
	bool used[400][400];
	for(int i = 0; i < 400; ++i) for(int j = 0; j < 400; ++j) used[i][j] = false;
	int ans = 0;
	for(int i = 0; i < h; ++i) for(int j = 0; j < w; ++j){
		if(used[i][j]) continue;
		vector<int> cnt(200, 0);
		queue<P> que;
		que.push(P(i, j));
		cnt[s[i][j]]++;
		used[i][j] = true;
		while(!que.empty()){
			P t = que.front(); que.pop();
			int x = t.first;
			int y = t.second;
			for(int k = 0; k < 4; ++k){
				int nx = x + dx[k];
				int ny = y + dy[k];
				if(nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
				if((s[nx][ny] != s[x][y]) && !used[nx][ny]){
					que.push(P(nx, ny));
					cnt[s[nx][ny]]++;
					used[nx][ny] = true;
				}
			}
		}
		ans += cnt[WHITE] * cnt[BLACK];
	}
	return ans;
}

int dsolve(vector<string> s){
	int ans = 0;
	for(int i = 0; i < h; ++i){
		for(int j = 0; j < w; ++j){
			queue<P> que;
			que.push(P(i, j));
			auto used = make_v<bool>(h, w);
			used[i][j] = true;
			int sum  = 0;
			while(!que.empty()){
				P tmp = que.front(); que.pop();
				int x = tmp.first, y = tmp.second;
				for(int k = 0; k < 4; ++k){
					int nx = x + dx[k];
					int ny = y + dy[k];
					if(0 > nx || 0 > ny || h <= nx || w <= ny) continue;
					if(!used[nx][ny] && (s[x][y] != s[nx][ny])){
						que.push(P(nx, ny));
						used[nx][ny] = true;
						if(s[i][j] != s[nx][ny]) sum++;
					}
				}
			}
			ans += sum;
		}
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int h, w;
	cin >> h >> w;
	xor128 xs(n);
	for(int k = 0; k < 100000; ++k){
		vector<string> s;
		for(int i = 0; i < h; ++i) s[i] = "fosjfolsajflasjflajslfjdklfjdlsfjslkdfjlksdjflksdjfklsdjfklsjfklsdfsdfloksjdflksdjflksjdklfjsdlkfjskldjfklsdjfkldsjfklsdjflksdjfklsdjfkljdsflklf";
		for(int i = 0; i < h; ++i){
			for(int j = 0; j < w; ++j){
				if(xs() % 2) s[i][j] = '#';
				else s[i][j] = '.';
			}
		}
		cout << csolve(s) << endl;
		break;
		if(csolve(s) != dsolve(s)){
			for(int i = 0; i < h; ++i) cout << s[i] << endl;
		}
	}
}