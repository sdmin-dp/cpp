#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'

const ll N=5e5+5;
ll n, m, idx;
vector<ll> g[N];         // 邻接表存图
ll dfn[N], low[N];      // dfn: 时间戳, low: 追溯值
vector<pair<ll,ll>> bridge; // 存储找到的所有桥
map<pair<ll,ll>,bool> mp;   // 标记哪些边是桥
vector<ll> ans[N];      // 存储每个双连通分量的节点
ll color[N];            // 标记每个节点所属的分量编号

// Tarjan 算法找桥
void dfs(ll x, ll fa) {
    low[x] = dfn[x] = ++idx; // 初始化时间戳
    bool flag = 0;           // 处理重边情况
    for(auto i : g[x]) {
        if(!dfn[i]) {        // 如果节点 i 未访问
            dfs(i, x);
            low[x] = min(low[x], low[i]); // 更新追溯值
            // 如果 low[i] > dfn[x]，说明 i 无法通过非父子边回到 x 或其祖先，故 x-i 是桥
            if(low[i] > dfn[x]) bridge.push_back({min(x, i), max(x, i)});
        }
        else if(i == fa) {   // 访问到父节点
            if(!flag) {      // 第一次跳过父节点（防止回溯）
                flag = 1;
                continue;
            } else {         // 如果有重边，则可以更新 low
                low[x] = min(low[x], dfn[i]);
            }
        } else {             // 访问到已访问节点（返祖边）
            low[x] = min(low[x], dfn[i]);
        }
    }
}

// 通过 DFS 给每个边双连通分量染色（分组）
void change(ll x) {
    color[x] = idx; // 赋予当前分量编号
    for(auto i : g[x]) {
        // 如果该边不是桥，且目标点还没被染色，则继续搜寻同一分量的点
        if(!mp[{min(x, i), max(x, i)}] && !color[i]) change(i);
    }
}

void solve() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        ll x, y; cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    // 1. 跑 Tarjan 寻找所有的桥
    idx = 0;
    for(int i = 1; i <= n; i++) if(!dfn[i]) dfs(i, 0);

    // 2. 将桥边存入 map 以便后续 O(log E) 查询
    for(auto &i : bridge) mp[{i.first, i.second}] = 1;

    // 3. 再次遍历图，跳过桥边，划分连通块
    idx = 0; 
    for(int i = 1; i <= n; i++) {
        if(!color[i]) {
            idx++; // 发现新的边双连通分量
            change(i);
        }
    }

    // 4. 输出结果
    cout << idx << el; // 输出分量个数
    for(int i = 1; i <= n; i++) ans[color[i]].push_back(i); // 按颜色分组
    for(ll i = 1; i <= idx; i++) {
        cout << ans[i].size() << " "; // 输出当前分量节点数
        for(auto &j : ans[i]) cout << j << " "; // 输出节点编号
        cout << el;
    }
}

int main() {
    // 优化输入输出效率
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll T = 1;
    // cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}