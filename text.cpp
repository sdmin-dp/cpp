#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N = 4e4 + 10;
#define pll pair<ll, ll>
ll n, s, u, v, w, ans = -1e18;
ll dis[N];
vector<pll> e[N];
void bfs(ll x, ll f)
{
    queue<pll> q;
    q.push({x, f});
    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        ll x = p.first, f = p.second;
        for (auto i:e[x])
        {
            ll v = i.first, w = i.second;
            if (v != f)
            {
                dis[v] = max(dis[v], dis[x] + w);
                if (dis[v] > ans)
                {
                    ans = dis[v];
                    s = v;
                }
                q.push({v, x});
            }
        }
    }
}
void solve()
{
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    bfs(1, -1);
    ans = LLONG_MIN;
    fill(dis+1, dis + n+1, 0);
    bfs(s, -1);
    cout << ans << el;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}