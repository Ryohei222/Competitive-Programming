/*
https://ei1333.github.io/luzhiled/snippets/structure/segment-tree.html
*/
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
struct SegmentTree {

  int size;
  vector<Monoid> seg;
  const function<Monoid(Monoid, Monoid)> f;
  const Monoid M1;
 
  SegmentTree(int n, const function<Monoid(Monoid, Monoid)> f, const Monoid &M1) : f(f), M1(M1) {
    size = 1;
    while(size < n) size <<= 1;
    seg.assign(2 * size, M1);
  }
 
  void set(int k, const Monoid &x) {
    seg[k + size] = x;
  }
 
  void build() {
    for(int k = size - 1; k > 0; k--) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }
 
  void update(int k, const Monoid &x) {
    k += size;
    seg[k] = x;
    while(k >>= 1) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }
 
  Monoid query(int a, int b) {
    Monoid L = M1, R = M1;
    for(a += size, b += size; a < b; a >>= 1, b >>= 1) {
      if(a & 1) L = f(L, seg[a++]);
      if(b & 1) R = f(seg[--b], R);
    }
    return f(L, R);
  }
 
  Monoid operator[](const int &k) const {
    return seg[k + size];
  }
};


int main(){

}