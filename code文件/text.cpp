#include<bits/stdc++.h>
using namespace std;

const int N = 500005;   // n 最大 5e5，原来的 1e5+5 越界了
int a[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        long long n, m, k;
        cin >> n >> m >> k;
        for(int i = 1; i <= n; i++) cin >> a[i];

        long long blocks = 0;   // 初始的极长连续段个数
        long long two = 0;      // 一次操作能贡献 +2 块的"有效位置"数量
        long long one = 0;      // 一次操作只能贡献 +1 块的位置数量

        for(int i = 1; i <= n; ){
            int j = i;
            while(j + 1 <= n && a[j + 1] == a[i]) ++j;
            int len = j - i + 1;
            ++blocks;
            two += (len - 1) / 2;       // 每 2 个相邻相等对需要 1 次操作
            if(len % 2 == 0) ++one;     // 剩下 1 个相等对只能靠 1 次操作换 1 块
            i = j + 1;
        }

        long long use2 = min(m, two);
        long long gain = use2 * 2;
        long long rest = m - use2;
        if(rest > 0) gain += min(rest, one);

        cout << blocks + gain << '\n';
    }
    return 0;
}
