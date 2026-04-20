#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

const int MAXN = 500005; // 假设原图有 N 个点
// 圆方树里，总点数 = 原图圆点数 + 新造出来的方点数
// 最坏情况下，方点数也能达到 N 个，所以数组开 2 倍！
vector<int> adj[MAXN];      // 原图邻接表
vector<int> tree[MAXN * 2]; // 缩点后的“圆方树”邻接表
int dfn[MAXN], low[MAXN], timer;
stack<int> st;
int n, m, square_cnt; // square_cnt 记录方点编号

void tarjan(int u) {
    dfn[u] = low[u] = ++timer;
    st.push(u);

    for (int v : adj[u]) {
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
            
            // 找到了一个点双！
            if (low[v] >= dfn[u]) {
                // 1. 每发现一个点双，就新造一个“方点”
                // 方点的编号从 n+1 开始往后排
                square_cnt++; 
                int cur_square = n + square_cnt; 

                // 2. 把栈里的点（这个点双里的成员）拿出来连向方点
                while (true) {
                    int node = st.top();
                    st.pop();
                    // 圆点 node 与 方点 cur_square 连边
                    tree[node].push_back(cur_square);
                    tree[cur_square].push_back(node);
                    if (node == v) break;
                }
                
                // 3. 特别注意：u 也是这个点双的一员，也要和方点连边
                // 但 u 不能弹出，因为它可能还要和别的方点连边
                tree[u].push_back(cur_square);
                tree[cur_square].push_back(u);
            }
        } else {
            low[u] = min(low[u], dfn[v]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if (u == v) continue;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 初始化方点计数，原图有 n 个点，方点从 n+1 开始
    square_cnt = 0;

    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            // 处理孤立点的情况：
            // 如果这个点没边，Tarjan 进去直接就退出了
            // 但在圆方树里，它通常作为一个独立的圆点存在
            tarjan(i);
            // 弹掉根节点（可选，为了逻辑严密）
            if (!st.empty()) st.pop(); 
        }
    }

    // 此时圆方树已经建好了！
    // 树的总节点数是 n + square_cnt
    cout << "原图点数: " << n << "，缩点后方点数: " << square_cnt << endl;
    cout << "缩点后的圆方树连边情况如下：" << endl;
    for (int i = 1; i <= n + square_cnt; i++) {
        for (int neighbor : tree[i]) {
            // 因为是无向边，为了不重复打印，只打印从小到大的
            if (i < neighbor) {
                // 打印格式：(圆/方)点 -> (圆/方)点
                cout << (i <= n ? "圆" : "方") << i << " -- " 
                     << (neighbor <= n ? "圆" : "方") << neighbor << endl;
            }
        }
    }

    return 0;
}