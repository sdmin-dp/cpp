#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> g[N];
bool vis[N];
int deg[N];
vector<int> component_nodes;

void dfs(int u) {
    vis[u] = true;
    component_nodes.push_back(u);
    for (int v : g[u]) {
        if (!vis[v]) dfs(v);
    }
}

void solve() {
    int n, m;
    while (cin >> n >> m) {
        for (int i = 1; i <= n; i++) {
            g[i].clear();
            vis[i] = false;
            deg[i] = 0;
        }
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
            deg[u]++; deg[v]++;
        }

        int total_strokes = 0;
        for (int i = 1; i <= n; i++) {
            if (!vis[i] && deg[i] > 0) {
                component_nodes.clear();
                dfs(i);
                
                int odd_cnt = 0;
                for (int node : component_nodes) {
                    if (deg[node] % 2 != 0) odd_cnt++;
                }
                
                if (odd_cnt == 0) total_strokes += 1;
                else total_strokes += odd_cnt / 2;
            }
        }
        cout << total_strokes << endl;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
