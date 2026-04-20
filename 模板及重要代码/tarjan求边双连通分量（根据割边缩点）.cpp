#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'

const ll N = 1e5 + 5;
ll n, m;
vector<ll> g[N], ng[N]; // g: 原图, ng: 缩点后的新图
ll dfn[N], low[N], idx;
stack<ll> st;           // 点双必须用栈来暂存分量里的点
vector<ll> bcc[N];      // 存储每个点双连通分量里的点
ll bcc_cnt;             // 点双计数器（相当于你代码里的新 idx）

// 第一步：Tarjan 寻找点双并记录
void dfs(ll x, ll root) {
    dfn[x] = low[x] = ++idx;
    st.push(x);

    // 特判孤立点
    if (x == root && g[x].empty()) {
        bcc[++bcc_cnt].push_back(x);
        return;
    }

    for (auto i : g[x]) {
        if (dfn[i] == 0) { // 树枝边
            dfs(i, root);
            low[x] = min(low[i], low[x]);
            
            // 【点双判定】发现以 x 为顶点的分量
            if (low[i] >= dfn[x]) {
                bcc_cnt++;
                while (true) {
                    ll node = st.top();
                    st.pop();
                    bcc[bcc_cnt].push_back(node);
                    if (node == i) break;
                }
                // x 是割点或端点，必须进组但不弹出
                bcc[bcc_cnt].push_back(x);
            }
        } 
        else low[x] = min(low[x], dfn[i]); 
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        ll x, y;
        cin >> x >> y;
        if (x == y) continue; // 忽略自环
        g[x].push_back(y);
        g[y].push_back(x);
    }

    // 1. 跑 Tarjan 找点双
    idx = 0;
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) dfs(i, i);
    }

    // 2. 建立新图（建立圆方树）
    // 你的逻辑是遍历割边连新图，点双逻辑是：原图点(圆点) 连 点双ID(方点)
    for (int i = 1; i <= bcc_cnt; i++) {
        ll square_node = n + i; // 方点编号接在圆点后面
        for (auto x : bcc[i]) {
            // 连接圆点 x 和方点 square_node
            ng[x].push_back(square_node);
            ng[square_node].push_back(x);
        }
    }
    
    // 此时 ng 就是缩点后的树了，总点数为 n + bcc_cnt
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    // cin >> T; // 如果有多组数据记得重置全局变量
    while (T--) {
        solve();
    }
    return 0;
}