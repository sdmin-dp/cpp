#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'

const ll N = 2e5 + 5; // 注意：缩点后的图点数 = 原图点 + 点双数量，所以开 2 倍
ll n, m;
vector<ll> g[N], ng[N]; // g: 原图, ng: 缩点后的新图(圆方树)
ll dfn[N], low[N], idx; // idx 用于 Tarjan 的时间戳
stack<ll> st;           // 栈：像一个箩筐，DFS 走过的点先存里面
ll bcc_cnt;             // 计数器：记录发现了多少个点双分量（相当于方点个数）

// 第一步：用 Tarjan 算法把所有的点双圈子找出来
void dfs(ll x, ll root) {
    dfn[x] = low[x] = ++idx; // 进场：给自己盖个时间戳戳，初始 low 是自己
    st.push(x);              // 进栈：把当前点扔进箩筐

    // 情况 A：这个点是个没人理的孤立点
    if (x == root && g[x].empty()) {
        bcc_cnt++; // 发现一个人的分量
        ll square_node = n + bcc_cnt; // 方点编号
        ng[x].push_back(square_node);
        ng[square_node].push_back(x);
        st.pop(); 
        return;
    }

    for (auto i : g[x]) {
        if (dfn[i] == 0) { // 没走过，说明 i 是 x 的儿子
            dfs(i, root);
            low[x] = min(low[x], low[i]); // 儿子回溯时，更新 x 的 low 值
            
            // 【核心判定】如果儿子 i 无论如何跑不到 x 的上面
            // 说明从 x 到 i 这一坨东西形成了一个坚固的“点双分量”
            if (low[i] >= dfn[x]) {
                bcc_cnt++; // 发现一个新的分量，记个号
                ll square_node = n + bcc_cnt; // 给这个分量造一个“方点”

                // 重点：我们要把这个圈子里所有的点都和这个“方点”连起来
                while (true) {
                    ll node = st.top(); // 从箩筐顶拿出一个点
                    st.pop();
                    // 在新图里，圆点 node 和 方点 square_node 互相连边
                    ng[node].push_back(square_node);
                    ng[square_node].push_back(square_node); // 这里笔误修正: 应该是 ng[square_node].push_back(node)
                    // 修正后代码逻辑：
                    ng[square_node].push_back(node);
                    
                    if (node == i) break; // 一直弹出到当前这个儿子 i 为止
                }
                // 特别注意：x 是这个分量的“头儿”，它也属于这个分量
                // 但 x 可能还是其他分量的“头儿”，所以 x 不能弹出栈，只能连边
                ng[x].push_back(square_node);
                ng[square_node].push_back(x);
            }
        } 
        else {
            // 如果 i 已经走过了，说明是一条回边，直接更新 low
            low[x] = min(low[x], dfn[i]);
        }
    }
}

void solve() {
    if(!(cin >> n >> m)) return;
    for (int i = 1; i <= m; i++) {
        ll x, y;
        cin >> x >> y;
        if (x == y) continue; // 自环没用，滚粗
        g[x].push_back(y);
        g[y].push_back(x);
    }

    // 1. 开始大扫除，把每个连通块里的点双都找出来并连好新图
    idx = 0;
    bcc_cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) dfs(i, i);
    }

    // 2. 此时 ng 数组里已经是缩点后的“圆方树”了
    // 圆点编号：1 ~ n
    // 方点编号：n+1 ~ n+bcc_cnt
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}