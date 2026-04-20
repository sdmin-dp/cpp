#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

const int MAXN = 100005;
vector<int> adj[MAXN];      // 邻接表
int dfn[MAXN], low[MAXN], timer;
stack<pair<int, int>> st;   // 存储边的栈，用于提取点双
vector<vector<int>> bccs;   // 存储最终找出的所有点双

void tarjan(int u, int p = -1) {
    dfn[u] = low[u] = ++timer;
    
    for (int v : adj[u]) {
        if (v == p) continue; // 不走回头路去父节点

        if (!dfn[v]) { // 如果 v 没被访问过（树枝边）
            st.push({u, v}); // 把这条边压入栈
            tarjan(v, u);
            low[u] = min(low[u], low[v]); // 更新能回溯到的最小值

            // 【关键判定】：说明 u 是割点或其上方的连接点
            if (low[v] >= dfn[u]) {
                vector<int> bcc;
                // 从栈中弹出边，直到弹出 (u, v) 为止
                while (true) {
                    pair<int, int> edge = st.top();
                    st.pop();
                    bcc.push_back(edge.first);
                    bcc.push_back(edge.second);
                    if (edge.first == u && edge.second == v) break;
                }
                // 去重：因为一个点会在多条边中出现
                sort(bcc.begin(), bcc.end());
                bcc.erase(unique(bcc.begin(), bcc.end()), bcc.end());
                bccs.push_back(bcc);
            }
        } 
        else if (dfn[v] < dfn[u]) { // 如果 v 已经访问过（回边/返祖边）
            st.push({u, v});
            low[u] = min(low[u], dfn[v]); // 更新 low 值
        }
    }
}

int main() {
    // 假设有 n 个点，m 条边...
    // 遍历所有点防止图不连通
    // if (!dfn[i]) tarjan(i);
    return 0;
}