#include <bits/stdc++.h>
#define ll l
using namespace std;
const int MAXN = 105;
const int INF = 0x3f3f3f3f;
vector<int> to[MAXN], cst1[MAXN], cst2[MAXN];
int dp[MAXN][MAXN];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int u, v, c, d;
        scanf("%d%d%d%d", &u, &v, &c, &d);
        to[u].push_back(v);
        cst1[u].push_back(c);
        cst2[u].push_back(d);
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[1][1] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (dp[i][j] == INF) continue;
            for (int p = 0; p < (int)to[i].size(); ++p) {
                int vi = to[i][p], ti = cst1[i][p];
                for (int q = 0; q < (int)to[j].size(); ++q) {
                    int vj = to[j][q], tj = cst2[j][q];
                    if (ti == tj) {
                        dp[vi][vj] = min(dp[vi][vj], dp[i][j] + ti);
                    }
                }
            }
        }
    }
    if (dp[n][n] == INF) puts("IMPOSSIBLE");
    else printf("%d\n", dp[n][n]);
    return 0;
}