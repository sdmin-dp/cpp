#include <iostream>
using namespace std;
 
constexpr int N = 2e5 + 5;
 
int ls[N]; // 上一个颜色为 color 的客栈位置
int sum[N]; // 记录每种颜色当前可选的左侧客栈数量
int cc[N]; // 当前位置之前，每种色调出现的次数
int lp_idx = -1; // 上一个价格小于等于 p 的客栈位置
int main()
{
    int n, k, p;
    cin >> n >> k >> p;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        int color, price;
        cin >> color >> price;
        if (price <= p)
            lp_idx = i;
        if (lp_idx >= ls[color])
            sum[color] = cc[color];
        ls[color] = i;
        ans += sum[color];
        cc[color]++;
    }
    cout << ans << endl;
    return 0;
}