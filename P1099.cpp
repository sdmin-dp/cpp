#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 305;
int n, s;
vector<pair<int, int>> g[N];
int fa[N], dis[N];
int dia[N], cnt, pre[N], maxd[N];
bool vis[N];

void dfs(int u, int f)
{
    fa[u] = f;
    for (auto [v, w] : g[u])
    {
        if (v == f)
            continue;
        dis[v] = dis[u] + w;
        dfs(v, u);
    }
}

void dfs2(int u, int f)
{
    for (auto [v, w] : g[u])
    {
        if (v == f || vis[v])
            continue;
        dis[v] = dis[u] + w;
        dfs2(v, u);
    }
}

void f()
{
    memset(dis, 0, sizeof(dis));
    dfs(1, 0);
    int A = 1;
    for (int i = 1; i <= n; i++)
        if (dis[i] > dis[A])
            A = i;

    memset(dis, 0, sizeof(dis));
    dfs(A, 0);
    int B = 1;
    for (int i = 1; i <= n; i++)
        if (dis[i] > dis[B])
            B = i;

    cnt = 0;
    for (int u = B; u; u = fa[u])
    {
        dia[++cnt] = u;
        pre[cnt] = dis[u];
    }
    reverse(dia + 1, dia + cnt + 1);
    reverse(pre + 1, pre + cnt + 1);
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= cnt; i++)
        vis[dia[i]] = true;
}
void solve()
{
    cin >> n >> s;
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    f();
    memset(maxd, 0, sizeof(maxd));
    for (int i = 1; i <= cnt; i++)
    {
        int u = dia[i];
        memset(dis, 0, sizeof(dis));
        dfs2(u, 0);
        for (int v = 1; v <= n; v++)
        {
            if (!vis[v])
            {
                maxd[i] = max(maxd[i], dis[v]);
            }
        }
    }
    int ans = 1e9;
    for (int l = 1; l <= cnt; l++)
    {
        for (int r = l; r <= cnt; r++)
        {
            if (pre[r] - pre[l] > s)
                continue;
            int ecc = 0;
            ecc = max(ecc, pre[l]);
            ecc = max(ecc, pre[cnt] - pre[r]);
            for (int k = l; k <= r; k++)
            {
                ecc = max(ecc, maxd[k]);
            }
            ans = min(ans, ecc);
       }
    }
    cout << ans << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    while (T--)
        solve();
    return 0;
}