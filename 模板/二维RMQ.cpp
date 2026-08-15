#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 255, K = 1e6 + 5;
int n, m, k, Log[N], st[N][N][10][10];
int xx1, xx2, yy1, yy2;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k; // n行 m列 k次查询
    Log[0] = -1;        // 计算Log数组
    for (int i = 1; i < N; i++)
        Log[i] = Log[i / 2] + 1;

    for (int i = 1; i <= n; i++) // 输入数据，不需要存原数组
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> st[i][j][0][0];
        }
    }
    for (int p = 1; p <= Log[n]; p++) // 先处理行，也就是第一列。条件还可以 (1<<p)<=n
    {
        for (int i = 1; i + (1 << p) - 1 <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                int m1 = st[i][j][p - 1][0];
                int m2 = st[i + (1 << (p - 1))][j][p - 1][0];
                st[i][j][p][0] = max(m1, m2);
            }
        }
    }
    for (int q = 1; (1 << q) <= m; q++) // 再处理列 把目标区域分成可重叠的左右两部分
    {
        for (int p = 0; (1 << p) <= n; p++) // 这层循环也可以在最内部，但要加上越界判断
        {
            for (int i = 1; i + (1 << p) - 1 <= n; i++) // 注意p对应行
            {
                for (int j = 1; j + (1 << q) - 1 <= m; j++) // q对应列
                {
                    int m1 = st[i][j][p][q - 1];
                    int m2 = st[i][j + (1 << (q - 1))][p][q - 1]; // 加找位置
                    st[i][j][p][q] = max(m1, m2);
                }
            }
        }
    }
    while (k--)
    {
        cin >> xx1 >> yy1 >> xx2 >> yy2;
        int p = Log[xx2 - xx1 + 1];
        int q = Log[yy2 - yy1 + 1];
        // 通过左上、左下、右上、右下合并出目标区域的最值
        int m1 = st[xx1][yy1][p][q];
        int m2 = st[xx2 - (1 << p) + 1][yy1][p][q]; // 减找位置
        int m3 = st[xx1][yy2 - (1 << q) + 1][p][q];
        int m4 = st[xx2 - (1 << p) + 1][yy2 - (1 << q) + 1][p][q];
        cout << max({m1, m2, m3, m4}) << "\n"; // 不要用endl，避免超时
    }
    return 0;
}

/*
in:
3 4 5
789 15225 27847 6452
3976 18268 23626 1943
13336 26216 17321 4960
2 2 3 4
2 3 3 4
2 1 3 4
1 3 2 4
1 2 3 2

out:
26216
23626
26216
27847
26216
*/


