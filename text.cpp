#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 3e5 + 10;

int n, m, q, dis[N], g[N], f[N], ans[N], res;
vector<int> G[N];
bool vis[N];

int fr (int x) {
    return (f[x] == x ? x : f[x] = fr(f[x]));
}

void init () {
    for (int i = 1; i <= n; i++)
        f[i] = i;
}

void dfs(int x, int fa)
{
    int dd = -1, ddd = -1;
    for (auto v : G[x])
    {
        if (v == fa)
            continue;
        dfs(v, x);
        int t = dis[v] + 1;
        dis[x] = max(t, dis[x]);
        if (t > dd)
            ddd = dd, dd = t;
        else if (t > ddd)
            ddd = t;
    }
    g[x] = max(dd, ddd);
    res = max(res, g[x]);
}
void solve() {
    cin >> n >> m >> q;
    init();
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i] || f[i] != i) {
            continue;
        }
        res = 0;
        memset(dis,0,sizeof(dis));
        dfs(i, 0);
        ans[i] = res;
        vis[i] = true;
    }
    for (int i = 1; i <= q; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            int x;
            cin >> x;
            cout << ans[fr(x)] << '\n';
        } else if (op == 2) {
            // cout << "you are dog" << '\n';
            int x, y;
            cin >> x >> y;
            x = fr(x), y = fr(y);
            if (x == y)
                continue;
            // for (int i = 1; i <= n; i++)
                // cout << ans[i] << ' ';
            int t = max((((ans[x] + 1) >> 1) + ((ans[y] + 1) >> 1)) + 1, max(ans[x], ans[y]));
            f[fr(x)] = fr (y);
            ans[fr(x)] = t;
        }
    }
}
int main() {
    ios::sync_with_stdio (false);
    cin.tie(nullptr), cout.tie(0);
    int T = 1; // cin >> T;
    while(T--) 
        solve();

    return 0;
}