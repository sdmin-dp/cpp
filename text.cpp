#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 1e5 + 10;

int n, ans = 0;
bool color[N];
vector<int> G[N];

bool dfs (int x, int father) {
    bool flag = false;
    for (auto v : G[x]) {
        if (v != father && dfs (v, x))
            flag = true;
    }
    if (!color[x] && flag)
        ans++;
    return (color[x] || flag);
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> color[i];
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    int x = -1;
    for (int i = 1; i <= n; i++) {
        if (color[i] == 1) {
            x = i;
            break;
        }
    }

    dfs(x, 0);
    cout << ans;
}

int main() {
    ios::sync_with_stdio (false);
    cin.tie(nullptr), cout.tie(0);

    int T = 1; // cin >> T;
    while(T--) 
        solve();
    return 0;
}