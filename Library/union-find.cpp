#include <iostream>
#include <vector>

using namespace std;

struct UnionFind{
    vector<int> data;

    UnionFind(int sz){
        data.assign(sz, -1);
    }

    int find(int x){
        if(data[x] <= -1) return x;
        else return (data[x] = find(data[x]));
    }

    bool same(int x, int y){
        return find(x) == find(y);
    }

    bool unite(int x, int y){
        if(same(x, y)) return false;
        x = find(x); y = find(y);
        if(data[x] > data[y]) swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return true;
    }

    int size(int x){
        return -1 * data[x];
    }

};