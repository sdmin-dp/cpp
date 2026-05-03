#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define el '\n'

const ll N = 2e4 + 5;
ll n, m;             // n: 点数, m: 边数
vector<ll> g[N];     // 邻接表存图
bool flag[N];        // 标记数组：flag[i] 为 true 表示点 i 是割点
ll idx = 0;          // 全洁时间戳计数器
ll num[N];           // DFN 序：节点 i 在 DFS 搜索中被访问到的次序（时间戳）
ll low[N];           // 追溯值：节点 i 不通过父节点能到达的最小时间戳

/**
 * Tarjan 算法求割点
 * @param x  当前访问节点
 * @param fa 当前节点的父节点（用于区分树边和回边，并判断根节点条件）
 */
void dfs(ll x, ll fa) {
    ll child = 0;        // 在 DFS 生成树中，x 节点的子树个数
    num[x] = low[x] = ++idx; // 初始化：DFN 和 LOW 初始都指向自己

    for (auto i : g[x]) {
        if (i == fa) continue; // 重点：不直接跑回父节点，避免逻辑死循环

        if (!num[i]) {         // 如果 i 没被访问过，(x, i) 是一条树边
            child++;
            dfs(i, x);         // 递归访问子节点
            
            // 策略：从子节点回溯后，尝试更新当前节点的 low 值
            // 如果子节点能跳得更高，那我也能跟着跳上去
            low[x] = min(low[x], low[i]);

            // --- 割点判定法则 ---
            
            // 情况 1：非根节点判定
            // 如果子节点 i 无论如何也跑不到 x 本身或者 x 之前的祖先（low[i] >= num[x]）
            // 那么一旦切断 x，子节点 i 所在的整棵子树就和原图失联了
            if (fa != 0 && low[i] >= num[x]) {
                flag[x] = true;
            }
            
            // 情况 2：根节点判定
            // 根节点没有“上方”的祖先，所以上述条件不适用。
            // 只要根节点在 DFS 树中有两个及以上的独立子分支，切断根后这些子分支必不相连
            if (fa == 0 && child >= 2) {
                flag[x] = true;
            }
        } 
        else {
            // 如果 i 已被访问过，且 i 不是 x 的父亲，说明 (x, i) 是一条回边（反向边）
            // 此时 i 是 x 的祖先，直接用 num[i] 更新 low[x]
            low[x] = min(low[x], num[i]);
        }
    }
}

void solve() {
    // 1. 输入数据与建图
    if (!(cin >> n >> m)) return;
    for (int i = 1; i <= m; i++) {
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // 2. 遍历每个点，处理非连通图的情况
    for (int i = 1; i <= n; i++) {
        if (!num[i]) { // 如果该点未被 DFN 染色，说明是新连通分量的起点
            dfs(i, 0); // 设根节点的父节点为 0
        }
    }

    // 3. 统计并输出结果
    vector<ll> ans;
    for (int i = 1; i <= n; i++) {
        if (flag[i]) ans.push_back(i);
    }

    cout << ans.size() << el;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << (i == ans.size() - 1 ? "" : " ");
    }
    cout << el;
}

int main() {
    // 优化 IO 效率
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll T = 1;
    // cin >> T; // 如果有多组数据则开启
    while (T--) {
        solve();
    }
    return 0;
}