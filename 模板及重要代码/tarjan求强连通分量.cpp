#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define el '\n'

const ll N = 1e4 + 5;
ll n, m;
vector<ll> g[N];    // 存图：g[x] 里面装着 x 指向的所有邻居

// --- Tarjan 的核心装备 ---
ll dfn[N];          // “入场序号”：你是第几个被搜到的（一旦定下就不变）
ll low[N];          // “能认到的最高祖辈”：通过这组关系，你最高能联系到哪个序号的人
ll ins[N];          // “是否在小黑屋”：标记节点是不是在当前的栈里
stack<ll> s;        // “小黑屋”：还没确定归属的节点都先关在这里
ll idx;             // “发号器”：每搜到一个新人，号就加 1

// --- 结果和缩点装备 ---
ll cnt = 0;         // “社团编号”：一共分出了多少个强连通分量
ll len[N];          // “社团规模”：每个社团里有几个人
ll color[N];        // “社团证”：记录每个人到底属于哪个社团
ll out[N];          // “社团外交”：记录这个社团有没有指向别人的边（出度）

/**
 * 核心：划清界限的 Tarjan 函数
 */
void tarjan(ll x) {
    // 1. 刚进场：发个入场号，默认最高祖辈就是自己
    dfn[x] = low[x] = ++idx;
    s.push(x);      // 把你塞进小黑屋
    ins[x] = 1;     // 标记你在小黑屋待命

    // 2. 找关系：看看 x 的邻居们
    for (auto i : g[x]) {
        if (!dfn[i]) {
            // 如果邻居还没入场：带他入场，继续递归搜
            tarjan(i);
            // 重点！搜完回来，如果邻居认到了更高的祖辈，你也赶紧跟着认了
            low[x] = min(low[x], low[i]);
        } else if (ins[x]) {
            // 如果邻居在小黑屋：说明撞上“回头路”了，抓到了一个环
            // 赶紧看看这个老邻居的入场号，更新一下自己的最高祖辈
            low[x] = min(low[x], dfn[i]);
        }
    }

    // 3. 搞总结：如果你的最高祖辈还是你自己，说明你是这个社团的“带头大哥”
    if (low[x] == dfn[x]) {
        cnt++; // 新成立一个社团
        ll top;
        do {
            top = s.top(); // 从小黑屋里抓出后进来的兄弟
            s.pop();
            ins[top] = 0;    // 兄弟出狱，自由了
            color[top] = cnt; // 登记社团编号
            len[cnt]++;      // 这个社团人数加 1
        } while (top != x);  // 直到把大哥（自己）也抓出来为止
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        ll x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }

    // 防漏：怕有的点孤苦伶仃或者图不连通，每个点都得排查一遍
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) tarjan(i);
    }

    // 缩点逻辑：看各个社团之间有没有勾连
    for (int u = 1; u <= n; u++) {
        for (auto v : g[u]) {
            // 如果 u 指向 v，但他们不在一个社团里
            if (color[u] != color[v]) {
                // 那 u 所在的社团就多了一份“外交开销”（出度）
                out[color[u]]++;
            }
        }
    }
}