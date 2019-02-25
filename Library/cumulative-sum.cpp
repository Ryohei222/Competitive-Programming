#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <numeric>

using namespace std;
 
typedef long long i64; 

//-----end of template-----//

template<typename T>
struct CumulativeSum{
    // usage: CumulativeSum<i64> ps(a); // (a := vector<i64>) - construct particial sum array
    //        query(a, b) - return sum[a, b)
    vector<T> sum;
    CumulativeSum(vector<T> a){
        sum = vector<T>(a.size() + 1);
        sum[0] = 0;
        for(int i = 0; i < a.size(); ++i){
            sum[i + 1] = sum[i] + a[i];
        }
    }
    T query(T x, T y){
        return -sum[min(x, y)] + sum[max(x, y)];
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    i64 n;
    cin >> n;
    vector<i64> a(n);
    for(i64 i = 0; i < n; ++i) cin >> a[i];
    CumulativeSum<i64> cs(a);

    while(1){
        i64 a, b;
        cin >> a >> b;
        if(a == -1) break;
        else cout << cs.query(a, b) << endl;
    }
}