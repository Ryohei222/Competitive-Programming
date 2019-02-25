#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <numeric>

using namespace std;
 
typedef long long i64; 

//-----end of template-----//

struct LazySegmentTree{

    using Monoid = int;
    using OpMonoid = int;

    Monoid M1;
    OpMonoid OM0;

    Monoid f(Monoid a, Monoid b){
        return a + b; // RSQ
        //return min(a, b) // RMQ
    }

    Monoid g(Monoid a, OpMonoid b){
        if(b != OM0) return b;
        else return a;
    }

    OpMonoid h(OpMonoid a, OpMonoid b){
        // 作用素のマージ bに親を入れる(代入では親が優先されるので)
        if(b != OM0) return b;
        else return a;
    }

    vector<Monoid> node;
    vector<OpMonoid> lazy;

    int n, sz, ht;

    LazySegmentTree(vector<Monoid> v){
        sz = v.size();
        n = 1;
        while(n < sz){
            n *= 2;
            ++ht;
        }
        node.assign(2 * n, M1);
        lazy.assign(2 * n, M1);
        for(int i = 0; i < sz; ++i) node[n + i] = v[i];
        for(int i = n - 1; i > 0; --i) node[i] = f(node[2 * i], node[2 * i + 1]);
    }

    void push(int k){
        if(lazy[k] == OM0) return;
        if(k < n){
            // 葉でなければ子とマージ
            lazy[2 * k] = h(lazy[2 * k], lazy[k]);
            lazy[2 * k + 1] = h(lazy[2 * k + 1], lazy[k]);
        }
        node[k] = g(node[k], lazy[k]);
        lazy[k] = OM0;
    }

    void update(int k, Monoid val){
        k += n;
        node[k] = val;
        while(k >>= 1){
            node[k] = f(node[2 * k], node[2 * k + 1]);
        }
    }

    void update(int a, int b, OpMonoid val){
        a += sz; b += sz - 1;
        for(int i = ht; i > 0; --i) push(a >> i)
    }

    Monoid query(int a, int b){
        Monoid l = M1, r = M1;
        for(a += n, b += n; a != b; a >>= 1, b >>= 1){
            if(a & 1) l = f(l, node[a++]);
            if(b & 1) r = f(node[--b], r);
        }
        return f(l, r);
    }
};

int main(){
    int n, q;
    cin >> n >> q;
    vector<int> v(n, (1LL<<31) - 1);
    SegmentTree<int> seg(v, [](int a, int b){ return min(a, b);}, std::numeric_limits<int>::max());
    for(int i = 0; i < q; ++i){
        int com, x, y;
        cin >> com >> x >> y;
        if(com == 0) seg.update(x, y);
        if(com == 1) cout << seg.query(x, y + 1) << endl;
    }
    return 0;
}