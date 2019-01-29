#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <numeric>

using namespace std;
 
typedef long long i64; 

//-----end of template-----//

template< typename Monoid >
struct SegmentTree{
    typedef function<Monoid(Monoid, Monoid)> F;
    
    int n, sz;
    vector<Monoid> node;
    F f;
    Monoid M1;

    SegmentTree(vector<Monoid> v, F f, Monoid M1) : f(f), M1(M1){
        sz = v.size();
        n = 1;
        while(n < sz) n *= 2;
        node.assign(2 * n, M1);
        for(int i = 0; i < sz; ++i) node[n + i] = v[i];
        for(int i = n - 1; i > 0; --i) node[i] = f(node[2 * i], node[2 * i + 1]);
    }

    void update(int k, Monoid val){
        k += n;
        node[k] = val;
        while(k >>= 1){
            node[k] = f(node[2 * k], node[2 * k + 1]);
        }
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