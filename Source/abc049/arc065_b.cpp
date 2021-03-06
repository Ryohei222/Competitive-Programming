#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<utility>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
typedef long long int ll;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i<signed(n);i++)
#define EREP(i,n) for(int i=1;i<=signed(n);i++)
#define ALL(a) (a).begin(),(a).end()
using std::cout;
using std::vector;
using std::endl;
using std::cin;
using std::string;
using std::min;
using std::max;
//#define EVEL 1
#ifdef EVEL
#define DEB(X) cout << #X << ":" <<X<<" " ;
#define TF(f) f ? cout<<"true  " : cout<<"false ";
#define END cout<<"\n";
#else
#define DEB(X) {}
#define TF(f) {}
#define END {}
#endif
const ll MOD = 1000000007;
const ll INF = 9e9;
typedef std::pair<int,int> P;


    ll N,K,L;
    ll ans;
    string A[200010];
    std::unordered_map<string,int> S;
struct UnionFind {
    vector< int > data;
    UnionFind(int sz){
        data.assign(sz, -1);
    }

    bool unite(int x, int y){
        x = find(x), y = find(y);
        if(x == y) return(false);
        if(data[x] > data[y]) std::swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return(true);
    }

    int find(int k){
        if(data[k] < 0) return(k);
        return(data[k] = find(data[k]));
    }

    bool same(int x,int y){
        return find(x)==find(y);
    }
    int size(int k){
        return(-data[find(k)]);
    }
};
int main(){
    std::ios_base::sync_with_stdio(false);
    cin>>N>>K>>L;
    UnionFind X(N+10),Y(N+10);
    REP(i,K){
        int a,b;
        cin>>a>>b;
        X.unite(a-1,b-1);
    }
    REP(i,L){
        int a,b;
        cin>>a>>b;
        Y.unite(a-1,b-1);
    }
    REP(i,N){
        A[i]=std::to_string(X.find(i))+"+"+std::to_string(Y.find(i));
        S[A[i]] += 1;
    }
    REP(i,N){
        cout<< S[A[i]];
        if(i!=N-1)cout<<" ";
    }
    //cout<<ans<<endl;
    return 0;
}

