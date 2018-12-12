## 立ってるbitの数

```cpp
__builtin_popcount();
__builtin_popcountl();
__builtin_popcountll();
```

## あるbitが立っているか

```cpp
int i, k;
i & (1LL<<k) // kbit目が立っている → true
```

##  bitset

```cpp
#include <bitset>

using namespace std;

int main(){
    bitset<32> bs(1333); // 長さ32のbit列を定義, 1333で初期化
    bs[0]; // 右から(0-indexed)0番目のbitの状態
    bs.set(1); // ...1番目のbitを1にする
    bs.reset(1); // ...1番目のbitを0にする
    bs.flip(); // 全bit反転
    bs.count(); // = __builtin_popcount(); 立ってるbitの数を取得
    bs.any(); // いずれかのbitが 1 → true/全部0 → false
    bs.all(); // すべてのbitが 1 → true/else → false
    cout << bs << endl; // このまま出力できる(32bit分)
}
```