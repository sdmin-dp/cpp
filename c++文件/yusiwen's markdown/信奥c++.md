放一篇大型秘籍：[大山秘籍]([Docs](https://tv7x543ftn5.feishu.cn/docx/DaODdbJHaokAzFxzCGNc4TeVnTe))

# 一个很容易被忽略的函数--exp

$exp(x)$表示求$e$（自然对数）的$x$次方。


# Tarjan算法

## 算法概述

Tarjan算法是由Robert Tarjan在1972年提出的一种基于深度优先搜索的图算法，用于解决图论中的多种连通性问题。该算法以其高效性和简洁性著称，主要应用包括：

- 求解有向图的强连通分量(SCC)
- 求解无向图的割点(关节点)
- 求解无向图的割边(桥)
- 求解最近公共祖先(LCA)

## 核心思想

Tarjan算法的核心思想是**利用DFS遍历图，通过时间戳和回溯信息来识别图中的连通结构**。算法维护两个关键数组：

1. **dfn数组**：记录每个节点在DFS中的访问顺序（时间戳）
2. **low数组**：记录每个节点能够通过回边或子树到达的最早时间戳

通过比较dfn和low值，算法能够识别出图中的连通分量、割点和割边。

## 时间戳与回溯

### 时间戳(dfn)

在DFS过程中，每个节点被访问时会被分配一个唯一的时间戳，表示该节点在遍历中的顺序。时间戳具有以下性质：

- 每个节点的时间戳唯一
- 父节点的时间戳小于子节点的时间戳
- 时间戳反映了DFS的访问顺序

### 回溯信息(low)

low[u]表示从节点u出发，通过树边或回边能够到达的最早时间戳。计算规则：

```
low[u] = min(
    dfn[u],                    // 节点自身的时间戳
    low[v] for all children v, // 子节点的low值
    dfn[w] for all back edges (u,w) // 回边连接的节点时间戳
)
```

## 算法框架

```cpp
void tarjan(int u, int parent) {
    dfn[u] = low[u] = ++timer;  // 设置时间戳
    stack.push(u);              // 节点入栈
    instack[u] = true;          // 标记节点在栈中

    for (int v : adj[u]) {
        if (v == parent) continue;  // 跳过回父节点的边

        if (!dfn[v]) {  // 如果v未被访问
            tarjan(v, u);           // 递归访问v
            low[u] = min(low[u], low[v]);  // 更新low值
        } else if (instack[v]) {  // 如果v在栈中(回边)
            low[u] = min(low[u], dfn[v]);  // 更新low值
        }
    }

    // 处理连通分量/割点/割边
    if (condition) {
        // 根据具体应用处理
    }
}
```

## Tarjan算法求解强连通分量(SCC)

### 强连通分量定义

在有向图中，如果两个节点u和v之间存在路径u→v和v→u，则称u和v是强连通的。一个强连通分量是图中最大的强连通子图，其中任意两个节点都是强连通的。

### 算法原理

Tarjan算法通过以下步骤识别强连通分量：

1. **DFS遍历**：从任意未访问节点开始DFS
2. **维护栈**：将访问的节点压入栈中
3. **计算low值**：根据子节点和回边更新low值
4. **识别SCC**：当dfn[u] == low[u]时，u是一个SCC的根节点

### 判断条件

节点u是强连通分量的根节点当且仅当：

```
dfn[u] == low[u]
```

此时，栈中从u开始到栈顶的所有节点构成一个强连通分量。

### 代码实现

```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];  // 邻接表
int dfn[N], low[N];  // 时间戳和low值
int timer;           // 时间戳计数器
stack<int> st;       // 栈
bool instack[N];     // 节点是否在栈中
vector<vector<int>> scc;  // 存储所有强连通分量
int scc_id[N];       // 节点所属的SCC编号
int scc_cnt;         // SCC计数器

void tarjan(int u) {
    dfn[u] = low[u] = ++timer;
    st.push(u);
    instack[u] = true;

    for (int v : adj[u]) {
        if (!dfn[v]) {  // 如果v未被访问
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (instack[v]) {  // 如果v在栈中(回边)
            low[u] = min(low[u], dfn[v]);
        }
    }

    // 如果u是SCC的根节点
    if (dfn[u] == low[u]) {
        vector<int> component;
        int v;
        do {
            v = st.top();
            st.pop();
            instack[v] = false;
            component.push_back(v);
            scc_id[v] = scc_cnt;
        } while (v != u);

        scc.push_back(component);
        scc_cnt++;
    }
}

void findSCC(int n) {
    timer = 0;
    scc_cnt = 0;
    memset(dfn, 0, sizeof(dfn));
    memset(instack, false, sizeof(instack));

    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
}

int main() {
    int n, m;  // 节点数和边数
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    findSCC(n);

    cout << "强连通分量数量: " << scc_cnt << endl;
    for (int i = 0; i < scc_cnt; i++) {
        cout << "SCC " << i + 1 << ": ";
        for (int node : scc[i]) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
```

### 缩点应用

强连通分量常用于图的缩点操作：

```cpp
vector<int> condensed_adj[N];  // 缩点后的图
int indegree[N];               // 入度

void buildCondensedGraph(int n) {
    memset(indegree, 0, sizeof(indegree));

    for (int u = 1; u <= n; u++) {
        for (int v : adj[u]) {
            if (scc_id[u] != scc_id[v]) {
                condensed_adj[scc_id[u]].push_back(scc_id[v]);
                indegree[scc_id[v]]++;
            }
        }
    }
}
```

## Tarjan算法求解割点(关节点)

### 割点定义

在无向连通图中，如果删除某个节点u及其所有相关边后，图的连通分量数量增加，则称节点u为割点(或关节点)。

### 算法原理

割点的识别基于以下观察：

1. **根节点特例**：如果根节点有至少两个子节点，则根节点是割点
2. **非根节点判断**：对于非根节点u，如果存在子节点v使得low[v] ≥ dfn[u]，则u是割点

这个条件的直观解释是：如果子节点v不能通过回边到达u的祖先节点，那么删除u会使得v子树与图的其余部分断开连接。

### 判断条件

对于节点u及其子节点v：

```
如果 u 是根节点且子节点数 ≥ 2，则 u 是割点
如果 u 不是根节点且存在子节点 v 使得 low[v] ≥ dfn[u]，则 u 是割点
```

### 代码实现

```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];  // 邻接表
int dfn[N], low[N];  // 时间戳和low值
int timer;           // 时间戳计数器
bool is_cut[N];      // 标记割点
int child_count;     // 子节点计数

void tarjan(int u, int parent) {
    dfn[u] = low[u] = ++timer;

    for (int v : adj[u]) {
        if (v == parent) continue;  // 跳过回父节点的边

        if (!dfn[v]) {  // 如果v未被访问
            if (parent == 0) child_count++;  // 根节点的子节点计数

            tarjan(v, u);
            low[u] = min(low[u], low[v]);

            // 判断割点
            if (parent != 0 && low[v] >= dfn[u]) {
                is_cut[u] = true;
            }
        } else {  // 如果v已被访问(回边)
            low[u] = min(low[u], dfn[v]);
        }
    }
}

void findCutPoints(int n) {
    timer = 0;
    memset(dfn, 0, sizeof(dfn));
    memset(is_cut, false, sizeof(is_cut));

    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            child_count = 0;
            tarjan(i, 0);

            // 根节点特例判断
            if (child_count >= 2) {
                is_cut[i] = true;
            }
        }
    }
}

int main() {
    int n, m;  // 节点数和边数
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);  // 无向图
    }

    findCutPoints(n);

    vector<int> cut_points;
    for (int i = 1; i <= n; i++) {
        if (is_cut[i]) {
            cut_points.push_back(i);
        }
    }

    cout << "割点数量: " << cut_points.size() << endl;
    cout << "割点: ";
    for (int point : cut_points) {
        cout << point << " ";
    }
    cout << endl;

    return 0;
}
```

### 割点与连通分量

割点将图分割成多个连通分量。以下代码可以找出每个割点分割的连通分量：

```cpp
vector<int> components[N];  // 每个割点对应的连通分量

void findComponents(int n) {
    // 首先找出所有割点
    findCutPoints(n);

    // 对每个割点，找出删除它后的连通分量
    for (int u = 1; u <= n; u++) {
        if (is_cut[u]) {
            bool visited[N] = {false};
            visited[u] = true;  // 标记割点为已访问

            for (int v = 1; v <= n; v++) {
                if (!visited[v]) {
                    vector<int> component;
                    dfsComponent(v, visited, component);
                    components[u].push_back(component.size());
                }
            }
        }
    }
}

void dfsComponent(int u, bool visited[], vector<int>& component) {
    visited[u] = true;
    component.push_back(u);

    for (int v : adj[u]) {
        if (!visited[v]) {
            dfsComponent(v, visited, component);
        }
    }
}
```

## Tarjan算法求解割边(桥)

### 割边定义

在无向连通图中，如果删除某条边e后，图的连通分量数量增加，则称边e为割边(或桥)。

### 算法原理

割边的识别基于以下观察：

对于边(u, v)，其中u是v的父节点，如果low[v] > dfn[u]，则边(u, v)是割边。

这个条件的直观解释是：如果子节点v不能通过回边到达u或u的祖先节点，那么边(u, v)是连接v子树与图其余部分的唯一路径，因此是割边。

### 判断条件

对于树边(u, v)：

```
如果 low[v] > dfn[u]，则边(u, v)是割边
```

注意这里是严格大于，而割点的判断是大于等于。

### 代码实现

```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<pair<int, int>> adj[N];  // 邻接表，存储边的信息
int dfn[N], low[N];              // 时间戳和low值
int timer;                       // 时间戳计数器
vector<pair<int, int>> bridges;  // 存储割边

void tarjan(int u, int parent_edge) {
    dfn[u] = low[u] = ++timer;

    for (auto& edge : adj[u]) {
        int v = edge.first;
        int edge_id = edge.second;

        if (edge_id == parent_edge) continue;  // 跳过回父节点的边

        if (!dfn[v]) {  // 如果v未被访问
            tarjan(v, edge_id);
            low[u] = min(low[u], low[v]);

            // 判断割边
            if (low[v] > dfn[u]) {
                bridges.push_back({min(u, v), max(u, v)});
            }
        } else {  // 如果v已被访问(回边)
            low[u] = min(low[u], dfn[v]);
        }
    }
}

void findBridges(int n) {
    timer = 0;
    memset(dfn, 0, sizeof(dfn));
    bridges.clear();

    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            tarjan(i, -1);
        }
    }
}

int main() {
    int n, m;  // 节点数和边数
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});  // 无向图
    }

    findBridges(n);

    // 排序割边
    sort(bridges.begin(), bridges.end());

    cout << "割边数量: " << bridges.size() << endl;
    cout << "割边: " << endl;
    for (auto& bridge : bridges) {
        cout << bridge.first << " - " << bridge.second << endl;
    }

    return 0;
}
```

### 边双连通分量

边双连通分量是图中不包含割边的最大子图。以下代码可以找出所有的边双连通分量：

```cpp
vector<vector<int>> ebcc;      // 存储所有边双连通分量
int ebcc_id[N];                // 节点所属的边双连通分量编号
int ebcc_cnt;                  // 边双连通分量计数器
bool is_bridge[N][N];          // 标记割边

void dfsEBCC(int u, int component_id) {
    ebcc_id[u] = component_id;
    ebcc[component_id - 1].push_back(u);

    for (int v : adj[u]) {
        if (ebcc_id[v] == 0 && !is_bridge[u][v]) {
            dfsEBCC(v, component_id);
        }
    }
}

void findEBCC(int n) {
    // 首先找出所有割边
    findBridges(n);

    // 标记割边
    memset(is_bridge, false, sizeof(is_bridge));
    for (auto& bridge : bridges) {
        is_bridge[bridge.first][bridge.second] = true;
        is_bridge[bridge.second][bridge.first] = true;
    }

    // 找出边双连通分量
    ebcc_cnt = 0;
    memset(ebcc_id, 0, sizeof(ebcc_id));

    for (int i = 1; i <= n; i++) {
        if (ebcc_id[i] == 0) {
            ebcc.push_back(vector<int>());
            dfsEBCC(i, ++ebcc_cnt);
        }
    }
}
```

### 缩点应用

边双连通分量缩点后形成一棵树：

```cpp
vector<int> condensed_adj[N];  // 缩点后的树

void buildCondensedTree(int n) {
    for (int u = 1; u <= n; u++) {
        for (int v : adj[u]) {
            if (ebcc_id[u] != ebcc_id[v]) {
                condensed_adj[ebcc_id[u]].push_back(ebcc_id[v]);
            }
        }
    }
}
```

## 算法复杂度分析

### 时间复杂度

Tarjan算法的时间复杂度为O(V + E)，其中V是图中顶点数，E是边数。这是因为：

1. 每个节点被访问一次
2. 每条边被检查两次（正向和反向）
3. 所有其他操作都是常数时间

### 空间复杂度

空间复杂度为O(V + E)，主要存储：

1. 邻接表：O(E)
2. dfn和low数组：O(V)
3. 栈或其他辅助结构：O(V)

## 应用场景

1. **网络可靠性分析**：识别网络中的关键节点和边
2. **社交网络分析**：发现紧密连接的群体
3. **电路设计**：识别电路中的关键连接
4. **交通规划**：找出交通网络中的关键路段

## 常见问题与技巧

1. **处理重边**：在无向图中，重边会影响割边的判断，需要特殊处理
2. **处理自环**：自环通常不影响连通性分析
3. **多组输入**：注意清空数组和重置变量
4. **输出顺序**：某些题目要求特定的输出顺序，需要排序
   
   

# 集合

确定性：给定一个集合，任给一个元素，该元素或者属于或者不属于该集合，二者必居其一，不允许有模棱两可的情况出现。

互异性：一个集合中，任何两个元素都认为是不相同的，即每个元素只能出现一次。有时需要对同一元素出现多次的情形进行刻画，可以使用多重集，其中的元素           允许出现多次。

无序性：一个集合中，每个元素的地位都是相同的，元素之间是无序的。集合上可以定义序关系，定义了序关系后，元素之间就可以按照序关系排序。但就集合本        身的特性而言，元素之间没有必然的序。
$$
\in\ \notin
$$

## 交并集

**交集定义**：由属于A且属于B的相同元素组成的集合，记作(或B∩A），读作“A交B”（或“B交A”），即A∩B={x|x∈A,且x∈B}， 如图1所示。注意交集越交越少。若A包含B，则$A∩B=B，A∪B=A$。

**并集定义**：由所有属于集合A或属于集合B的元素所组成的集合，记作$A \cup B$（$或B∪A$），读作“A并B”（或“B并A”），即$A∪B={x|x∈A,或x∈B}，如图1所示。注意并集越并越多，这与交集的情况正相反

### 三集合容斥原理

$$
a\cup b\cup c = a + b +c-a\cap b -b\cap c-a \cap c + a\cap b \cap c
$$

<img src="https://bkimg.cdn.bcebos.com/pic/d000baa1cd11728b1ab6e504c5fcc3cec3fd2c78?x-bce-process=image/format,f_auto/watermark,image_d2F0ZXIvYmFpa2UyNzI,g_7,xp_5,yp_5,P_20/resize,m_lfit,limit_1,h_1080" alt="img" style="zoom:50%;" />

---

“抽屉”通常指结果的所有可能性的数量



# 二分查找`STL`

1.`binary_search()` 

使用方法为：`binary_search(数组名,数组名+数据个数,找的数);`

返回 true or false

PS:区间为左闭右开

2.`lower_bound()`

使用方法为与`bs`一样

`lower_bound(数组名,数组名+数据个数,找的数) - 数组名`c++就是找的数的左边界

### 去重

1.`unique`

`unique(数组名，数组名+数据个数) - 数组名`就是最后一个没有重复的数据位置的后一个的**指针**，所以要减去数组名得到没有重复数据的数据个数

2.顺序查找

```c++
sort(a, a+n);
cout << a[0] << " ";
for (int i = 0; i < n; i++) {
    if (a[i] != a[i-1]) {
        cout<<a[i]<<" ";
    }
}
```

3.`set`

```c++
set<int> st;
for (int i = 0; i < n; i++) {
    st.insert(a[i]);
}
for (auto it = st.begin(); it != st.end(); it++) {
    cout<<*it;
}
```



# 深搜迷宫问题类型

| 问题类型 | 洪水填充 | 是否可达       | 最小步数 | 路径数量         | 最小路径成本  | 最小成本路径成本 |
|:----:|:----:|:----------:|:----:|:------------:|:-------:|:--------:|
| 回溯   | ✅    | ❌          | ✅    | ✅            | ✅       | ✅        |
| 剪枝   | ❌    | ❌          | ✅    | ❌            | ✅       | ✅        |
| 边界条件 | 自然终止 | 达到终点       | 到达终点 | 到达终点         | 到达终点    | 到达终点     |
| 边界处理 | 无    | `exit(0);` | 打擂台  | 复制栈数据 or 打擂台 | 累加和的最小值 | 复制栈数据    |

## DFS欧拉序

### 概念介绍

欧拉序（Euler Tour）是DFS遍历树的一种记录方式，记录了DFS过程中访问节点的顺序。欧拉序有两种常见的形式：

1. **节点进入序列**：记录每个节点第一次被访问的时间戳
2. **完整遍历序列**：记录每次进入和离开节点的时间戳

欧拉序在许多树相关问题中非常有用，如LCA（最近公共祖先）查询、子树操作等。

### 算法原理

在DFS遍历树的过程中，我们记录：

- 进入节点时的时间戳（in时间）
- 离开节点时的时间戳（out时间）

对于树中的每个节点，其子树中的所有节点在欧拉序中是连续的，这一性质使得欧拉序在处理子树问题时非常高效。

### 代码实现

```cpp
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 5;

vector<int> g[N];  // 邻接表存储树
int in[N];         // 进入时间戳
int out[N];        // 离开时间戳
int euler[N * 2];  // 欧拉序序列（完整遍历序列）
int node_in[N];    // 节点进入序列
int timer;         // 时间戳计数器
int euler_idx;     // 欧拉序索引

// DFS遍历生成欧拉序
void dfs(int u, int parent) {
    // 记录进入时间戳
    in[u] = ++timer;
    node_in[timer] = u;  // 节点进入序列：第timer个访问的节点是u

    // 完整欧拉序：记录进入节点
    euler[++euler_idx] = u;

    // 递归访问所有子节点
    for (int v : g[u]) {
        if (v != parent) {  // 避免回边
            dfs(v, u);
            // 完整欧拉序：从子节点返回后再次记录当前节点
            euler[++euler_idx] = u;
        }
    }

    // 记录离开时间戳
    out[u] = timer;
}

// 判断节点u是否是节点v的祖先
bool is_ancestor(int u, int v) {
    // u是v的祖先当且仅当in[u] <= in[v]且out[u] >= out[v]
    return in[u] <= in[v] && out[u] >= out[v];
}

// 获取节点u的子树在欧拉序中的区间
pair<int, int> get_subtree_range(int u) {
    // 子树节点在节点进入序列中是连续的
    return {in[u], out[u]};
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;  // 节点数
    cin >> n;

    // 读取树的边（假设是1号节点为根的无向树）
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // 从根节点开始DFS
    timer = 0;
    euler_idx = 0;
    dfs(1, 0);

    // 输出节点进入序列
    cout << "节点进入序列: ";
    for (int i = 1; i <= n; i++) {
        cout << node_in[i] << " ";
    }
    cout << endl;

    // 输出完整欧拉序
    cout << "完整欧拉序: ";
    for (int i = 1; i <= euler_idx; i++) {
        cout << euler[i] << " ";
    }
    cout << endl;

    // 输出每个节点的进入和离开时间戳
    cout << "节点时间戳:\n";
    for (int i = 1; i <= n; i++) {
        cout << "节点" << i << ": in=" << in[i] << ", out=" << out[i] << endl;
    }

    // 示例：判断祖先关系
    int u, v;
    cout << "输入两个节点判断祖先关系: ";
    cin >> u >> v;
    if (is_ancestor(u, v)) {
        cout << u << " 是 " << v << " 的祖先" << endl;
    } else {
        cout << u << " 不是 " << v << " 的祖先" << endl;
    }

    // 示例：获取子树区间
    cout << "输入节点获取其子树区间: ";
    cin >> u;
    auto range = get_subtree_range(u);
    cout << "节点" << u << "的子树在欧拉序中的区间: [" 
         << range.first << ", " << range.second << "]" << endl;

    return 0;
}
```

### 应用场景

1. **LCA查询**：结合RMQ（区间最小值查询）可以在O(1)时间内回答LCA查询
2. **子树操作**：利用子树在欧拉序中的连续性，可以高效处理子树查询和更新
3. **路径查询**：某些路径问题可以转化为欧拉序上的区间问题
4. **树的动态统计**：结合树状数组或线段树，可以处理动态的树操作

### 复杂度分析

- **时间复杂度**：O(N)，其中N是树的节点数
- **空间复杂度**：O(N)，用于存储欧拉序和时间戳数组

### 示例：子树和查询

```cpp
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 5;

vector<int> g[N];
vector<ll> values(N);  // 节点值
int in[N], out[N];
int node_in[N];
int timer;
ll prefix_sum[N * 2];  // 前缀和数组

void dfs(int u, int parent) {
    in[u] = ++timer;
    node_in[timer] = u;

    for (int v : g[u]) {
        if (v != parent) {
            dfs(v, u);
        }
    }

    out[u] = timer;
}

// 预处理前缀和
void preprocess_prefix_sum() {
    for (int i = 1; i <= timer; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + values[node_in[i]];
    }
}

// 查询子树和
ll query_subtree_sum(int u) {
    return prefix_sum[out[u]] - prefix_sum[in[u] - 1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, q;  // 节点数和查询数
    cin >> n >> q;

    // 读取节点值
    for (int i = 1; i <= n; i++) {
        cin >> values[i];
    }

    // 读取树的边
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // DFS生成欧拉序
    timer = 0;
    dfs(1, 0);

    // 预处理前缀和
    preprocess_prefix_sum();

    // 处理查询
    while (q--) {
        int type, u;
        cin >> type >> u;

        if (type == 1) {  // 更新节点值
            ll new_val;
            cin >> new_val;
            ll diff = new_val - values[u];
            values[u] = new_val;

            // 更新前缀和（实际应用中可能需要使用树状数组或线段树）
            for (int i = in[u]; i <= timer; i++) {
                prefix_sum[i] += diff;
            }
        } else if (type == 2) {  // 查询子树和
            cout << query_subtree_sum(u) << endl;
        }
    }

    return 0;
}
```

### 总结

DFS欧拉序是处理树问题的强大工具，它将树的结构转化为线性结构，使得许多复杂的树操作可以通过简单的区间操作来实现。掌握欧拉序对于解决信奥竞赛中的树相关问题非常有帮助。


# 倍增思想

## 基本概念

倍增（Doubling）是一种重要的算法思想，其核心思想是**利用二进制拆分的思想，预处理出2的幂次方的信息，从而加速查询**。

### 为什么叫"倍增"

"倍增"来源于每次跳转的距离都是2的幂次方：1, 2, 4, 8, 16, 32... 这样我们可以通过组合这些2的幂次方来快速到达目标位置。

### 核心思想

1. **预处理阶段**：提前计算每个点向上跳2^k步到达的祖先节点
2. **查询阶段**：通过二进制分解，组合不同的2^k跳跃来快速到达目标

### 为什么要用倍增

考虑一个简单的问题：从节点u向上跳k步，会到达哪个节点？

**朴素做法**：一步一步向上跳，时间复杂度O(k)

**倍增做法**：将k表示为二进制，比如k=13=8+4+1，只需跳3次，时间复杂度O(log k)

## 应用场景

倍增思想广泛应用于：

1. **LCA（最近公共祖先）**：快速查询两个节点的最近公共祖先
2. **树上路径查询**：快速查询树上两点间的路径信息
3. **RMQ（区间最值查询）**：快速查询区间最大值/最小值
4. **K-th ancestor**：快速查找节点的第k个祖先

## 倍增预处理

### 数据结构设计

```
const int N = 1e5 + 5;
const int LOGN = 20;  // 2^20 > 1e5，足够覆盖

vector<int> adj[N];   // 邻接表
int depth[N];         // 节点深度
int parent[N][LOGN];  // parent[u][k]表示节点u向上跳2^k步的祖先
```


### 预处理过程


```cpp
void dfs(int u, int p, int d) {
    // 记录深度
    depth[u] = d;
    
    // parent[u][0]是u的直接父节点
    parent[u][0] = p;
    
    // 预处理倍增信息
    // parent[u][k] = parent[parent[u][k-1]][k-1]
    // 即：向上跳2^k步 = 向上跳2^(k-1)步，再向上跳2^(k-1)步
    for (int k = 1; k < LOGN; k++) {
        if (parent[u][k-1] != -1) {
            parent[u][k] = parent[parent[u][k-1]][k-1];
        }
    }
    
    // 递归处理子节点
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u, d + 1);
        }
    }
}
```

### 向上跳k步的实现

```cpp
// 从节点u向上跳k步，返回到达的节点
int jump_up(int u, int k) {
    for (int i = 0; i < LOGN; i++) {
        // 如果k的第i位是1，就向上跳2^i步
        if ((k >> i) & 1) {
            u = parent[u][i];
            if (u == -1) return -1;  // 超出树的范围
        }
    }
    return u;
}
```


## 复杂度分析

- **预处理时间复杂度**：O(N log N)，每个节点预处理log N层
- **预处理空间复杂度**：O(N log N)，存储parent数组
- **单次查询时间复杂度**：O(log N)

---

# 倍增求LCA（最近公共祖先）

## LCA定义

在树中，两个节点u和v的最近公共祖先（Lowest Common Ancestor，LCA）是指：

1. 既是u的祖先，也是v的祖先
2. 在所有满足条件1的节点中，深度最大（最接近u和v）

**直观理解**：从u和v同时向根节点走，第一个相遇的节点就是LCA

## 倍增求LCA的原理

### 核心思路

倍增求LCA分为三个步骤：

1. **预处理**：用DFS预处理每个节点的深度和2^k祖先
2. **调整深度**：将深度较大的节点向上跳，使两个节点深度相同
3. **同时上跳**：两个节点同时从高位到低位向上跳，找到LCA

### 详细步骤

**Step 1: 预处理**

```cpp
void dfs(int u, int p, int d) {
    depth[u] = d;
    parent[u][0] = p;
    
    for (int k = 1; k < LOGN; k++) {
        if (parent[u][k-1] != -1) {
            parent[u][k] = parent[parent[u][k-1]][k-1];
        }
    }
    
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u, d + 1);
        }
    }
}
```

**Step 2: 调整深度**

如果两个节点深度不同，先将深度较大的节点向上跳，使深度相同。

```cpp
// 将节点u调整到与节点v相同的深度
void adjust_depth(int &u, int d) {
    int diff = depth[u] - d;
    for (int i = 0; i < LOGN; i++) {
        if ((diff >> i) & 1) {
            u = parent[u][i];
        }
    }
}
```

**Step 3: 同时上跳**

两个节点同时从高位到低位向上跳，如果跳2^k步后不是同一个节点，就跳；否则不跳。

最后两个节点的父节点就是LCA。

```cpp
int lca(int u, int v) {
    // Step 1: 确保u的深度大于等于v
    if (depth[u] < depth[v]) {
        swap(u, v);
    }
    
    // Step 2: 将u调整到与v相同的深度
    adjust_depth(u, depth[v]);
    
    // Step 3: 如果调整后u就是v，直接返回
    if (u == v) return u;
    
    // Step 4: 从高位到低位尝试上跳
    for (int k = LOGN - 1; k >= 0; k--) {
        // 如果跳2^k步后不是同一个节点，就跳
        if (parent[u][k] != parent[v][k]) {
            u = parent[u][k];
            v = parent[v][k];
        }
    }
    
    // 此时u和v都是LCA的子节点，它们的父节点就是LCA
    return parent[u][0];
}
```

## 完整代码实现

```cpp
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,m;
ll fa[N]; // 存储每个节点的父节点
ll dep[N],up[15][N]; // dep存储节点深度, up用于存储倍增数组（二进制跳跃的祖先节点）

// DFS初始化倍增数组和节点深度
// 重难点：倍增数组的构建（预处理每个节点的2^k级祖先）
void dfs(ll x,ll f){
    dep[x]=dep[f]+1; // 当前节点深度为父节点深度+1
    up[0][x]=f; // 初始化2^0级祖先（直接父节点）

    // 倍增数组的构建：利用递推关系 up[i][x] = up[i-1][up[i-1][x]]
    // 即x的2^i级祖先等于x的2^(i-1)级祖先的2^(i-1)级祖先
    for(int i=1;i<10;i++) up[i][x]=up[i-1][up[i-1][x]];

    // 递归遍历子节点
    for(int i=2;i<=n;i++) if(fa[i]==x) dfs(i,x);
}

// LCA查询函数（最近公共祖先）
// 重难点：利用倍增数组实现二进制跳跃，快速找到LCA
ll LCA(ll u,ll v){
    // 确保u的深度大于等于v
    if(dep[u]<dep[v]) swap(v,u);

    // 将u向上跳跃至与v同一深度
    // 从最高位开始尝试跳跃，能跳则跳
    for(int i=9;i>=0;i--){
        if(dep[up[i][u]]>=dep[v]){
            u=up[i][u];
        }
    }

    // 如果u和v相等，说明v就是u的祖先，直接返回
    if(u==v) return u;

    // 同时向上跳跃u和v，直到它们的父节点相同
    // 从最高位开始尝试跳跃，能跳则跳（但不跳到相同节点）
    for(int k=9;k>=0;k--){
        if(up[k][u]!=up[k][v]){
            u=up[k][u];
            v=up[k][v];
        }
    }

    // 最终u和v的父节点即为LCA
    return up[0][u];
}

void solve(){
    cin>>n>>m;
    for(int i=2;i<=n;i++) cin>>fa[i]; // 读取每个节点的父节点
    fa[1]=0; // 根节点的父节点设为0
    dfs(1,0); // 从根节点开始DFS，初始化倍增数组和深度

    // 处理m次查询
    for(int i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        cout<<LCA(x,y)<<el; // 输出x和y的LCA
    }
}

int main(){
    ll T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
```

### 算法过程解析

以查询LCA(4, 5)为例：

1. **预处理阶段**：
   - ``depth[1] = 0, depth[2] = 1, depth[3] = 1``
   - ``depth[4] = 2, depth[5] = 2, depth[6] = 2, depth[7] = 2``
   - ``parent[4][0] = 2, parent[5][0] = 2, parent[6][0] = 3, parent[7][0] = 3``

2. **查询阶段**：
   - ``depth[4] = 2, depth[5] = 2``，深度相同，无需调整
   - 从高位到低位尝试上跳：
     - ``k=1: parent[4][1] = 1, parent[5][1] = 1``，相同，不跳
     - `` k=0: parent[4][0] = 2, parent[5][0] = 2``，相同，不跳
   - 最后返回``parent[4][0] = parent[5][0] = 2``

## 复杂度分析

### 时间复杂度

- **预处理阶段**：O(N log N)
  - DFS遍历所有节点：$O(N)$
  - 每个节点预处理log N层：O(N log N)

- **单次查询**：O(log N)
  - 调整深度：O(log N)
  - 同时上跳：O(log N)

- **总复杂度**：O((N + Q) log N)，其中Q是查询次数

### 空间复杂度

- **存储空间**：O(N log N)
  - 邻接表：O(N)
  - depth数组：O(N)
  - parent数组：O(N log N)

## 与其他LCA算法的对比

|   算法    |   预处理时间    |  单次查询时间  |   空间复杂度    | 实现难度 |
| :-----: | :--------: | :------: | :--------: | :--: |
|   倍增    | O(N log N) | O(log N) | O(N log N) |  中等  |
| Tarjan  |    O(N)    |   O(1)   |    O(N)    |  困难  |
| RMQ+欧拉序 |    O(N)    |   O(1)   |    O(N)    |  中等  |
|  树链剖分   |    O(N)    | O(log N) |    O(N)    |  困难  |

## 应用扩展

### 1. 树上路径和查询

```cpp
// 求树上两点路径上节点权值的和
int path_sum(int u, int v, vector<int>& val, vector<int>& prefix) {
    int ancestor = lca(u, v);
    return prefix[u] + prefix[v] - 2 * prefix[ancestor] + val[ancestor];
}
```

### 2. 树上第k个祖先

```cpp
// 求节点u的第k个祖先
int kth_ancestor(int u, int k) {
    for (int i = 0; i < LOGN; i++) {
        if ((k >> i) & 1) {
            u = parent[u][i];
            if (u == -1) return -1;
        }
    }
    return u;
}
```

### 3. 树上两点路径上的第k个节点

```cpp
// 求u到v路径上的第k个节点
int kth_node_on_path(int u, int v, int k) {
    int ancestor = lca(u, v);
    int d1 = depth[u] - depth[ancestor];
    int d2 = depth[v] - depth[ancestor];
    
    if (k <= d1 + 1) {
        // 第k个节点在u到LCA的路径上
        return kth_ancestor(u, k - 1);
    } else {
        // 第k个节点在LCA到v的路径上
        return kth_ancestor(v, d1 + d2 - k + 1);
    }
}
```

## 常见错误与注意事项

1. **LOG(N)的大小**：
   - LOGN应该设置为⌈log₂(N)⌉+1，确保覆盖所有可能的跳跃
   - 对于N=1e5，LOGN=20就足够了

2. **根节点的处理**：
   - 根节点的parent[1][0]应该设置为-1
   - 在DFS时要注意检查parent[u][k-1]是否为-1

3. **查询时的边界情况**：
   - 当u是v的祖先时，lca(u, v)应该返回u
   - 代码中的if (u == v) return u;处理了这种情况

4. **从高位到低位遍历**：
   - 在同时上跳时，必须从高位到低位遍历
   - 这样可以确保找到最深的公共祖先

## 总结

倍增求LCA是一种经典且高效的算法，具有以下优点：

1. **效率高**：预处理O(N log N)，查询O(log N)
2. **易于实现**：代码逻辑清晰，容易理解和调试
3. **适用范围广**：不仅可以求LCA，还可以解决树上路径查询等问题
4. **扩展性强**：可以结合其他算法解决更复杂的问题

掌握倍增思想对于解决信奥竞赛中的树相关问题非常重要，建议多练习相关题目以熟练掌握。

# RMQ问题（区间最值查询）

## 什么是RMQ问题？

RMQ是Range Minimum Query（区间最小值查询）或Range Maximum Query（区间最大值查询）的缩写。简单来说，就是在一个数组中，快速地找到某个区间内的最小值或最大值。

### 一个简单的例子

假设有一个数组：`[3, 1, 4, 1, 5, 9, 2, 6]`

如果我们想知道区间 `[2, 5]`（从索引2到索引5）的最大值，那么答案是 `9`。

如果用朴素做法，我们需要遍历这个区间，时间复杂度是 `O(区间长度)`。但如果查询很多次，效率就很低了。

### RMQ问题的特点

1. **数组是静态的**：数组中的值不会改变（没有修改操作）
2. **查询次数很多**：需要回答很多次区间查询
3. **要求快速响应**：每次查询的时间要非常短

## 朴素做法的问题

```cpp
#include <iostream>
#include <vector>
using namespace std;

// 朴素做法：每次查询都遍历整个区间
int naiveRMQ(vector<int>& arr, int l, int r) {
    int maxVal = arr[l];
    for (int i = l + 1; i <= r; i++) {
        maxVal = max(maxVal, arr[i]);
    }
    return maxVal;
}

int main() {
    vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6};
    
    // 查询区间[2, 5]的最大值
    cout << "区间[2, 5]的最大值: " << naiveRMQ(arr, 2, 5) << endl;  // 输出: 9
    
    return 0;
}
```

**问题**：每次查询都要遍历整个区间，如果查询很多次，总时间复杂度是 `O(查询次数 × 区间长度)`，太慢了！

---

# ST表（Sparse Table）

## ST表是什么？

ST表（Sparse Table，稀疏表）是解决RMQ问题的一种高效数据结构。它的核心思想是**预处理**：提前计算出各种可能的区间信息，然后用倍增的思想快速查询。

### 为什么叫"稀疏表"？

因为ST表存储的是一些"稀疏"的区间信息，不是所有可能的长度的区间都存储，而是只存储长度为 `2^k` 的区间信息。

### ST表的核心思想

1. **预处理阶段**：计算所有长度为 `2^k` 的区间的最大值/最小值
2. **查询阶段**：将查询区间分解为两个 `2^k` 的区间，取它们的最值

### ST表与倍增的关系

ST表和倍增算法有着密切的关系：

1. **相同的思想基础**：都基于二进制分解和倍增思想
2. **相同的时间复杂度**：预处理都是O(n × log n)，查询都是O(1)或O(log n)
3. **不同的应用场景**：
   - 倍增：主要用于树上路径查询（如LCA）
   - ST表：主要用于静态数组的区间查询

### 为什么选择预处理所有 `2^k` 长度的区间？

这是一个很好的问题！让我们详细分析一下：

#### 原因1：覆盖所有可能的查询

任何查询区间的长度都可以表示为若干个 `2^k` 的和，因此预处理所有 `2^k` 长度的区间可以覆盖所有可能的查询。

#### 原因2：快速计算

预处理 `2^k` 长度的区间可以利用递推关系：
- `2^k` 长度的区间 = 两个 `2^(k-1)` 长度的区间
- 这种递推关系使得预处理可以高效完成

#### 原因3：查询简单

查询时只需要找到合适的 `k` 值，然后用两个预处理好的区间覆盖查询区间。

### 为什么不预处理所有可能长度的区间？

这是一个很好的问题！让我们比较一下：

#### 方案1：预处理所有可能长度的区间

- 预处理时间：O(n²)
- 空间复杂度：O(n²)
- 查询时间：O(1)

#### 方案2：预处理 `2^k` 长度的区间（ST表）

- 预处理时间：O(n × log n)
- 空间复杂度：O(n × log n)
- 查询时间：O(1)

#### 为什么选择方案2？

1. **预处理时间更短**：O(n × log n) < O(n²)
2. **空间更省**：O(n × log n) < O(n²)
3. **查询时间相同**：都是O(1)
4. **实现简单**：利用递推关系，容易实现

### 倍增思想的本质

倍增思想的本质是：**将复杂的操作分解为多个简单操作的组合**。

具体来说：

1. **预处理阶段**：提前计算各种可能的基本操作
2. **查询阶段**：将复杂操作分解为基本操作的组合

#### 在ST表中的应用：

1. **预处理**：计算所有 `2^k` 长度的区间的最值
2. **查询**：将任意长度的查询区间分解为两个 `2^k` 的区间

#### 在LCA中的应用：

1. **预处理**：计算每个节点向上跳 `2^k` 步的祖先
2. **查询**：将任意跳跃距离分解为多个 `2^k` 的跳跃

### 为什么是 `2` 的幂次方？

`2` 的幂次方在计算机中有很多优势：

1. **二进制友好**：计算机使用二进制，`2` 的幂次方可以用移位运算快速计算
2. **分解方便**：任何整数都可以表示为 `2` 的幂次方的和
3. **递推简单**：`2^k` 可以通过 `2^(k-1)` 快速得到

#### 如果不使用 `2` 的幂次方会怎样？

假设我们预处理所有长度为 `3^k` 的区间：

1. **预处理时间**：仍然是 O(n × log₃ n)
2. **查询时间**：可能需要更多次查表（因为分解更复杂）
3. **实现复杂**：递推关系更复杂，不如 `2` 的幂次方方便

### ST表的预处理细节

让我们更详细地看看预处理的过程：

#### 预处理的三个步骤

**第一步：初始化log2数组**

```cpp
log2[1] = 0;  // 2^0 = 1
log2[2] = 1;  // 2^1 = 2
log2[3] = 1;  // 2^1 = 2 < 3 < 2^2 = 4
log2[4] = 2;  // 2^2 = 4
log2[5] = 2;  // 2^2 = 4 < 5 < 2^3 = 8
// ...
```

**为什么需要log2数组？**

因为查询时需要快速找到最大的 `k` 使得 `2^k <= 区间长度`，log2数组提供了这个功能。

**第二步：初始化st表（j=0，长度为1）**

```cpp
for (int i = 0; i < n; i++) {
    st[i][0] = arr[i];  // 长度为1的区间，最大值就是arr[i]本身
}
```

**第三步：递推计算st表（j>0）**

```cpp
for (int j = 1; (1 << j) <= n; j++) {        // 枚举2的幂次
    for (int i = 0; i + (1 << j) <= n; i++) {  // 枚举起始位置
        // 长度为2^j的区间可以分为两个长度为2^(j-1)的区间
        // 区间1：[i, i + 2^(j-1) - 1]
        // 区间2：[i + 2^(j-1), i + 2^j - 1]
        st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }
}
```

**为什么要这样递推？**

因为 `2^j = 2 × 2^(j-1)`，所以长度为 `2^j` 的区间可以完美地分成两个长度为 `2^(j-1)` 的区间。

## ST表的预处理

### 数据结构设计

```cpp
const int N = 1e5 + 5;
const int LOGN = 20;  // 2^20 > 1e5，足够覆盖

int st[N][LOGN];  // st[i][j]表示从位置i开始，长度为2^j的区间的最大值
int log2[N];      // log2[i]表示i的以2为底的对数的整数部分
```

### 预处理过程

```cpp
void build(vector<int>& arr, int n) {
    // 第一步：初始化log2数组
    log2[1] = 0;
    for (int i = 2; i <= n; i++) {
        log2[i] = log2[i / 2] + 1;  // 利用递推关系计算log2
    }
    
    // 第二步：初始化st表
    // 长度为2^0 = 1的区间，最大值就是arr[i]本身
    for (int i = 0; i < n; i++) {
        st[i][0] = arr[i];
    }
    
    // 第三步：递推计算st表
    // st[i][j] = max(st[i][j-1], st[i + 2^(j-1)][j-1])
    // 意思是：长度为2^j的区间，可以分成两个长度为2^(j-1)的区间
    for (int j = 1; (1 << j) <= n; j++) {        // 枚举2的幂次
        for (int i = 0; i + (1 << j) <= n; i++) {  // 枚举起始位置
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}
```

### 预处理过程详解

假设数组是 `[3, 1, 4, 1, 5, 9, 2, 6]`，长度为8。

**第一步：计算log2数组**
```
log2[1] = 0
log2[2] = 1
log2[3] = 1
log2[4] = 2
log2[5] = 2
log2[6] = 2
log2[7] = 2
log2[8] = 3
```

**第二步：初始化st表（j=0，长度为1）**
```
st[0][0] = 3  (区间[0,0])
st[1][0] = 1  (区间[1,1])
st[2][0] = 4  (区间[2,2])
st[3][0] = 1  (区间[3,3])
st[4][0] = 5  (区间[4,4])
st[5][0] = 9  (区间[5,5])
st[6][0] = 2  (区间[6,6])
st[7][0] = 6  (区间[7,7])
```

**第三步：计算st表（j=1，长度为2）**
```
st[0][1] = max(st[0][0], st[1][0]) = max(3, 1) = 3  (区间[0,1])
st[1][1] = max(st[1][0], st[2][0]) = max(1, 4) = 4  (区间[1,2])
st[2][1] = max(st[2][0], st[3][0]) = max(4, 1) = 4  (区间[2,3])
st[3][1] = max(st[3][0], st[4][0]) = max(1, 5) = 5  (区间[3,4])
st[4][1] = max(st[4][0], st[5][0]) = max(5, 9) = 9  (区间[4,5])
st[5][1] = max(st[5][0], st[6][0]) = max(9, 2) = 9  (区间[5,6])
st[6][1] = max(st[6][0], st[7][0]) = max(2, 6) = 6  (区间[6,7])
```

**第四步：计算st表（j=2，长度为4）**
```
st[0][2] = max(st[0][1], st[2][1]) = max(3, 4) = 4  (区间[0,3])
st[1][2] = max(st[1][1], st[3][1]) = max(4, 5) = 5  (区间[1,4])
st[2][2] = max(st[2][1], st[4][1]) = max(4, 9) = 9  (区间[2,5])
st[3][2] = max(st[3][1], st[5][1]) = max(5, 9) = 9  (区间[3,6])
st[4][2] = max(st[4][1], st[6][1]) = max(9, 6) = 9  (区间[4,7])
```

**第五步：计算st表（j=3，长度为8）**
```
st[0][3] = max(st[0][2], st[4][2]) = max(4, 9) = 9  (区间[0,7])
```

## ST表的查询

### 查询原理

对于查询区间 `[l, r]`，我们需要找到一个最大的 `k`，使得 `2^k <= (r - l + 1)`。

然后将区间 `[l, r]` 分解为两个长度为 `2^k` 的区间：
- 区间1：`[l, l + 2^k - 1]`
- 区间2：`[r - 2^k + 1, r]`

这两个区间会覆盖整个查询区间，并且可能有重叠，但重叠不影响最大值/最小值的查询。

### 查询代码

```cpp
// 查询区间[l, r]的最大值
int query(int l, int r) {
    int k = log2[r - l + 1];  // 计算最大的k，使得2^k <= 区间长度
    // st[l][k] 表示从l开始，长度为2^k的区间的最大值
    // st[r - (1 << k) + 1][k] 表示从r - 2^k + 1开始，长度为2^k的区间的最大值
    return max(st[l][k], st[r - (1 << k) + 1][k]);
}
```

### 查询过程详解

假设我们要查询区间 `[2, 5]`（即索引2到索引5）的最大值。

**第一步：计算区间长度**
```
区间长度 = r - l + 1 = 5 - 2 + 1 = 4
```

**第二步：计算k的值**
```
k = log2[4] = 2
```

**第三步：分解区间**
```
区间1：[2, 2 + 2^2 - 1] = [2, 5]  → st[2][2] = 9
区间2：[5 - 2^2 + 1, 5] = [2, 5]  → st[2][2] = 9
```

**第四步：取最大值**
```
max(st[2][2], st[2][2]) = max(9, 9) = 9
```

所以区间 `[2, 5]` 的最大值是 `9`。

### 另一个例子：查询区间 `[1, 6]`

**第一步：计算区间长度**
```
区间长度 = 6 - 1 + 1 = 6
```

**第二步：计算k的值**
```
k = log2[6] = 2  （因为2^2 = 4 <= 6，而2^3 = 8 > 6）
```

**第三步：分解区间**
```
区间1：[1, 1 + 2^2 - 1] = [1, 4]  → st[1][2] = 5
区间2：[6 - 2^2 + 1, 6] = [3, 6]  → st[3][2] = 9
```

**第四步：取最大值**
```
max(st[1][2], st[3][2]) = max(5, 9) = 9
```

所以区间 `[1, 6]` 的最大值是 `9`。

### 查询过程的详细分析

#### 为什么查询是O(1)的？

查询过程包括以下步骤：

1. **计算区间长度**：`r - l + 1` —— O(1)
2. **查找k值**：`log2[r - l + 1]` —— O(1)（查表）
3. **第一次查表**：`st[l][k]` —— O(1)
4. **第二次查表**：`st[r - (1 << k) + 1][k]` —— O(1)
5. **取最大值**：`max(...)` —— O(1)

所有步骤都是O(1)的，所以总时间是O(1)。

#### 为什么两个区间一定能覆盖查询区间？

设查询区间长度为 `len = r - l + 1`，我们找到最大的 `k` 使得 `2^k <= len`。

那么：
- `2^k >= len/2`（因为 `2^k` 是不超过 `len` 的最大的 `2` 的幂次方）
- 两个长度为 `2^k` 的区间可以覆盖长度为 `2 * 2^k >= len` 的区间

因此，两个长度为 `2^k` 的区间一定能覆盖长度为 `len` 的查询区间。

#### 为什么重叠不影响结果？

假设查询区间 `[l, r]` 的最大值是 `maxVal`。

那么 `maxVal` 一定在区间1 `[l, l + 2^k - 1]` 或区间2 `[r - 2^k + 1, r]` 中。

因此，`max(st[l][k], st[r - (1 << k) + 1][k])` 一定等于 `maxVal`。

即使两个区间有重叠，也不会影响最大值的查询结果。

#### 为什么不能只用一个区间？

因为查询区间的长度 `len` 可能不是 `2` 的幂次方。

如果只用一个长度为 `2^k` 的区间，可能无法完全覆盖查询区间。

例如，查询区间长度为 `6`，最大的 `k` 是 `2`（因为 `2^2 = 4 <= 6 < 2^3 = 8`）。

如果只用一个长度为 `4` 的区间，无法覆盖长度为 `6` 的查询区间。

#### 为什么只需要两个区间？

因为 `2^k >= len/2`，所以两个长度为 `2^k` 的区间可以覆盖长度为 `len` 的查询区间。

如果用三个区间，虽然也能覆盖，但会增加查询时间和代码复杂度。

#### 为什么区间2的起点是 `r - 2^k + 1`？

区间2的起点是 `r - 2^k + 1`，长度是 `2^k`，所以区间2的范围是 `[r - 2^k + 1, r]`。

这样区间2和区间1 `[l, l + 2^k - 1]` 一起覆盖整个查询区间 `[l, r]`。

#### 为什么不是 `l + len - 2^k`？

因为 `len = r - l + 1`，所以 `l + len - 2^k = l + r - l + 1 - 2^k = r - 2^k + 1`。

因此，`l + len - 2^k` 和 `r - 2^k + 1` 是等价的。

### 查询的边界情况处理

#### 情况1：查询区间为单个元素

```cpp
// 查询区间 [3, 3]
int result = query(3, 3);
```

**分析**：
- 区间长度 = 1
- k = log2[1] = 0
- 区间1：[3, 3] → st[3][0] = arr[3]
- 区间2：[3, 3] → st[3][0] = arr[3]
- 结果：max(arr[3], arr[3]) = arr[3]

#### 情况2：查询区间长度为2的幂次方

```cpp
// 查询区间 [0, 7]，长度为8
int result = query(0, 7);
```

**分析**：
- 区间长度 = 8
- k = log2[8] = 3
- 区间1：[0, 7] → st[0][3]
- 区间2：[0, 7] → st[0][3]
- 结果：max(st[0][3], st[0][3]) = st[0][3]

#### 情况3：查询区间长度接近2的幂次方

```cpp
// 查询区间 [0, 6]，长度为7
int result = query(0, 6);
```

**分析**：
- 区间长度 = 7
- k = log2[7] = 2（因为2^2 = 4 <= 7 < 2^3 = 8）
- 区间1：[0, 3] → st[0][2]
- 区间2：[3, 6] → st[3][2]
- 结果：max(st[0][2], st[3][2])

### 查询的时间复杂度分析

#### 时间复杂度：O(1)

虽然查询看起来有很多步骤，但每一步都是O(1)的：

1. **计算区间长度**：一次减法和加法 —— O(1)
2. **查找k值**：查表 —— O(1)
3. **计算数组索引**：几次加减法和移位运算 —— O(1)
4. **两次查表**：O(1)
5. **一次max操作**：O(1)

#### 与朴素做法的对比

**朴素做法**：
- 时间复杂度：O(查询区间长度)
- 对于长度为n的数组，最坏情况是O(n)

**ST表**：
- 时间复杂度：O(1)
- 无论查询区间多长，都是常数时间

#### 查询的常数因子

虽然查询是O(1)的，但常数因子可能较大：

1. **多次查表**：需要查两次st表
2. **计算索引**：需要计算两个数组索引
3. **log2查表**：需要查一次log2数组

因此，对于简单的查询，ST表可能不是最优的。

但对于复杂的查询或多次查询，ST表的优势就体现出来了。

## 完整代码实现

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 1e5 + 5;
const int LOGN = 20;  // 2^20 > 1e5，足够覆盖

int st[N][LOGN];  // st[i][j]表示从位置i开始，长度为2^j的区间的最大值
int log2[N];      // log2[i]表示i的以2为底的对数的整数部分

// 预处理ST表
void build(vector<int>& arr, int n) {
    // 第一步：初始化log2数组
    log2[1] = 0;
    for (int i = 2; i <= n; i++) {
        log2[i] = log2[i / 2] + 1;  // 利用递推关系计算log2
    }
    
    // 第二步：初始化st表
    // 长度为2^0 = 1的区间，最大值就是arr[i]本身
    for (int i = 0; i < n; i++) {
        st[i][0] = arr[i];
    }
    
    // 第三步：递推计算st表
    // st[i][j] = max(st[i][j-1], st[i + 2^(j-1)][j-1])
    // 意思是：长度为2^j的区间，可以分成两个长度为2^(j-1)的区间
    for (int j = 1; (1 << j) <= n; j++) {        // 枚举2的幂次
        for (int i = 0; i + (1 << j) <= n; i++) {  // 枚举起始位置
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}

// 查询区间[l, r]的最大值
int query(int l, int r) {
    int k = log2[r - l + 1];  // 计算最大的k，使得2^k <= 区间长度
    // st[l][k] 表示从l开始，长度为2^k的区间的最大值
    // st[r - (1 << k) + 1][k] 表示从r - 2^k + 1开始，长度为2^k的区间的最大值
    return max(st[l][k], st[r - (1 << k) + 1][k]);
}

int main() {
    // 示例：在数组[3, 1, 4, 1, 5, 9, 2, 6]中进行多次查询
    vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6};
    int n = arr.size();
    
    // 预处理ST表
    build(arr, n);
    
    // 测试查询
    cout << "数组: [3, 1, 4, 1, 5, 9, 2, 6]" << endl;
    cout << "----------------------------------------" << endl;
    
    cout << "区间[0, 3]的最大值: " << query(0, 3) << endl;  // 应该输出4
    cout << "区间[2, 5]的最大值: " << query(2, 5) << endl;  // 应该输出9
    cout << "区间[1, 6]的最大值: " << query(1, 6) << endl;  // 应该输出9
    cout << "区间[0, 7]的最大值: " << query(0, 7) << endl;  // 应该输出9
    cout << "区间[3, 4]的最大值: " << query(3, 4) << endl;  // 应该输出5
    
    return 0;
}
```

## 复杂度分析

### 时间复杂度

**预处理阶段**：
- 时间复杂度：O(n × log n)
- 分析：外层循环log n次，内层循环n次

**查询阶段**：
- 时间复杂度：O(1)
- 分析：只需要一次max操作，常数时间

**总时间复杂度**：O(n × log n + Q)，其中Q是查询次数

### 空间复杂度

- 空间复杂度：O(n × log n)
- 分析：需要存储st表和log2数组

## ST表的优势和劣势

### 优势

1. **查询速度快**：每次查询只需要O(1)时间
2. **实现简单**：代码逻辑清晰，容易理解和实现
3. **支持多次查询**：预处理一次，可以回答大量查询
4. **无需修改**：数组是静态的，不需要支持修改操作

### 劣势

1. **不支持修改**：ST表不支持对数组的修改操作
2. **空间开销大**：需要O(n × log n)的空间
3. **预处理时间**：需要O(n × log n)的预处理时间

## ST表与其他方法的对比

| 方法 | 预处理时间 | 单次查询时间 | 支持修改 | 空间复杂度 |
| :--- | :--- | :--- | :--- | :--- |
| 朴素做法 | O(1) | O(n) | 支持 | O(1) |
| ST表 | O(n × log n) | O(1) | 不支持 | O(n × log n) |
| 线段树 | O(n) | O(log n) | 支持 | O(n) |
| 树状数组 | O(n) | O(log n) | 支持 | O(n) |

**选择建议**：
- 如果数组是静态的（不修改），查询次数多，选择ST表
- 如果需要支持修改，选择线段树或树状数组
- 如果查询次数很少，直接用朴素做法

## ST表的变种和应用

### 1. 求区间最小值

只需要将预处理和查询中的 `max` 改为 `min` 即可：

```cpp
// 预处理（求最小值）
for (int j = 1; (1 << j) <= n; j++) {
    for (int i = 0; i + (1 << j) <= n; i++) {
        st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }
}

// 查询（求最小值）
int queryMin(int l, int r) {
    int k = log2[r - l + 1];
    return min(st[l][k], st[r - (1 << k) + 1][k]);
}
```

### 2. 同时求最大值和最小值

使用两个ST表分别存储最大值和最小值：

```cpp
int stMax[N][LOGN];  // 存储最大值
int stMin[N][LOGN];  // 存储最小值

// 预处理
void build(vector<int>& arr, int n) {
    log2[1] = 0;
    for (int i = 2; i <= n; i++) {
        log2[i] = log2[i / 2] + 1;
    }
    
    for (int i = 0; i < n; i++) {
        stMax[i][0] = arr[i];
        stMin[i][0] = arr[i];
    }
    
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            stMax[i][j] = max(stMax[i][j - 1], stMax[i + (1 << (j - 1))][j - 1]);
            stMin[i][j] = min(stMin[i][j - 1], stMin[i + (1 << (j - 1))][j - 1]);
        }
    }
}

// 查询最大值和最小值
pair<int, int> queryMinMax(int l, int r) {
    int k = log2[r - l + 1];
    int maxVal = max(stMax[l][k], stMax[r - (1 << k) + 1][k]);
    int minVal = min(stMin[l][k], stMin[r - (1 << k) + 1][k]);
    return {maxVal, minVal};
}
```

### 3. 求区间GCD

ST表也可以用来求区间最大公约数（GCD），只需要将 `max` 改为 `gcd`：

```cpp
int stGCD[N][LOGN];  // 存储GCD值

// 预处理（求GCD）
void buildGCD(vector<int>& arr, int n) {
    log2[1] = 0;
    for (int i = 2; i <= n; i++) {
        log2[i] = log2[i / 2] + 1;
    }
    
    for (int i = 0; i < n; i++) {
        stGCD[i][0] = arr[i];
    }
    
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            stGCD[i][j] = __gcd(stGCD[i][j - 1], stGCD[i + (1 << (j - 1))][j - 1]);
        }
    }
}

// 查询GCD
int queryGCD(int l, int r) {
    int k = log2[r - l + 1];
    return __gcd(stGCD[l][k], stGCD[r - (1 << k) + 1][k]);
}
```

## 常见问题与注意事项

### 1. 数组下标问题

在C++中，数组下标从0开始，但在某些算法题中可能从1开始。需要根据题目要求调整。

### 2. LOGN的大小设置

LOGN应该设置为⌈log₂(N)⌉+1，确保覆盖所有可能的跳跃。对于N=1e5，LOGN=20就足够了。

### 3. 空间限制

如果题目空间限制较严，需要注意ST表的空间开销。可以考虑使用其他方法。

### 4. 查询区间的边界

查询时要注意区间边界是否包含在查询范围内，避免越界。

## ST表的详细原理分析

### 为什么ST表查询时间复杂度是O(1)？

这是一个很好的问题！让我们详细分析一下：

1. **预处理阶段**：我们提前计算了所有长度为 `2^k` 的区间的最值
2. **查询阶段**：对于任意查询区间 `[l, r]`，我们只需要查表两次
3. **关键技巧**：利用二进制分解，将任意长度的区间表示为两个 `2^k` 的区间

### 为什么可以用两个区间覆盖查询区间？

假设查询区间长度为 `len = r - l + 1`，我们找到最大的 `k` 使得 `2^k <= len`。

那么：
- 区间1：`[l, l + 2^k - 1]`，长度为 `2^k`
- 区间2：`[r - 2^k + 1, r]`，长度为 `2^k`

这两个区间会覆盖整个查询区间 `[l, r]`，并且可能有重叠。但是，对于求最大值或最小值来说，重叠不会影响结果。

### 为什么重叠不影响结果？

**关键观察**：对于最大值/最小值查询，两个重叠的区间覆盖整个查询区间是足够的。

假设区间1的最大值是 `max1`，区间2的最大值是 `max2`，那么整个查询区间的最大值就是 `max(max1, max2)`。

即使两个区间有重叠，`max1` 和 `max2` 中至少有一个是整个查询区间的最大值。

### 为什么不能只用一个区间？

因为查询区间的长度不一定是 `2` 的幂次方。如果只用一个长度为 `2^k` 的区间，可能无法完全覆盖查询区间。

### 为什么用两个区间就足够了？

因为 `2^k` 是不超过 `len` 的最大的 `2` 的幂次方，所以 `2^k >= len/2`。

因此，两个长度为 `2^k` 的区间可以覆盖长度为 `len` 的查询区间。

## ST表的数学基础

### 二进制分解原理

任何正整数都可以表示为若干个 `2` 的幂次方的和。这是ST表的数学基础。

例如：
- `5 = 4 + 1 = 2^2 + 2^0`
- `13 = 8 + 4 + 1 = 2^3 + 2^2 + 2^0`
- `100 = 64 + 32 + 4 = 2^6 + 2^5 + 2^2`

### 为什么选择 `2` 的幂次方？

1. **二进制分解**：任何整数都可以表示为 `2` 的幂次方的和
2. **快速计算**：计算机使用二进制，计算 `2` 的幂次方非常快
3. **倍增思想**：`2^k` 的长度可以通过 `2^(k-1)` 的长度得到

### log2数组的作用

`log2[i]` 表示 `i` 的以 `2` 为底的对数的整数部分，即最大的 `k` 使得 `2^k <= i`。

这个数组可以快速计算查询区间对应的 `k` 值，从而确定查询时需要使用的 `st` 表的列。

## ST表的详细调试技巧

### 1. 打印ST表

在调试时，可以打印ST表来验证预处理是否正确：

```cpp
void printST(int n) {
    cout << "ST表内容：" << endl;
    for (int j = 0; (1 << j) <= n; j++) {
        cout << "2^" << j << " 的区间：";
        for (int i = 0; i + (1 << j) <= n; i++) {
            cout << st[i][j] << " ";
        }
        cout << endl;
    }
}
```

### 2. 验证查询结果

可以用朴素方法验证ST表的查询结果：

```cpp
int naiveQuery(vector<int>& arr, int l, int r) {
    int result = arr[l];
    for (int i = l + 1; i <= r; i++) {
        result = max(result, arr[i]);
    }
    return result;
}

// 在测试代码中
for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
        int stResult = query(i, j);
        int naiveResult = naiveQuery(arr, i, j);
        if (stResult != naiveResult) {
            cout << "错误：区间[" << i << ", " << j << "]的查询结果不一致！" << endl;
            cout << "ST表结果：" << stResult << endl;
            cout << "朴素结果：" << naiveResult << endl;
        }
    }
}
```

### 3. 打印log2数组

```cpp
void printLog2(int n) {
    cout << "log2数组：" << endl;
    for (int i = 1; i <= n; i++) {
        cout << "log2[" << i << "] = " << log2[i] << endl;
    }
}
```

## ST表的高级应用

### 1. 二维RMQ问题

二维RMQ问题是在矩阵中查询子矩阵的最大值/最小值。

```cpp
const int N = 1005;
const int LOGN = 11;  // 2^11 > 1000

int st[N][N][LOGN][LOGN];  // 四维数组，存储二维ST表
int log2[N];

// 预处理二维ST表
void build2D(vector<vector<int>>& matrix, int n, int m) {
    // 初始化log2数组
    log2[1] = 0;
    for (int i = 2; i <= max(n, m); i++) {
        log2[i] = log2[i / 2] + 1;
    }
    
    // 初始化：大小为1×1的子矩阵
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            st[i][j][0][0] = matrix[i][j];
        }
    }
    
    // 预处理：先按行预处理
    for (int k = 1; (1 << k) <= n; k++) {
        for (int i = 0; i + (1 << k) <= n; i++) {
            for (int j = 0; j < m; j++) {
                st[i][j][k][0] = max(st[i][j][k-1][0], st[i + (1 << (k-1))][j][k-1][0]);
            }
        }
    }
    
    // 预处理：再按列预处理
    for (int k = 0; (1 << k) <= n; k++) {
        for (int l = 1; (1 << l) <= m; l++) {
            for (int i = 0; i + (1 << k) <= n; i++) {
                for (int j = 0; j + (1 << l) <= m; j++) {
                    st[i][j][k][l] = max(st[i][j][k][l-1], st[i][j + (1 << (l-1))][k][l-1]);
                }
            }
        }
    }
}

// 查询子矩阵最大值
int query2D(int x1, int y1, int x2, int y2) {
    int k = log2[x2 - x1 + 1];
    int l = log2[y2 - y1 + 1];
    
    // 将子矩阵分解为4个部分
    int m1 = max(st[x1][y1][k][l], st[x2 - (1 << k) + 1][y1][k][l]);
    int m2 = max(st[x1][y2 - (1 << l) + 1][k][l], st[x2 - (1 << k) + 1][y2 - (1 << l) + 1][k][l]);
    
    return max(m1, m2);
}
```

**二维RMQ的原理**：

1. **预处理阶段**：
   - 先对每一行构建ST表
   - 再对每一列构建ST表
   - 这样就得到了所有可能的子矩阵的最值

2. **查询阶段**：
   - 将查询子矩阵分解为4个预处理好的子矩阵
   - 取这4个子矩阵的最值

**复杂度分析**：
- 预处理时间：O(n × m × log n × log m)
- 查询时间：O(1)
- 空间复杂度：O(n × m × log n × log m)

**优化技巧**：
- 可以先按行预处理，再按列预处理，减少重复计算
- 可以使用空间换时间，存储中间结果

### 2. 离线RMQ问题

当所有查询都已知时，可以考虑离线处理，可能会更高效。

### 3. ST表与LCA的结合

ST表可以用来解决LCA（最近公共祖先）问题，通过将树转换为欧拉序，然后用ST表查询最小深度节点。

```cpp
vector<int> euler;  // 欧拉序
vector<int> depth;  // 每个节点的深度
vector<int> first;  // 每个节点在欧拉序中第一次出现的位置
int stEuler[N][LOGN];  // 存储欧拉序的ST表
int log2[N];

// DFS生成欧拉序
void dfs(int u, int parent, int d) {
    euler.push_back(u);
    depth.push_back(d);
    
    for (int v : adj[u]) {
        if (v != parent) {
            dfs(v, u, d + 1);
            euler.push_back(u);
            depth.push_back(d);
        }
    }
}

// 预处理ST表
void buildST() {
    int n = euler.size();
    log2[1] = 0;
    for (int i = 2; i <= n; i++) {
        log2[i] = log2[i / 2] + 1;
    }
    
    for (int i = 0; i < n; i++) {
        stEuler[i][0] = euler[i];
    }
    
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            int left = stEuler[i][j - 1];
            int right = stEuler[i + (1 << (j - 1))][j - 1];
            // 选择深度较小的节点
            stEuler[i][j] = (depth[left] < depth[right]) ? left : right;
        }
    }
}

// 查询LCA
int queryLCA(int u, int v) {
    int l = first[u];
    int r = first[v];
    if (l > r) swap(l, r);
    
    int k = log2[r - l + 1];
    int left = stEuler[l][k];
    int right = stEuler[r - (1 << k) + 1][k];
    
    return (depth[left] < depth[right]) ? left : right;
}
```

## ST表的性能优化

### 1. 内存优化

如果空间限制严格，可以考虑以下优化：

```cpp
// 使用short类型存储，减少内存
short st[N][LOGN];

// 或者使用位压缩
unsigned int st[N];  // 每个整数存储多个值
```

**内存优化的原理**：

1. **类型压缩**：使用更小的数据类型
   - 如果数值范围小，可以用 `short` 代替 `int`
   - 如果数值范围更小，可以用 `char` 代替 `int`

2. **位压缩**：一个整数存储多个值
   - 如果每个值只需要4位，一个 `int` 可以存储8个值
   - 节省空间，但增加代码复杂度

**注意事项**：
- 数值范围不能超过数据类型的范围
- 位压缩会增加代码复杂度和时间开销

### 2. 预处理优化

```cpp
// 手动展开循环，减少循环开销
for (int j = 1; j <= LOGN; j++) {
    int len = 1 << j;
    int halfLen = 1 << (j - 1);
    for (int i = 0; i + len <= n; i++) {
        st[i][j] = max(st[i][j - 1], st[i + halfLen][j - 1]);
    }
}
```

**预处理优化的原理**：

1. **减少重复计算**：
   - 提前计算 `len` 和 `halfLen`
   - 避免在循环中重复计算

2. **循环展开**：
   - 手动展开内层循环
   - 减少循环开销

**更高级的优化**：

```cpp
// 使用SIMD指令加速（需要特定硬件支持）
void buildSIMD(vector<int>& arr, int n) {
    for (int i = 0; i < n; i++) {
        st[i][0] = arr[i];
    }
    
    for (int j = 1; (1 << j) <= n; j++) {
        #pragma omp parallel for  // 使用OpenMP并行化
        for (int i = 0; i + (1 << j) <= n; i++) {
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}
```

### 3. 查询优化

```cpp
// 使用内联函数
inline int query(int l, int r) {
    int k = log2[r - l + 1];
    return max(st[l][k], st[r - (1 << k) + 1][k]);
}
```

**查询优化的原理**：

1. **内联函数**：
   - 减少函数调用开销
   - 适合简单的查询函数

2. **避免重复计算**：
   - 将中间结果存储在局部变量中
   - 减少重复的数组访问

**更高级的优化**：

```cpp
// 预计算所有可能的k值和偏移量
struct QueryInfo {
    int k;
    int offset1;
    int offset2;
};

QueryInfo queryInfo[N][N];  // 存储所有可能的查询信息

void buildQueryInfo(int n) {
    for (int l = 0; l < n; l++) {
        for (int r = l; r < n; r++) {
            int len = r - l + 1;
            int k = log2[len];
            queryInfo[l][r].k = k;
            queryInfo[l][r].offset1 = l;
            queryInfo[l][r].offset2 = r - (1 << k) + 1;
        }
    }
}

// 查询时直接使用预计算的信息
inline int queryFast(int l, int r) {
    QueryInfo info = queryInfo[l][r];
    return max(st[info.offset1][info.k], st[info.offset2][info.k]);
}
```

### 4. 缓存优化

**缓存友好的访问模式**：

```cpp
// 按列优先顺序预处理，提高缓存命中率
void buildCacheFriendly(vector<int>& arr, int n) {
    log2[1] = 0;
    for (int i = 2; i <= n; i++) {
        log2[i] = log2[i / 2] + 1;
    }
    
    for (int i = 0; i < n; i++) {
        st[i][0] = arr[i];
    }
    
    // 按列优先顺序处理
    for (int i = 0; i < n; i++) {
        for (int j = 1; (1 << j) <= n - i; j++) {
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}
```

**缓存优化的原理**：

1. **空间局部性**：
   - 相邻的元素存储在相邻的内存位置
   - 提高缓存命中率

2. **时间局部性**：
   - 最近访问的元素很可能再次被访问
   - 减少缓存未命中

### 5. 并行化处理

```cpp
// 使用OpenMP并行化预处理
#include <omp.h>

void buildParallel(vector<int>& arr, int n) {
    log2[1] = 0;
    for (int i = 2; i <= n; i++) {
        log2[i] = log2[i / 2] + 1;
    }
    
    for (int i = 0; i < n; i++) {
        st[i][0] = arr[i];
    }
    
    for (int j = 1; (1 << j) <= n; j++) {
        #pragma omp parallel for
        for (int i = 0; i + (1 << j) <= n; i++) {
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}
```

**并行化优化的原理**：

1. **任务分解**：
   - 将预处理任务分解为多个子任务
   - 每个子任务处理一部分数据

2. **负载均衡**：
   - 使用 `#pragma omp parallel for` 自动分配任务
   - 避免负载不均衡

**注意事项**：
- 并行化会增加线程创建和同步的开销
- 适合大规模数据的预处理

## ST表的常见错误

### 1. 数组越界

```cpp
// 错误：可能越界
for (int j = 1; (1 << j) <= n; j++) {
    for (int i = 0; i <= n - (1 << j); i++) {  // 可能越界
        st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }
}

// 正确
for (int j = 1; (1 << j) <= n; j++) {
    for (int i = 0; i + (1 << j) <= n; i++) {
        st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }
}
```

### 2. log2数组未初始化

```cpp
// 错误：log2数组未初始化
void build(vector<int>& arr, int n) {
    for (int i = 0; i < n; i++) {
        st[i][0] = arr[i];
    }
    
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}

// 正确：先初始化log2数组
void build(vector<int>& arr, int n) {
    log2[1] = 0;
    for (int i = 2; i <= n; i++) {
        log2[i] = log2[i / 2] + 1;
    }
    
    for (int i = 0; i < n; i++) {
        st[i][0] = arr[i];
    }
    
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}
```

### 3. 查询区间为空

```cpp
// 错误：没有检查区间是否为空
int query(int l, int r) {
    int k = log2[r - l + 1];
    return max(st[l][k], st[r - (1 << k) + 1][k]);
}

// 正确：检查区间是否为空
int query(int l, int r) {
    if (l > r) swap(l, r);
    if (l < 0 || r >= n) return -1;  // 处理越界
    int k = log2[r - l + 1];
    return max(st[l][k], st[r - (1 << k) + 1][k]);
}
```

## ST表的典型题目分析

### 题目1：区间最值查询

**题目描述**：给定一个长度为n的数组，回答m次查询，每次查询询问区间[l, r]的最大值。

**解题思路**：
1. 使用ST表预处理
2. 每次查询O(1)回答

**代码示例**：

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1e5 + 5;
const int LOGN = 20;

int st[N][LOGN];
int log2[N];

void build(vector<int>& arr, int n) {
    log2[1] = 0;
    for (int i = 2; i <= n; i++) {
        log2[i] = log2[i / 2] + 1;
    }
    
    for (int i = 0; i < n; i++) {
        st[i][0] = arr[i];
    }
    
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int query(int l, int r) {
    int k = log2[r - l + 1];
    return max(st[l][k], st[r - (1 << k) + 1][k]);
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    build(arr, n);
    
    while (m--) {
        int l, r;
        cin >> l >> r;
        cout << query(l, r) << endl;
    }
    
    return 0;
}
```

### 题目2：区间GCD查询

**题目描述**：给定一个长度为n的数组，回答m次查询，每次查询询问区间[l, r]的GCD。

**解题思路**：
1. 使用ST表预处理GCD
2. GCD运算满足可结合性，可以用ST表

**代码示例**：

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1e5 + 5;
const int LOGN = 20;

int st[N][LOGN];
int log2[N];

void build(vector<int>& arr, int n) {
    log2[1] = 0;
    for (int i = 2; i <= n; i++) {
        log2[i] = log2[i / 2] + 1;
    }
    
    for (int i = 0; i < n; i++) {
        st[i][0] = arr[i];
    }
    
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            st[i][j] = __gcd(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int query(int l, int r) {
    int k = log2[r - l + 1];
    return __gcd(st[l][k], st[r - (1 << k) + 1][k]);
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    build(arr, n);
    
    while (m--) {
        int l, r;
        cin >> l >> r;
        cout << query(l, r) << endl;
    }
    
    return 0;
}
```

### 题目3：区间最大值和最小值

**题目描述**：给定一个长度为n的数组，回答m次查询，每次查询询问区间[l, r]的最大值和最小值。

**解题思路**：
1. 使用两个ST表分别存储最大值和最小值
2. 每次查询同时返回最大值和最小值

**代码示例**：

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1e5 + 5;
const int LOGN = 20;

int stMax[N][LOGN];
int stMin[N][LOGN];
int log2[N];

void build(vector<int>& arr, int n) {
    log2[1] = 0;
    for (int i = 2; i <= n; i++) {
        log2[i] = log2[i / 2] + 1;
    }
    
    for (int i = 0; i < n; i++) {
        stMax[i][0] = arr[i];
        stMin[i][0] = arr[i];
    }
    
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            stMax[i][j] = max(stMax[i][j - 1], stMax[i + (1 << (j - 1))][j - 1]);
            stMin[i][j] = min(stMin[i][j - 1], stMin[i + (1 << (j - 1))][j - 1]);
        }
    }
}

pair<int, int> query(int l, int r) {
    int k = log2[r - l + 1];
    int maxVal = max(stMax[l][k], stMax[r - (1 << k) + 1][k]);
    int minVal = min(stMin[l][k], stMin[r - (1 << k) + 1][k]);
    return {maxVal, minVal};
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    build(arr, n);
    
    while (m--) {
        int l, r;
        cin >> l >> r;
        auto result = query(l, r);
        cout << result.first << " " << result.second << endl;
    }
    
    return 0;
}
```

## ST表的扩展阅读

### 1. 相关数据结构

- **线段树**：支持修改操作，但查询时间较长
- **树状数组**：支持修改操作，但功能有限
- **分块**：在ST表和线段树之间的折中方案

### 2. 相关算法

- **倍增算法**：与ST表思想相似
- **LCA算法**：可以用ST表优化
- **RMQ的其他解法**：卡特兰数方法、四俄罗斯人方法

### 3. 实际应用

- **数据库查询优化**：快速查找区间最值
- **图像处理**：快速查找区域最大值/最小值
- **金融分析**：快速查找区间最高价/最低价

## 总结

ST表是解决RMQ问题的高效数据结构，具有以下特点：

1. **查询效率高**：单次查询O(1)时间
2. **实现简单**：代码逻辑清晰，容易理解和实现
3. **适用范围广**：可以解决区间最值、GCD等问题
4. **静态数组**：适用于不修改的数组
5. **数学基础**：基于二进制分解和倍增思想

掌握ST表对于解决信奥竞赛中的区间查询问题非常重要，建议多练习相关题目以熟练掌握。

### 练习建议

1. **基础练习**：实现ST表的基本操作（预处理、查询）
2. **应用练习**：解决实际的RMQ问题
3. **变种练习**：尝试不同类型的区间查询（最小值、GCD等）
4. **综合练习**：结合其他算法解决复杂问题
5. **调试练习**：学习如何调试ST表程序

### 学习路线

1. **理解原理**：先理解ST表的基本思想和数学基础
2. **实现代码**：亲手实现ST表，加深理解
3. **测试验证**：用各种测试用例验证代码正确性
4. **应用实践**：解决实际的算法问题
5. **扩展学习**：学习相关数据结构和算法

通过系统学习和大量练习，可以熟练掌握ST表这一强大的数据结构，为解决区间查询问题提供有力工具。

---
## 01背包

### 二维

> [!IMPORTANT]
> 
> **状态转移公式** : `dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]]+v[i])` 选择第i个物品，需满足$j≥w_i$，即在剩余容量$j−w_i$的基础上加上当前物品的价值$v_i$。



```c++
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

void solve() {
    ll W, n;
    cin >> W >> n;3
    vector<ll> w(n + 1), v(n + 1);
    vector<vector<ll> > dp(n + 1, vector<ll> (W + 1));

    for (int i = 1; i <= n; i++)
        cin >> w[i] >> v[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            if (j < w[i]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            }
        }
    }
    cout << dp[n][W];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    while (T--) {
        solve(); 
    }
    return 0;
}
```

### 一维

> [!IMPORTANT]
> 
> 状态转移公式`dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i])`



```c++
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

void solve() {
    ll W, n;
    cin >> W >> n;
    vector<ll> w(n + 1), v(n + 1);
    vector<ll> dp(W + 1);
    for (int i = 1; i <= n; i++)
        cin >> w[i] >> v[i];
    for (int i = 1; i <= n; i++) {
        for (int j = W; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    cout << dp[W];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
```

## 完全背包

> [!IMPORTANT]
> 
> 二维状态转移公式：`dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);`
> 
> 一维状态转移公式：`dp[j] = max(dp[j], dp[j - weights[i]] + values[i])`



### 二维DP解法

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int completePack2D(int W, vector<int>& weights, vector<int>& values) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= W; ++j) {
            if (j >= weights[i-1]) {
                dp[i][j] = max(dp[i-1][j], dp[i][j-weights[i-1]] + values[i-1]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][W];
}

int main() {
    int W = 5;
    vector<int> weights = {1, 2, 3};
    vector<int> values = {6, 10, 12};

    cout << "Maximum value (2D): " << completePack2D(W, weights, values) << endl;
    return 0;
}
```

### 一维DP解法

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int completePack1D(int W, vector<int>& weights, vector<int>& values) {
    vector<int> dp(W + 1, 0);

    for (int i = 0; i < weights.size(); ++i) {
        for (int j = weights[i]; j <= W; ++j) { // 正向遍历
            dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);
        }
    }

    return dp[W];
}

int main() {
    int W = 5;
    vector<int> weights = {1, 2, 3};
    vector<int> values = {6, 10, 12};

    cout << "Maximum value (1D): " << completePack1D(W, weights, values) << endl;
    return 0;
}
```

### 代码解析

**二维解法特点：**

1. 使用二维数组`dp[n+1][W+1]`存储中间结果
2. 外层循环遍历物品，内层循环遍历容量
3. 状态转移时比较不选当前物品和选当前物品的情况
4. 空间复杂度O(N*W)

**一维解法特点：**

1. 使用一维数组`dp[W+1]`优化空间
2. **关键点**：内层循环必须**正向遍历**（从`weights[i]`到`W`）
3. 状态转移直接覆盖原数组
4. 空间复杂度O(W)

> [!CAUTION]
> 
> **为什么完全背包要正向遍历？**

在完全背包中，同一物品可以选多次。正向遍历时，`dp[j - weights[i]]`可能已经包含当前物品的选取，因此可以实现多次选取的效果。例如：

当计算`dp[2]`时：

- 可能已经选取了1个物品（`dp[1]`的值）
- 然后`dp[2] = max(dp[2], dp[1] + values[i])`相当于再选一次

而逆序遍历（如01背包）会保证每个物品只被考虑一次。

**复杂度分析**

两种解法的时间复杂度都是O(N*W)，其中：

- N是物品数量
- W是背包容量

空间复杂度：

- 二维：O(N*W)
- 一维：O(W)

## 多重背包

多重背包问题是背包问题的一个变种，其中每种物品有一定的数量限制（不是无限也不是只有一个）。下面我将介绍多重背包问题的C++实现。

**问题描述**

给定：

- 一个容量为W的背包
- N种物品，每种物品有：
  - 重量weight[i]
  - 价值value[i]
  - 数量限制amount[i]

目标：在不超过背包容量的前提下，选择物品使得总价值最大。

### 基本解法：转化为01背包

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int multiKnapsack(int W, vector<int>& weight, vector<int>& value, vector<int>& amount) {
    int n = weight.size();
    vector<int> dp(W + 1, 0);

    for (int i = 0; i < n; i++) {
        for (int j = W; j >= weight[i]; j--) {
            // 尝试放入0到amount[i]个第i种物品
            for (int k = 1; k <= amount[i] && k * weight[i] <= j; k++) {
                dp[j] = max(dp[j], dp[j - k * weight[i]] + k * value[i]);
            }
        }
    }

    return dp[W];
}

int main() {
    int W = 10; // 背包容量
    vector<int> weight = {2, 3, 4}; // 物品重量
    vector<int> value = {3, 4, 5}; // 物品价值
    vector<int> amount = {3, 2, 2}; // 物品数量限制

    cout << "最大价值: " << multiKnapsack(W, weight, value, amount) << endl;
    return 0;
}
```

### 优化解法：二进制拆分

通过二进制优化将12个单一物品拆为四个一的物品将复杂的多重背包问题简化为更直观的01背包问题

```cpp
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

void solve() {
    int W, n;
    cin >> n >> W;
    vector<int> v(1), w(1);
    vector<int> dp(W + 1);
    for (int i = 1; i <= n; i++) {
        int num, wi, vi;
        cin >> num >> wi >> vi;
        for (int j = 1; j <= num; j *= 2) {
            w.push_back(wi * j);
            v.push_back(vi * j);
            num -= j;
        }
        if (num != 0) {
            w.push_back(wi * num);
            v.push_back(vi * num);
        }
    }
    n = v.size() - 1;
    for (int i = 1; i <= n; i++) {
        for (int j = W; j >= v[i]; j--) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
```

### 单调队列优化

更高效的解法是使用单调队列优化，可以将时间复杂度进一步降低：

```cpp
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int monotonicQueueMultiKnapsack(int W, vector<int>& weight, vector<int>& value, vector<int>& amount) {
    vector<int> dp(W + 1, 0);
    vector<int> pre(W + 1, 0); // 前一轮的dp值
    int n = weight.size();

    for (int i = 0; i < n; i++) {
        pre = dp;
        int w = weight[i], v = value[i], m = amount[i];

        for (int j = 0; j < w; j++) {
            deque<int> q;
            for (int k = j; k <= W; k += w) {
                // 维护单调队列
                while (!q.empty() && (k - q.front()) / w > m) {
                    q.pop_front();
                }

                if (!q.empty()) {
                    dp[k] = max(pre[k], pre[q.front()] + (k - q.front()) / w * v);
                }

                while (!q.empty() && pre[k] >= pre[q.back()] + (k - q.back()) / w * v) {
                    q.pop_back();
                }

                q.push_back(k);
            }
        }
    }

    return dp[W];
}

int main() {
    int W = 10; // 背包容量
    vector<int> weight = {2, 3, 4}; // 物品重量
    vector<int> value = {3, 4, 5}; // 物品价值
    vector<int> amount = {3, 2, 2}; // 物品数量限制

    cout << "最大价值(单调队列优化): " << monotonicQueueMultiKnapsack(W, weight, value, amount) << endl;
    return 0;
}
```

**总结**

1. **基本解法**：简单直观，但时间复杂度较高，为$O(N*W*K)$，其中K是物品的平均数量
2. **二进制优化**：将问题转化为01背包，时间复杂度降低到$O(N*W*logK)$
3. **单调队列优化**：最优解法，时间复杂度为$O(N*W)$

# 质数和合数

## 质数判定(代码)

```cpp
bool isprime(ll x){
  if(x<2) return 0;
  for(int i=2;i*i<=x;i++) if(x%i==0) return 0;
  return 1;
}//x是要判定的数
```

## 质数筛

给定l,r，求出l~r之间所有的质数，这样的问题叫做质数筛

### 埃氏筛

#### 基本思想

 任意整数x的倍数，$2x,3x……$都不是质数

#### 实现步骤

Step 1: 首先将小于1的数排除;
Step 2: 创建从l ~r到的连续整数列表;
Step 3:初始化p=2,因为2是最小的质数;
Step 4:枚举所有p的倍数,标记为非质数(合数)；
Step 5:找到下一个没有标记且大于p的数。如果没有,结束运算，如果有p赋值为它；
Step 6:运算结束后，剩下所有没有被标记的数都是质数;

#### 代码

```cpp
//ll = long long
//N=元素个数
bool is_p[N];
ll prime[N];
ll aishishai(ll n){
  for(int i=1;i<=n;i++) is_p[i]=1;
  //prime[]存储了l~r的所有质数
  //这里我提前将prime初始化为0
  is_p[1]=0;
  is_p[0]=0;
  //Step 1
  ll tot=0;
  for(int i=1;i<=n;i++){
    if(!is_p[i]) continue;//当前数是合数
    //是质数
    prime[++tot]=i;//存储这个质数
    for(int j=i*2;j<=n;j+=i) is_p[j]=0;//Step 4 and Step 5
  }
  return tot;//质数的个数
}
```

### 欧拉筛(线性筛）

#### 基本思想

在埃氏筛法的基础上，让每个合数都只被他的最小质因子筛选一次，已达到不重复的目的

#### 实现步骤

Step 1:依次枚举每一个数
Step 2:若当前数没被筛，则把这个数加入质数集合
Step 3:对于每一个数,枚举当前已知质数,并筛掉当前的数×枚举到的数
Step 4:如果i是枚举到的质数的倍数,停止枚举质数

#### 代码

```cpp
//ll = long long
//N=元素个数
bool is_prime[N];
ll prime[N];
ll oulashai(ll n){
  //prime[]存储了l~r的所有质数
  //这里我提前将is_prime初始化为0
  is_prime[0]=0;
  is_prime[1]=0;
  for(int i=2;i<=n;i++){
    if(is_prime[i]) prime[cnt++]=i;
    for(int j=1;j<cnt&&prime[j]*i<=n;j++){
      is_prime[prime[j]*i]=0;
      if(i%prime[j]==0) break;
    }
   return cnt;
  }
```

# 同余

$(a+b) \mod q=(a\mod q+b\mod q)\mod q$

$(a-b) \mod q = (a \mod q-b \mod q+q)\mod q$



# 图论

## 最短路

### floyd

### 思路

选择$k$点中转$i$点出发$j$点结束，时间复杂度$O(n^3)$,肯定不会$TLE$的

### 代码

```cpp
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e2+5;
double f(ll x1,ll y1,ll x2,ll y2){
    return sqrt((x1-x2)*1.0*(x1-x2)*1.0+(y1-y2)*1.0*(y1-y2)*1.0);
}
ll n,m;
pair<ll,ll> a[N];
double dis[N][N];
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].first>>a[i].second;
    memset(dis,127.0,sizeof(dis));
    cin>>m;
    for(int i=1;i<=m;i++){
        ll x,y;
        cin>>x>>y;
        dis[x][y]=dis[y][x]=f(a[x].first,a[x].second,a[y].first,a[y].second);
    }
    ll b,e;
    cin>>b>>e;
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dis[i][j]>dis[i][k]+dis[k][j]) dis[i][j]=dis[i][k]+dis[k][j];
            }
        }
    }
    printf("%.2f",dis[b][e]);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}
```



### dijkstra

### 代码

```cpp
#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,m;
vector<pair<ll,ll>> g[N];
ll dis[N];
ll b,e;
void dijkstra(ll b){

    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;//堆优化
    q.push({0,b});
    memset(dis,0x3f,sizeof(dis));
    dis[b]=0;
    while(!q.empty()){
        auto x=q.top();
        q.pop();
        if(x.first>dis[x.second]) continue;
        for(auto i:g[x.second]){
            if(dis[i.first]>dis[x.second]+i.second){
                dis[i.first]=dis[x.second]+i.second;
                q.push({dis[i.first],i.first});
            }
        }
    }
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    dijkstra();
    cout<<dis[e];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}

```



### bellman-ford

没必要讲

### SPFA

### 正常版

SPFA不难，可以用在差分约束系统上

直接贴代码：

```cpp
#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,m,b,e;
vector<pair<ll,ll>> g[N];
ll dis[N];
bool inq[N];
ll SPFA(){
    queue<ll> q;
    q.push(b);
    dis[b]=0;
    inq[b]=1;
    while(!q.empty()){
        ll x=q.front();
        inq[x]=0;
        q.pop();
        for(auto v:g[x]){
            if(!inq[v.first]&&dis[v.first]>dis[x]+v.second){
	            inq[v.first]=1;
                dis[v.first]=dis[x]+v.second;
                q.push(v.first);
            }
        }
    }
    return dis[e];
}
void solve(){
    cin>>n>>m>>b>>e;
    for(int i=1;i<=m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    memset(dis,0x3f,sizeof(dis));
    cout<<SPFA()<<el;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
```

### 负环判断

> [!CAUTION]
> 
> 负环是什么？
> 
> 负环指图上一个环，他们的边权和为复数

> [!CAUTION]
> 
> 为啥有负环的图$SPFA$得不到正确解呢？
> 
> 因为负环上边权和是负数，一直走下去最小值是$-\infty$,得不到解

> [!CAUTION]
> 
> 怎么判断负环呢？
> 
> 只要一个点的入队次数超过$n$了，这个图就一定有负环

代码：

```cpp
#include<bits/stdc++.h>
using namespace std;
const int N=10010*2;
int e[N],ne[N],w[N],h[N],idx,cnt[N],dis[N],st[N];
int n,m;
queue<int> q;
void add(int a,int b,int c)
{
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}
bool spfa()
{
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;i++)
    {
        st[i]=true;
        q.push(i);
    }
    while(q.size())
    {
        int t=q.front();
        q.pop();
        st[t]=false;
        for(int i=h[t];~i;i=ne[i])
        {
            int j=e[i];
            if(dis[j]>dis[t]+w[i])
            {
                dis[j]=dis[t]+w[i];
                cnt[j]=cnt[t]+1;
                if(cnt[j]>=n) return true;
                if(!st[j])
                {
                    st[j]=true;
                    q.push(j);
                }
            }
        }
    }
    return false;
}
int main()
{
    cin>>n>>m;
    memset(h,-1,sizeof(h));
    for(int i=0;i<m;i++)
    {
        int u,v,c;
        cin>>u>>v>>c;
        add(u,v,c);
    }
    if(spfa())
    cout<<"Yes"<<endl;
    else
    cout<<"No"<<endl;
}//复制的别人的
```







# 扩展欧几里得算法

## 算法概述

扩展欧几里得算法（Extended Euclidean Algorithm）是欧几里得算法的扩展，不仅能够计算两个整数的最大公约数(GCD)，还能找到满足贝祖等式（Bézout's identity）的整数解。

### 贝祖等式

对于任意两个不全为零的整数a和b，存在整数x和y，使得：

```
ax + by = gcd(a, b)
```

这个等式称为贝祖等式，其中x和y称为贝祖系数。

## 算法原理

扩展欧几里得算法基于欧几里得算法的递归过程，通过回溯计算贝祖系数。

### 基本递推关系

假设我们已经计算出了：

```
gcd(b, a % b) = b * x' + (a % b) * y'
```

由于 `a % b = a - (a / b) * b`，我们可以得到：

```
gcd(a, b) = a * y' + b * (x' - (a / b) * y')
```

因此，贝祖系数的递推关系为：

```
x = y'
y = x' - (a / b) * y'
```

## 代码实现

### 基础版本

```cpp
#include <bits/stdc++.h>
using namespace std;

// 扩展欧几里得算法
// 返回a和b的最大公约数，并计算贝祖系数x和y
int extended_gcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1;
    int gcd = extended_gcd(b, a % b, x1, y1);

    // 回溯计算贝祖系数
    x = y1;
    y = x1 - (a / b) * y1;

    return gcd;
}

int main() {
    int a, b;
    cout << "输入两个整数a和b: ";
    cin >> a >> b;

    int x, y;
    int gcd = extended_gcd(a, b, x, y);

    cout << "gcd(" << a << ", " << b << ") = " << gcd << endl;
    cout << "贝祖系数: x = " << x << ", y = " << y << endl;
    cout << "验证: " << a << " * " << x << " + " << b << " * " << y << " = " << a * x + b * y << endl;

    return 0;
}
```

### 迭代版本

```cpp
#include <bits/stdc++.h>
using namespace std;

// 迭代版本的扩展欧几里得算法
pair<int, pair<int, int>> extended_gcd_iterative(int a, int b) {
    int x0 = 1, y0 = 0;  // 初始贝祖系数
    int x1 = 0, y1 = 1;  // 临时变量

    while (b != 0) {
        int q = a / b;

        // 更新贝祖系数
        int temp_x = x0 - q * x1;
        int temp_y = y0 - q * y1;

        x0 = x1;
        y0 = y1;
        x1 = temp_x;
        y1 = temp_y;

        // 欧几里得算法步骤
        int temp = a % b;
        a = b;
        b = temp;
    }

    return {a, {x0, y0}};  // 返回gcd和贝祖系数
}

int main() {
    int a, b;
    cout << "输入两个整数a和b: ";
    cin >> a >> b;

    auto result = extended_gcd_iterative(a, b);
    int gcd = result.first;
    int x = result.second.first;
    int y = result.second.second;

    cout << "gcd(" << a << ", " << b << ") = " << gcd << endl;
    cout << "贝祖系数: x = " << x << ", y = " << y << endl;
    cout << "验证: " << a << " * " << x << " + " << b << " * " << y << " = " << a * x + b * y << endl;

    return 0;
}
```

## 应用场景

### 1. 求解线性同余方程

扩展欧几里得算法可以用来求解形如 `ax ≡ b (mod m)` 的线性同余方程。

#### 求解步骤

1. 首先求解 `ax + my = gcd(a, m)`
2. 如果 `gcd(a, m) | b`，则方程有解
3. 解为 `x ≡ x0 * (b / gcd(a, m)) (mod m)`

#### 代码实现

```cpp
#include <bits/stdc++.h>
using namespace std;

// 扩展欧几里得算法
int extended_gcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1;
    int gcd = extended_gcd(b, a % b, x1, y1);

    x = y1;
    y = x1 - (a / b) * y1;

    return gcd;
}

// 求解线性同余方程 ax ≡ b (mod m)
bool linear_congruence(int a, int b, int m, int &x) {
    int x0, y0;
    int gcd = extended_gcd(a, m, x0, y0);

    if (b % gcd != 0) {
        return false;  // 无解
    }

    // 计算特解
    x = (x0 * (b / gcd)) % m;
    if (x < 0) x += m;  // 确保解为正

    return true;
}

int main() {
    int a, b, m;
    cout << "求解线性同余方程 ax ≡ b (mod m)" << endl;
    cout << "输入a, b, m: ";
    cin >> a >> b >> m;

    int x;
    if (linear_congruence(a, b, m, x)) {
        cout << "方程有解，一个特解为: x ≡ " << x << " (mod " << m << ")" << endl;

        // 通解形式
        int gcd = __gcd(a, m);
        cout << "通解: x ≡ " << x << " + k * " << m / gcd << " (mod " << m << "), k ∈ Z" << endl;
    } else {
        cout << "方程无解" << endl;
    }

    return 0;
}
```

### 2. 求解模逆元

当a和m互质时，扩展欧几里得算法可以用来计算a模m的逆元。

#### 逆元定义

如果 `a * x ≡ 1 (mod m)`，则称x为a模m的逆元，记作 `a^(-1) ≡ x (mod m)`。

#### 代码实现

```cpp
#include <bits/stdc++.h>
using namespace std;

// 扩展欧几里得算法
int extended_gcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1;
    int gcd = extended_gcd(b, a % b, x1, y1);

    x = y1;
    y = x1 - (a / b) * y1;

    return gcd;
}

// 计算模逆元
bool mod_inverse(int a, int m, int &inv) {
    int x, y;
    int gcd = extended_gcd(a, m, x, y);

    if (gcd != 1) {
        return false;  // 逆元不存在
    }

    inv = (x % m + m) % m;  // 确保逆元为正
    return true;
}

int main() {
    int a, m;
    cout << "计算a模m的逆元" << endl;
    cout << "输入a, m: ";
    cin >> a >> m;

    int inv;
    if (mod_inverse(a, m, inv)) {
        cout << a << " 模 " << m << " 的逆元是: " << inv << endl;
        cout << "验证: " << a << " * " << inv << " ≡ " << (a * inv) % m << " (mod " << m << ")" << endl;
    } else {
        cout << a << " 模 " << m << " 的逆元不存在（因为gcd(" << a << ", " << m << ") ≠ 1）" << endl;
    }

    return 0;
}
```

### 3. 求解二元一次不定方程

扩展欧几里得算法可以用来求解形如 `ax + by = c` 的二元一次不定方程。

#### 求解步骤

1. 首先求解 `ax + by = gcd(a, b)`
2. 如果 `gcd(a, b) | c`，则方程有解
3. 解为 `x = x0 * (c / gcd(a, b))`，`y = y0 * (c / gcd(a, b))`

#### 代码实现

```cpp
#include <bits/stdc++.h>
using namespace std;

// 扩展欧几里得算法
int extended_gcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1;
    int gcd = extended_gcd(b, a % b, x1, y1);

    x = y1;
    y = x1 - (a / b) * y1;

    return gcd;
}

// 求解二元一次不定方程 ax + by = c
bool linear_diophantine(int a, int b, int c, int &x, int &y) {
    int x0, y0;
    int gcd = extended_gcd(a, b, x0, y0);

    if (c % gcd != 0) {
        return false;  // 无解
    }

    // 计算特解
    int factor = c / gcd;
    x = x0 * factor;
    y = y0 * factor;

    return true;
}

int main() {
    int a, b, c;
    cout << "求解二元一次不定方程 ax + by = c" << endl;
    cout << "输入a, b, c: ";
    cin >> a >> b >> c;

    int x, y;
    if (linear_diophantine(a, b, c, x, y)) {
        cout << "方程有解，一个特解为: x = " << x << ", y = " << y << endl;

        // 通解形式
        int gcd = __gcd(a, b);
        cout << "通解: x = " << x << " + k * " << b / gcd << ", y = " << y << " - k * " << a / gcd << ", k ∈ Z" << endl;
    } else {
        cout << "方程无解" << endl;
    }

    return 0;
}
```

## 算法复杂度分析

### 时间复杂度

扩展欧几里得算法的时间复杂度与欧几里得算法相同，为O(log(min(a, b)))。这是因为每次递归调用都会将问题规模至少减少一半。

### 空间复杂度

- 递归版本：O(log(min(a, b)))，由于递归栈的深度
- 迭代版本：O(1)，只需要常数级别的额外空间

## 常见问题与技巧

### 1. 处理大数

当处理大数时，可以使用long long类型：

```cpp
long long extended_gcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    long long x1, y1;
    long long gcd = extended_gcd(b, a % b, x1, y1);

    x = y1;
    y = x1 - (a / b) * y1;

    return gcd;
}
```

### 2. 处理负数

扩展欧几里得算法可以处理负数，但通常我们希望得到正的解：

```cpp
// 确保解为正
x = (x % m + m) % m;
```

### 3. 多组解的处理

对于有解的方程，通常有无限多组解。通解形式为：

对于 `ax + by = c`，通解为：

```
x = x0 + k * (b / gcd(a, b))
y = y0 - k * (a / gcd(a, b))
```

其中k为任意整数。

## 总结

扩展欧几里得算法是数论中的重要工具，它不仅能够计算最大公约数，还能求解贝祖等式，从而解决线性同余方程、模逆元计算和二元一次不定方程等问题。在信奥竞赛中，扩展欧几里得算法经常出现在数论相关的题目中，掌握其原理和应用非常重要。

## 差分约束系统

### 用处和含义

它广泛应用于**区间约束、调度优化、最值计算**等问题。现在来看求的是关于**一组变量的特殊不等式组**的方法。

如果一个系统由**$n$个变量和$m$个约束条件**组成，形成$m$个形如$a_i-a_j \geq k$ 的不等式，（$i,j,k,a[1-n]$ 均为常数 ）则称其为`差分约束系统`。 

**全都是由两个未知数的差$\leq$一个常数（$\geq$也可以，左右乘上-1就变成了$\leq$ ）的不等式组**就称作差分约束系统。

### 解题思想

由于是两个未知数**作差**：

所以${x_1,x_2,x_3,x_4,x_5}$是一个解，则${x_1+n,x_2+n,x_3+n,x_4+n,x_5+n}$ （$n$为一个常数） 也是一个解(互相抵消，懂得都懂)

所以说，这种不等式组**要么没解，要么有无限个解**



举个例子：

$x_1-x_0\leq 2$     （1）

$x_2-x_0 \leq 7$     （2）

$x_3-x_0 \leq 8$     （3)

$x_2-x_1 \leq 3$     （4）

$x_3-x_2\leq 2$     （5）

求$x_3-x_0$的最大值。

思考：例如这样的不等式，可以将他们**相加**（$\leq$号前面相加，后面相加，把没有用的抵消掉），得到许多$x_3-x_0 \leq k$,把这些不等式中的$k$,取个$min$,就得到了答案

解：

（3) ：$x_3-x_0 \leq 8$

（2）+（5）：$x_3-x_0 \leq 9$

（1）+（4）+（5）：$x_3-x_0 \leq 7$ 

$\min(8,9,7)=7$,所以答案为7

> [!IMPORTANT]
> 
> 这里可以把不等式组看成图(有向图)（建图是从$x_j$到$x_i$)
> 
> 例如：
> 
> $x_1-x_0 \leq 2$ 可以理解为$x_1$到$x_2$的距离为2！
> 
> 所以说求$x_3-x_0$的最大值就是求图中$x_3$到$x_0$的最短距离！

所以可以用上$SPFA$

> [!CAUTION]
> 
> 有负环怎么办？
> 
> 可以用$SPFA$判负环呀

可以去上面$SPFA$的位置学一学



### 代码详解

懒得写了，看一看一篇很棒的文章：[好东西](https://www.luogu.com.cn/problem/solution/P5960)（没错是万能的$luogu$题解）

code:

```cpp
#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,m;
vector<pair<ll,ll>> g[N];
vector<ll> dis(N,INT_MAX);
vector<ll> vis(N);
ll cnt[N];
bool SPFA(){
    queue<ll> q;
    dis[0]=0;
    q.push(0);
    vis[0]=1;
    while(!q.empty()){
        auto x=q.front();
        q.pop();
        vis[x]=0;
        for(auto i:g[x]){
            if(dis[i.first]>dis[x]+i.second){
                dis[i.first]=dis[x]+i.second;
                if(!vis[i.first]){
                    cnt[i.first]++;
                    vis[i.first]=1;
                    if(cnt[i.first]>n+1) return 0;
                    q.push(i.first);
                }
            }
        }
    }
    return 1;
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        g[v].push_back({u,w});
    }
    for(int i=1;i<=n;i++) g[0].push_back({i,0});
    bool flag=SPFA();
    if(!flag) cout<<"NO";
    else for(int i=1;i<=n;i++) cout<<dis[i]<<" ";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
```

### 扩展

#### $x_i-x_j \geq k$

改为$x_i-x_j \leq -k$

#### $x_i-x_j = k$

改为$x_i-x_j \leq k$和$x_i-x_j \geq k$(建两条边)

#### $x_i=x_j$

改为$x_i-x_j=0$和$x_j-x_i=0$ (还是建两条边)

# KMP算法

KMP（Knuth-Morris-Pratt）算法是一种高效的字符串匹配算法，用于在主串中查找模式串出现的位置。其核心思想是利用已匹配的部分信息，避免不必要的回溯。

## 为什么需要KMP算法？

### 暴力匹配的问题

假设我们要在文本串 `"ababcababcabc"` 中查找模式串 `"ababc"`。

**暴力匹配过程**：

```
文本: a b a b c a b a b c a b c
模式: a b a b c
```

当匹配到第5个字符时，文本是'c'，模式也是'c'，匹配成功！
但如果模式串是 `"ababd"`，文本串是 `"ababcababd"`：

```
文本: a b a b c a b a b d
模式: a b a b d
```

匹配到第5个字符时，文本是'c'，模式是'd'，不匹配！
暴力算法会回退文本指针，从第2个字符重新开始匹配，这导致了很多重复比较。

### KMP的解决思路

KMP算法的精髓：**当匹配失败时，不回退文本指针，而是利用已匹配的信息，将模式串"滑动"到合适的位置继续匹配。**

## 算法原理

KMP算法的核心是**前缀函数（next数组）**，它记录了模式串中每个位置的最长相同前后缀的长度。

**前缀**：从第一个字符开始但不包含最后一个字符的子串
**后缀**：从最后一个字符开始但不包含第一个字符的子串

例如：模式串 `"ababc"` 的前缀函数：

- 位置0：`"a"`，最长相同前后缀长度 = 0
- 位置1：`"ab"`，最长相同前后缀长度 = 0
- 位置2：`"aba"`，最长相同前后缀长度 = 1（前缀"a"，后缀"a"）
- 位置3：`"abab"`，最长相同前后缀长度 = 2（前缀"ab"，后缀"ab"）
- 位置4：`"ababc"`，最长相同前后缀长度 = 0

## KMP算法详细过程

### 第一步：理解next数组的作用

next数组告诉我们：**当模式串的第i个字符匹配失败时，应该跳转到第next[i-1]个字符继续匹配。**

举个例子，模式串 `"ababc"`：

```
位置: 0 1 2 3 4
字符: a b a b c
next: 0 0 1 2 0
```

- 当第4个字符'c'匹配失败时，跳转到next[3]=2的位置
- 当第3个字符'b'匹配失败时，跳转到next[2]=1的位置
- 当第2个字符'a'匹配失败时，跳转到next[1]=0的位置

### 第二步：手工计算next数组

以模式串 `"ababc"` 为例：

**初始化**：next[0] = 0

**计算next[1]**：

- 子串："ab"
- 前缀：{"a"}
- 后缀：{"b"}
- 最长相同前后缀长度 = 0
- next[1] = 0

**计算next[2]**：

- 子串："aba"
- 前缀：{"a", "ab"}
- 后缀：{"a", "ba"}
- 最长相同前后缀 = "a"，长度 = 1
- next[2] = 1

**计算next[3]**：

- 子串："abab"
- 前缀：{"a", "ab", "aba"}
- 后缀：{"b", "ab", "bab"}
- 最长相同前后缀 = "ab"，长度 = 2
- next[3] = 2

**计算next[4]**：

- 子串："ababc"
- 前缀：{"a", "ab", "aba", "abab"}
- 后缀：{"c", "bc", "abc", "babc"}
- 最长相同前后缀长度 = 0
- next[4] = 0

**最终next数组**：[0, 0, 1, 2, 0]

### 第三步：KMP匹配过程详解

以文本串 `"ababcababcabc"` 和模式串 `"ababc"` 为例：

```
文本: a b a b c a b a b c a b c
模式: a b a b c
next: 0 0 1 2 0
```

**第1轮匹配**：

- i=0, j=0: 'a'=='a'，匹配成功，j++
- i=1, j=1: 'b'=='b'，匹配成功，j++
- i=2, j=2: 'a'=='a'，匹配成功，j++
- i=3, j=3: 'b'=='b'，匹配成功，j++
- i=4, j=4: 'c'=='c'，匹配成功，j++
- j=5==m，找到匹配！起始位置 = i-m+1 = 4-5+1 = 0
- j = next[4] = 0，继续寻找下一个匹配

**第2轮匹配**：

- i=5, j=0: 'a'=='a'，匹配成功，j++
- i=6, j=1: 'b'=='b'，匹配成功，j++
- i=7, j=2: 'a'=='a'，匹配成功，j++
- i=8, j=3: 'b'=='b'，匹配成功，j++
- i=9, j=4: 'c'=='c'，匹配成功，j++
- j=5==m，找到匹配！起始位置 = 9-5+1 = 5
- j = next[4] = 0，继续寻找下一个匹配

**第3轮匹配**：

- i=10, j=0: 'a'=='a'，匹配成功，j++
- i=11, j=1: 'b'=='b'，匹配成功，j++
- i=12, j=2: 'c'!='a'，匹配失败！
- j = next[1] = 0，模式串跳到开头

**第4轮匹配**：

- i=12, j=0: 'c'!='a'，匹配失败！
- i++，文本指针前进

**匹配结束**，找到位置：[0, 5]

### 第四步：理解KMP的优势

假设文本串 `"aaaabaaaab"`，模式串 `"aaaab"`：

**暴力匹配**：

- 第1次匹配失败后，文本指针回退到位置1
- 第2次匹配失败后，文本指针回退到位置2
- ... 大量重复比较

**KMP匹配**：

- 文本指针永不回退，只向前移动
- 利用next数组，模式串智能跳转
- 避免了所有重复比较

## next数组构建

```cpp
vector<int> buildNext(const string& pattern) {
    int m = pattern.length();
    vector<int> next(m, 0);
    int j = 0;  // 前缀指针

    for (int i = 1; i < m; i++) {
        // 不匹配时，回退到前一个匹配位置
        while (j > 0 && pattern[i] != pattern[j]) {
            j = next[j - 1];
        }

        // 匹配成功，j向前移动
        if (pattern[i] == pattern[j]) {
            j++;
        }

        next[i] = j;
    }

    return next;
}
```

## 匹配过程

```cpp
vector<int> kmpSearch(const string& text, const string& pattern) {
    vector<int> positions;
    int n = text.length();
    int m = pattern.length();

    if (m == 0) return positions;

    vector<int> next = buildNext(pattern);
    int j = 0;  // 模式串指针

    for (int i = 0; i < n; i++) {
        // 不匹配时，利用next数组回退
        while (j > 0 && text[i] != pattern[j]) {
            j = next[j - 1];
        }

        // 匹配成功，j向前移动
        if (text[i] == pattern[j]) {
            j++;
        }

        // 完全匹配成功
        if (j == m) {
            positions.push_back(i - m + 1);  // 记录起始位置
            j = next[j - 1];  // 继续寻找下一个匹配
        }
    }

    return positions;
}
```

## 完整C++实现

```cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 构建next数组
vector<int> buildNext(const string& pattern) {
    int m = pattern.length();
    vector<int> next(m, 0);
    int j = 0;

    for (int i = 1; i < m; i++) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = next[j - 1];
        }

        if (pattern[i] == pattern[j]) {
            j++;
        }

        next[i] = j;
    }

    return next;
}

// KMP搜索
vector<int> kmpSearch(const string& text, const string& pattern) {
    vector<int> positions;
    int n = text.length();
    int m = pattern.length();

    if (m == 0) return positions;

    vector<int> next = buildNext(pattern);
    int j = 0;

    for (int i = 0; i < n; i++) {
        while (j > 0 && text[i] != pattern[j]) {
            j = next[j - 1];
        }

        if (text[i] == pattern[j]) {
            j++;
        }

        if (j == m) {
            positions.push_back(i - m + 1);
            j = next[j - 1];
        }
    }

    return positions;
}

int main() {
    string text = "ababcababcabc";
    string pattern = "ababc";

    vector<int> result = kmpSearch(text, pattern);

    cout << "文本: " << text << endl;
    cout << "模式: " << pattern << endl;
    cout << "匹配位置: ";
    for (int pos : result) {
        cout << pos << " ";
    }
    cout << endl;

    return 0;
}
```

## 算法复杂度分析

**时间复杂度**：

- 构建next数组：O(m)，其中m是模式串长度
- 匹配过程：O(n)，其中n是文本串长度
- 总时间复杂度：O(n + m)

**空间复杂度**：

- next数组：O(m)

## 应用场景

1. **字符串匹配**：在文本编辑器中查找关键词
2. **DNA序列匹配**：生物信息学中查找基因序列
3. **模式识别**：在大量数据中查找特定模式
4. **文本搜索**：搜索引擎中的关键词匹配

## 优化技巧

1. **next数组优化**：在某些情况下可以优化为nextval数组，进一步减少不必要的比较
2. **多模式匹配**：结合AC自动机实现多模式串匹配
3. **循环节判断**：利用next数组判断字符串是否有循环节

## 常见问题

**Q: KMP算法与暴力匹配的区别？**
A: 暴力匹配在失配时，主串指针会回溯到下一个位置重新开始匹配；而KMP算法利用next数组，主串指针不回溯，模式串指针根据next数组回退。

**Q: next数组的作用是什么？**
A: next数组记录了模式串每个位置的最长相同前后缀长度，用于在失配时确定模式串应该回退到哪个位置继续匹配。

**Q: KMP算法一定能找到所有匹配吗？**
A: 是的，KMP算法能够找到文本串中所有模式串出现的位置。

## 练习题目

1. **模板题**：实现KMP算法，在给定文本中查找模式串
2. **循环节问题**：利用next数组判断字符串的最小循环节
3. **最长公共前后缀**：求字符串每个前缀的最长公共前后缀长度
4. **多模式匹配**：扩展KMP算法处理多个模式串

# 字典树（Trie）

## 概念介绍

字典树（Trie树），又称前缀树，是一种树形数据结构，用于高效地存储和检索字符串集合中的键。它利用字符串的公共前缀来减少查询时间，最大限度地减少无谓的字符串比较。

**字典树的核心思想**：将字符串集合中的公共前缀合并，形成一个树形结构，使得每个字符串都对应从根节点到某个叶子节点（或中间节点）的唯一路径。

## 基本性质

1. **根节点不包含字符**，除根节点外每个节点都只包含一个字符
2. **从根节点到某一节点**，路径上经过的字符连接起来，即为该节点对应的字符串
3. **每个节点的所有子节点**包含的字符都不相同
4. **从根节点到某个节点的路径**，对应一个字符串的前缀

## 字典树的核心作用

### 1. 高效的字符串检索

字典树最基本的作用是提供高效的字符串查找能力。与传统的线性搜索相比，字典树具有以下优势：

- **时间复杂度优势**：查找时间复杂度为O(m)，其中m是字符串长度，与存储的字符串数量无关
- **最坏情况保证**：即使是在最坏的情况下，字典树的查找性能也不会退化
- **前缀匹配优势**：天然支持前缀匹配，这是其他数据结构难以高效实现的

### 2. 前缀相关问题的解决方案

字典树在处理前缀相关问题时具有独特优势：

- **前缀查找**：判断是否存在以某个前缀开头的字符串
- **前缀统计**：统计以某个前缀开头的字符串数量
- **前缀枚举**：枚举所有以某个前缀开头的字符串
- **最长公共前缀**：快速查找一组字符串的最长公共前缀

### 3. 空间优化

通过共享公共前缀，字典树能够显著减少存储空间：

- **公共前缀合并**：相同前缀的字符串共享路径上的节点
- **避免重复存储**：相比直接存储所有字符串，减少了冗余字符的存储
- **动态扩展**：随着字符串的添加，空间按需分配

### 4. 字典序操作

字典树天然支持字典序相关操作：

- **字典序排序**：通过中序遍历可以得到字典序排序的结果
- **范围查询**：支持查找某个字典序范围内的所有字符串
- **前驱后继**：可以高效查找某个字符串的前驱和后继

## 为什么要使用字典树？

### 传统方法的问题

假设我们要存储以下字符串：

```
{"code", "coder", "coding", "compile", "compiler", "computer"}
```

**使用传统数组存储**：

- 查找"coding"需要逐个比较
- 时间复杂度：O(n*m)，n是字符串数量，m是字符串长度
- 无法高效处理前缀相关问题

**使用哈希表存储**：

- 查找效率高，但无法利用前缀信息
- 无法高效地解决前缀相关问题
- 不支持字典序操作

**使用平衡二叉搜索树存储**：

- 查找时间复杂度：O(m*log n)
- 虽然支持字典序，但前缀操作效率不高

### 字典树的优势

1. **查找效率高**：查找时间复杂度为O(m)，m是字符串长度，与字符串数量无关
2. **前缀匹配**：天然支持前缀匹配操作，时间复杂度仍为O(m)
3. **空间效率**：通过共享公共前缀节省空间，特别是当字符串有大量公共前缀时
4. **排序友好**：中序遍历可以得到字典序排序，时间复杂度为O(总字符数)
5. **多模式匹配**：可以高效处理多个模式串的匹配问题

## 字典树与其他数据结构的对比

### 与哈希表的对比

| 特性      | 字典树     | 哈希表           |
| ------- | ------- | ------------- |
| 查找时间复杂度 | O(m)    | O(1)平均，O(n)最坏 |
| 前缀匹配    | O(m)    | 不支持           |
| 字典序遍历   | O(总字符数) | 不支持           |
| 空间复杂度   | O(总字符数) | O(字符串数量×平均长度) |
| 冲突处理    | 无冲突     | 需要处理冲突        |
| 内存局部性   | 较好      | 依赖哈希函数        |

**适用场景**：

- 字典树：需要前缀操作、字典序操作或最坏情况性能保证的场景
- 哈希表：只需要精确查找，且对平均性能要求高的场景

### 与平衡二叉搜索树的对比

| 特性      | 字典树     | 平衡二叉搜索树    |
| ------- | ------- | ---------- |
| 查找时间复杂度 | O(m)    | O(m×log n) |
| 前缀匹配    | O(m)    | O(m×log n) |
| 字典序遍历   | O(总字符数) | O(n×m)     |
| 插入/删除   | O(m)    | O(m×log n) |
| 空间复杂度   | O(总字符数) | O(n×m)     |
| 实现复杂度   | 中等      | 较高         |

**适用场景**：

- 字典树：字符串长度较短，或前缀操作频繁的场景
- 平衡二叉搜索树：需要动态维护有序性，且字符串长度较长的场景

### 与数组的对比

| 特性      | 字典树     | 数组           |
| ------- | ------- | ------------ |
| 查找时间复杂度 | O(m)    | O(n×m)       |
| 前缀匹配    | O(m)    | O(n×m)       |
| 字典序遍历   | O(总字符数) | O(n×log n×m) |
| 插入/删除   | O(m)    | O(n×m)       |
| 空间复杂度   | O(总字符数) | O(n×m)       |
| 实现复杂度   | 中等      | 简单           |

**适用场景**：

- 字典树：数据量大，查找操作频繁的场景
- 数组：数据量小，或需要简单实现的场景

### 与红黑树的对比

| 特性      | 字典树     | 红黑树        |
| ------- | ------- | ---------- |
| 查找时间复杂度 | O(m)    | O(m×log n) |
| 前缀匹配    | O(m)    | O(m×log n) |
| 字典序遍历   | O(总字符数) | O(n×m)     |
| 插入/删除   | O(m)    | O(m×log n) |
| 空间复杂度   | O(总字符数) | O(n×m)     |
| 平衡操作    | 不需要     | 需要         |

**适用场景**：

- 字典树：字符串操作为主，特别是前缀相关的场景
- 红黑树：需要平衡的树结构，但不限于字符串的场景

## 选择字典树的时机

### 适合使用字典树的场景

1. **前缀操作频繁**：需要频繁进行前缀匹配、前缀统计等操作
2. **字符串集合大**：存储大量字符串，且需要高效查找
3. **公共前缀多**：字符串集合中有大量公共前缀，可以节省空间
4. **字典序需求**：需要按字典序遍历或查找前驱后继
5. **多模式匹配**：需要同时匹配多个模式串

### 不适合使用字典树的场景

1. **内存受限**：字典树的空间开销较大，每个节点需要存储子节点指针
2. **字符串很长**：当字符串长度很大时，字典树的性能优势不明显
3. **只需要精确查找**：如果只需要精确查找，哈希表通常是更好的选择
4. **动态性要求高**：频繁的插入删除操作可能导致内存碎片
5. **字符集大**：当字符集很大时（如Unicode），字典树的空间开销会显著增加

## 字典树的基本结构

```cpp
// 字典树节点的定义
struct TrieNode {
    TrieNode* children[26];  // 假设只处理小写字母
    bool isEnd;              // 标记是否是单词结束
    int count;               // 记录以该节点结尾的单词数量
    int prefixCount;         // 记录以该节点为前缀的单词数量

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isEnd = false;
        count = 0;
        prefixCount = 0;
    }
};
```

## 基本操作

### 1. 插入操作

将一个字符串插入到字典树中。

```cpp
void insert(TrieNode* root, const string& word) {
    TrieNode* node = root;

    for (char ch : word) {
        int index = ch - 'a';  // 计算字符对应的索引

        // 如果子节点不存在，创建新节点
        if (node->children[index] == nullptr) {
            node->children[index] = new TrieNode();
        }

        node = node->children[index];
        node->prefixCount++;  // 更新前缀计数
    }

    node->isEnd = true;
    node->count++;  // 更新单词计数
}
```

**插入过程示例**

插入单词"code"：

```
步骤1：根节点 -> 'c'
步骤2：'c'节点 -> 'o'
步骤3：'o'节点 -> 'd'
步骤4：'d'节点 -> 'e'
步骤5：标记'e'节点为单词结束
```

### 2. 查找操作

查找字典树中是否存在某个字符串。

```cpp
bool search(TrieNode* root, const string& word) {
    TrieNode* node = root;

    for (char ch : word) {
        int index = ch - 'a';

        // 如果子节点不存在，单词不存在
        if (node->children[index] == nullptr) {
            return false;
        }

        node = node->children[index];
    }

    // 返回是否是单词结束
    return node->isEnd;
}
```

### 3. 前缀查找

查找是否存在以某个前缀开头的单词。

```cpp
bool startsWith(TrieNode* root, const string& prefix) {
    TrieNode* node = root;

    for (char ch : prefix) {
        int index = ch - 'a';

        if (node->children[index] == nullptr) {
            return false;
        }

        node = node->children[index];
    }

    return true;  // 前缀存在
}
```

### 4. 删除操作

从字典树中删除一个字符串。

```cpp
bool deleteWord(TrieNode* root, const string& word, int depth = 0) {
    if (!root) return false;

    // 如果到达单词末尾
    if (depth == word.length()) {
        if (root->isEnd) {
            root->isEnd = false;
            root->count--;
            return true;  // 标记删除成功
        }
        return false;  // 单词不存在
    }

    int index = word[depth] - 'a';
    TrieNode* child = root->children[index];

    if (!child) return false;  // 单词不存在

    bool shouldDeleteChild = deleteWord(child, word, depth + 1);

    // 如果应该删除子节点且子节点没有其他子节点
    if (shouldDeleteChild) {
        delete child;
        root->children[index] = nullptr;

        // 检查当前节点是否可以删除
        bool hasChildren = false;
        for (int i = 0; i < 26; i++) {
            if (root->children[i]) {
                hasChildren = true;
                break;
            }
        }

        return !hasChildren && !root->isEnd;
    }

    return false;
}
```

## 完整实现示例

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

class Trie {
private:
    struct TrieNode {
        TrieNode* children[26];
        bool isEnd;
        int count;
        int prefixCount;

        TrieNode() {
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
            isEnd = false;
            count = 0;
            prefixCount = 0;
        }

        ~TrieNode() {
            for (int i = 0; i < 26; i++) {
                delete children[i];
            }
        }
    };

    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    ~Trie() {
        delete root;
    }

    // 插入单词
    void insert(const string& word) {
        TrieNode* node = root;

        for (char ch : word) {
            int index = ch - 'a';

            if (node->children[index] == nullptr) {
                node->children[index] = new TrieNode();
            }

            node = node->children[index];
            node->prefixCount++;
        }

        node->isEnd = true;
        node->count++;
    }

    // 查找单词
    bool search(const string& word) {
        TrieNode* node = root;

        for (char ch : word) {
            int index = ch - 'a';

            if (node->children[index] == nullptr) {
                return false;
            }

            node = node->children[index];
        }

        return node->isEnd;
    }

    // 查找前缀
    bool startsWith(const string& prefix) {
        TrieNode* node = root;

        for (char ch : prefix) {
            int index = ch - 'a';

            if (node->children[index] == nullptr) {
                return false;
            }

            node = node->children[index];
        }

        return true;
    }

    // 获取以prefix为前缀的单词数量
    int countWordsWithPrefix(const string& prefix) {
        TrieNode* node = root;

        for (char ch : prefix) {
            int index = ch - 'a';

            if (node->children[index] == nullptr) {
                return 0;
            }

            node = node->children[index];
        }

        return node->prefixCount;
    }

    // 获取单词word的出现次数
    int getWordCount(const string& word) {
        TrieNode* node = root;

        for (char ch : word) {
            int index = ch - 'a';

            if (node->children[index] == nullptr) {
                return 0;
            }

            node = node->children[index];
        }

        return node->count;
    }

    // 删除单词
    bool erase(const string& word) {
        return deleteHelper(root, word, 0);
    }

private:
    bool deleteHelper(TrieNode* node, const string& word, int depth) {
        if (depth == word.length()) {
            if (!node->isEnd) return false;

            node->isEnd = false;
            node->count--;
            return true;
        }

        int index = word[depth] - 'a';
        TrieNode* child = node->children[index];

        if (!child) return false;

        bool shouldDeleteChild = deleteHelper(child, word, depth + 1);

        if (shouldDeleteChild) {
            delete child;
            node->children[index] = nullptr;

            bool hasChildren = false;
            for (int i = 0; i < 26; i++) {
                if (node->children[i]) {
                    hasChildren = true;
                    break;
                }
            }

            return !hasChildren && !node->isEnd;
        }

        return false;
    }
};

int main() {
    Trie trie;

    // 插入单词
    trie.insert("hello");
    trie.insert("world");
    trie.insert("help");
    trie.insert("helper");
    trie.insert("helicopter");

    // 测试查找
    cout << "查找 'hello': " << (trie.search("hello") ? "存在" : "不存在") << endl;
    cout << "查找 'word': " << (trie.search("word") ? "存在" : "不存在") << endl;

    // 测试前缀查找
    cout << "前缀 'hel': " << (trie.startsWith("hel") ? "存在" : "不存在") << endl;
    cout << "前缀 'xyz': " << (trie.startsWith("xyz") ? "存在" : "不存在") << endl;

    // 统计前缀单词数量
    cout << "以 'hel' 为前缀的单词数量: " << trie.countWordsWithPrefix("hel") << endl;
    cout << "以 'help' 为前缀的单词数量: " << trie.countWordsWithPrefix("help") << endl;

    // 获取单词出现次数
    cout << "'hello' 出现次数: " << trie.getWordCount("hello") << endl;

    // 删除单词
    trie.erase("hello");
    cout << "删除 'hello' 后查找: " << (trie.search("hello") ? "存在" : "不存在") << endl;

    return 0;
}
```

## 高级应用

### 1. 前缀匹配搜索

实现类似搜索引擎的自动补全功能。

```cpp
vector<string> getAllWordsWithPrefix(TrieNode* root, const string& prefix) {
    vector<string> result;
    TrieNode* node = root;

    // 先找到前缀对应的节点
    for (char ch : prefix) {
        int index = ch - 'a';
        if (node->children[index] == nullptr) {
            return result;  // 前缀不存在
        }
        node = node->children[index];
    }

    // 从该节点开始收集所有单词
    collectWords(node, prefix, result);
    return result;
}

void collectWords(TrieNode* node, string current, vector<string>& result) {
    if (node->isEnd) {
        result.push_back(current);
    }

    for (int i = 0; i < 26; i++) {
        if (node->children[i]) {
            collectWords(node->children[i], current + char('a' + i), result);
        }
    }
}
```

### 2. 字典序排序

通过中序遍历字典树实现字典序排序。

```cpp
void printWordsInOrder(TrieNode* node, string current) {
    if (node->isEnd) {
        cout << current << endl;
    }

    for (int i = 0; i < 26; i++) {
        if (node->children[i]) {
            printWordsInOrder(node->children[i], current + char('a' + i));
        }
    }
}
```

### 3. 最长公共前缀

查找一组字符串的最长公共前缀。

```cpp
string findLongestCommonPrefix(vector<string>& words) {
    if (words.empty()) return "";

    Trie trie;
    for (const string& word : words) {
        trie.insert(word);
    }

    string prefix = "";
    TrieNode* node = trie.root;

    while (true) {
        int childCount = 0;
        int nextIndex = -1;

        for (int i = 0; i < 26; i++) {
            if (node->children[i]) {
                childCount++;
                nextIndex = i;
            }
        }

        // 如果只有一个子节点且不是单词结束，继续
        if (childCount == 1 && !node->isEnd) {
            prefix += char('a' + nextIndex);
            node = node->children[nextIndex];
        } else {
            break;
        }
    }

    return prefix;
}
```

## 优化技巧

### 1. 空间优化：压缩字典树

对于具有许多单分支节点的字典树，可以使用压缩字典树来节省空间。

```cpp
struct CompressedTrieNode {
    map<string, CompressedTrieNode*> children;  // 使用字符串作为键
    bool isEnd;

    CompressedTrieNode() : isEnd(false) {}
};
```

### 2. 数组优化

使用数组代替指针可以提高缓存效率。

```cpp
class ArrayTrie {
private:
    static const int MAXNODES = 100000;
    static const int ALPHABET = 26;

    int children[MAXNODES][ALPHABET];
    bool isEnd[MAXNODES];
    int nodeCount;

public:
    ArrayTrie() {
        memset(children, -1, sizeof(children));
        memset(isEnd, false, sizeof(isEnd));
        nodeCount = 1;  // 节点0是根节点
    }

    void insert(const string& word) {
        int current = 0;

        for (char ch : word) {
            int index = ch - 'a';
            if (children[current][index] == -1) {
                children[current][index] = nodeCount++;
            }
            current = children[current][index];
        }

        isEnd[current] = true;
    }

    bool search(const string& word) {
        int current = 0;

        for (char ch : word) {
            int index = ch - 'a';
            if (children[current][index] == -1) {
                return false;
            }
            current = children[current][index];
        }

        return isEnd[current];
    }
};
```

## 复杂度分析

### 时间复杂度

- **插入操作**：O(m)，其中m是字符串长度
- **查找操作**：O(m)，其中m是字符串长度
- **前缀查找**：O(m)，其中m是前缀长度
- **删除操作**：O(m)，其中m是字符串长度

### 空间复杂度

- **最坏情况**：O(N*M)，其中N是单词数量，M是平均单词长度
- **最好情况**：O(M)，当所有单词共享公共前缀时

## 应用场景

### 日常应用

1. **搜索引擎自动补全**：根据用户输入提供搜索建议
2. **拼写检查**：检查单词拼写是否正确
3. **IP路由表**：最长前缀匹配
4. **字典实现**：高效的单词查找和管理
5. **模式匹配**：多模式字符串匹配
6. **基因序列分析**：DNA序列的存储和查询

### 信奥竞赛中的典型应用场景

#### 1. 字符串统计问题

**题目类型**：统计给定前缀的单词数量、统计出现频率最高的单词等

**应用示例**：

```cpp
// 统计以某个前缀开头的单词数量
int countPrefixWords(TrieNode* root, const string& prefix) {
    TrieNode* node = root;
    for (char ch : prefix) {
        int index = ch - 'a';
        if (node->children[index] == nullptr) {
            return 0;
        }
        node = node->children[index];
    }
    return node->prefixCount;
}
```

#### 2. 前缀匹配问题

**题目类型**：查找所有以给定前缀开头的单词、查找最长公共前缀等

**应用示例**：

```cpp
// 查找所有以prefix为前缀的单词
vector<string> findWordsWithPrefix(TrieNode* root, const string& prefix) {
    vector<string> result;
    TrieNode* node = root;

    // 找到前缀对应的节点
    for (char ch : prefix) {
        int index = ch - 'a';
        if (node->children[index] == nullptr) {
            return result;
        }
        node = node->children[index];
    }

    // 收集所有单词
    collectAllWords(node, prefix, result);
    return result;
}
```

#### 3. 最大异或对问题

**题目类型**：在给定的数组中，找到两个数的异或值最大

**应用示例**：

```cpp
// 01字典树节点
struct XORTrieNode {
    XORTrieNode* children[2];
    XORTrieNode() {
        children[0] = children[1] = nullptr;
    }
};

// 插入数字到01字典树
void insert(XORTrieNode* root, int num) {
    XORTrieNode* node = root;
    for (int i = 30; i >= 0; i--) {
        int bit = (num >> i) & 1;
        if (node->children[bit] == nullptr) {
            node->children[bit] = new XORTrieNode();
        }
        node = node->children[bit];
    }
}

// 查找最大异或值
int findMaxXOR(XORTrieNode* root, int num) {
    XORTrieNode* node = root;
    int maxXOR = 0;
    for (int i = 30; i >= 0; i--) {
        int bit = (num >> i) & 1;
        int toggleBit = 1 - bit;
        if (node->children[toggleBit] != nullptr) {
            maxXOR += (1 << i);
            node = node->children[toggleBit];
        } else {
            node = node->children[bit];
        }
    }
    return maxXOR;
}
```

#### 4. 单词接龙问题

**题目类型**：给定起始单词和结束单词，找到最短的转换序列

**应用示例**：

```cpp
// 使用字典树优化单词查找
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        Trie trie;
        for (const string& word : wordList) {
            trie.insert(word);
        }

        if (!trie.search(endWord)) return 0;

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            if (curr.first == endWord) return curr.second;

            // 生成所有可能的下一个单词
            for (int i = 0; i < curr.first.size(); i++) {
                char original = curr.first[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    if (c == original) continue;
                    curr.first[i] = c;
                    if (trie.search(curr.first)) {
                        q.push({curr.first, curr.second + 1});
                        trie.erase(curr.first);  // 避免重复访问
                    }
                }
                curr.first[i] = original;
            }
        }

        return 0;
    }
};
```

#### 5. 多模式串匹配问题

**题目类型**：在文本中同时查找多个模式串

**应用示例**：

```cpp
// AC自动机（基于字典树的多模式匹配算法）
struct ACMNode {
    ACMNode* children[26];
    ACMNode* fail;
    vector<int> output;

    ACMNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        fail = nullptr;
    }
};

// 构建AC自动机
void buildACAutomaton(ACMNode* root, vector<string>& patterns) {
    // 构建字典树
    for (int i = 0; i < patterns.size(); i++) {
        ACMNode* node = root;
        for (char ch : patterns[i]) {
            int index = ch - 'a';
            if (node->children[index] == nullptr) {
                node->children[index] = new ACMNode();
            }
            node = node->children[index];
        }
        node->output.push_back(i);
    }

    // 构建失败指针
    queue<ACMNode*> q;
    for (int i = 0; i < 26; i++) {
        if (root->children[i] != nullptr) {
            root->children[i]->fail = root;
            q.push(root->children[i]);
        }
    }

    while (!q.empty()) {
        ACMNode* current = q.front();
        q.pop();

        for (int i = 0; i < 26; i++) {
            if (current->children[i] != nullptr) {
                ACMNode* child = current->children[i];
                ACMNode* failNode = current->fail;

                while (failNode != nullptr && failNode->children[i] == nullptr) {
                    failNode = failNode->fail;
                }

                if (failNode == nullptr) {
                    child->fail = root;
                } else {
                    child->fail = failNode->children[i];
                }

                child->output.insert(child->output.end(), 
                                   child->fail->output.begin(), 
                                   child->fail->output.end());

                q.push(child);
            }
        }
    }
}
```

#### 6. 字符串变换问题

**题目类型**：通过插入、删除、替换操作将一个字符串变为另一个字符串的最小操作数

**应用示例**：

```cpp
// 使用字典树优化编辑距离计算
class EditDistanceTrie {
private:
    struct TrieNode {
        TrieNode* children[26];
        bool isEnd;

        TrieNode() {
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
            isEnd = false;
        }
    };

    TrieNode* root;

public:
    void insert(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (node->children[index] == nullptr) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEnd = true;
    }

    // 查找编辑距离不超过k的单词
    vector<string> findWordsWithinEditDistance(const string& word, int k) {
        vector<string> result;
        vector<vector<int>> dp(word.size() + 1, vector<int>(1, 0));

        for (int i = 0; i <= word.size(); i++) {
            dp[i][0] = i;
        }

        searchHelper(root, word, dp, result);
        return result;
    }

private:
    void searchHelper(TrieNode* node, const string& word, 
                      vector<vector<int>>& dp, vector<string>& result, 
                      string current = "") {
        if (node->isEnd && dp[word.size()][0] <= 2) {
            result.push_back(current);
        }

        for (int i = 0; i < 26; i++) {
            if (node->children[i] != nullptr) {
                char ch = 'a' + i;
                vector<vector<int>> newDP(word.size() + 1, vector<int>(dp[0].size() + 1, 0));

                newDP[0][0] = dp[0][0] + 1;

                for (int j = 1; j <= word.size(); j++) {
                    newDP[j][0] = dp[j][0] + 1;
                    newDP[0][j] = j;
                }

                for (int j = 1; j <= word.size(); j++) {
                    int cost = (word[j-1] == ch) ? 0 : 1;
                    newDP[j][1] = min({dp[j-1][1] + 1,        // 删除
                                      dp[j][0] + 1,           // 插入
                                      dp[j-1][0] + cost});     // 替换
                }

                searchHelper(node->children[i], word, newDP, result, current + ch);
            }
        }
    }
};
```

### 竞赛技巧与优化

#### 1. 空间优化技巧

**使用数组代替指针**：

```cpp
class ArrayTrie {
private:
    static const int MAXNODES = 100000;
    static const int ALPHABET = 26;

    int children[MAXNODES][ALPHABET];
    bool isEnd[MAXNODES];
    int nodeCount;

public:
    ArrayTrie() {
        memset(children, -1, sizeof(children));
        memset(isEnd, false, sizeof(isEnd));
        nodeCount = 1;
    }

    void insert(const string& word) {
        int current = 0;
        for (char ch : word) {
            int index = ch - 'a';
            if (children[current][index] == -1) {
                children[current][index] = nodeCount++;
            }
            current = children[current][index];
        }
        isEnd[current] = true;
    }
};
```

#### 2. 位优化技巧

**使用位掩码表示子节点**：

```cpp
struct BitTrieNode {
    int children;  // 26位掩码，每一位表示一个子节点是否存在
    bool isEnd;

    BitTrieNode() : children(0), isEnd(false) {}

    bool hasChild(char ch) {
        return children & (1 << (ch - 'a'));
    }

    void setChild(char ch) {
        children |= (1 << (ch - 'a'));
    }

    void clearChild(char ch) {
        children &= ~(1 << (ch - 'a'));
    }
};
```

#### 3. 内存池优化

**使用内存池减少动态内存分配**：

```cpp
class MemoryPoolTrie {
private:
    struct TrieNode {
        TrieNode* children[26];
        bool isEnd;

        static TrieNode* create() {
            static TrieNode pool[100000];
            static int poolIndex = 0;
            return &pool[poolIndex++];
        }
    };

    TrieNode* root;

public:
    MemoryPoolTrie() {
        root = TrieNode::create();
    }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (node->children[index] == nullptr) {
                node->children[index] = TrieNode::create();
            }
            node = node->children[index];
        }
        node->isEnd = true;
    }
};
```

### 常见竞赛题型总结

1. **前缀统计类**：统计以某个前缀开头的单词数量
2. **最大异或类**：在数组中找到异或值最大的数对
3. **多模式匹配类**：在文本中同时查找多个模式串
4. **字符串变换类**：通过最少操作将一个字符串变为另一个
5. **字典序相关类**：查找字典序第k小的单词、前驱后继等
6. **单词接龙类**：找到单词之间的最短转换路径

## 字典树的变体和扩展应用

### 1. 01字典树（二进制字典树）

01字典树是专门用于处理二进制数的字典树，常用于解决最大异或对问题。

```cpp
class BinaryTrie {
private:
    struct Node {
        Node* children[2];
        int count;

        Node() {
            children[0] = children[1] = nullptr;
            count = 0;
        }
    };

    Node* root;

public:
    BinaryTrie() {
        root = new Node();
    }

    void insert(int num) {
        Node* node = root;
        for (int i = 30; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node->children[bit] == nullptr) {
                node->children[bit] = new Node();
            }
            node = node->children[bit];
            node->count++;
        }
    }

    void remove(int num) {
        Node* node = root;
        for (int i = 30; i >= 0; i--) {
            int bit = (num >> i) & 1;
            node = node->children[bit];
            node->count--;
        }
    }

    int findMaxXOR(int num) {
        Node* node = root;
        int maxXOR = 0;

        for (int i = 30; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int toggleBit = 1 - bit;

            if (node->children[toggleBit] != nullptr && 
                node->children[toggleBit]->count > 0) {
                maxXOR += (1 << i);
                node = node->children[toggleBit];
            } else {
                node = node->children[bit];
            }
        }

        return maxXOR;
    }

    // 查找小于等于num的最大数
    int findMaxLessOrEqual(int num) {
        Node* node = root;
        int result = 0;

        for (int i = 30; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if (bit == 1 && node->children[0] != nullptr && 
                node->children[0]->count > 0) {
                node = node->children[0];
            } else if (node->children[bit] != nullptr && 
                      node->children[bit]->count > 0) {
                result |= (bit << i);
                node = node->children[bit];
            } else {
                return -1;  // 没有找到
            }
        }

        return result;
    }
};
```

### 2. 压缩字典树（Radix Tree）

压缩字典树通过将单路径节点合并来节省空间。

```cpp
class CompressedTrie {
private:
    struct Node {
        map<string, Node*> children;
        bool isEnd;

        Node() : isEnd(false) {}
    };

    Node* root;

public:
    CompressedTrie() {
        root = new Node();
    }

    void insert(const string& word) {
        Node* node = root;
        string remaining = word;

        while (!remaining.empty()) {
            bool found = false;

            for (auto& [edge, child] : node->children) {
                int commonPrefix = getCommonPrefix(remaining, edge);

                if (commonPrefix > 0) {
                    if (commonPrefix == edge.length()) {
                        // 完全匹配现有边
                        remaining = remaining.substr(commonPrefix);
                        node = child;
                        found = true;
                        break;
                    } else if (commonPrefix < edge.length()) {
                        // 需要分割现有边
                        Node* newNode = new Node();
                        Node* splitNode = new Node();

                        string splitEdge = edge.substr(commonPrefix);
                        splitNode->children = child->children;
                        splitNode->isEnd = child->isEnd;

                        newNode->children[splitEdge] = splitNode;
                        newNode->isEnd = (commonPrefix == remaining.length());

                        node->children.erase(edge);
                        node->children[edge.substr(0, commonPrefix)] = newNode;

                        if (commonPrefix < remaining.length()) {
                            remaining = remaining.substr(commonPrefix);
                            node = newNode;
                        }

                        found = true;
                        break;
                    }
                }
            }

            if (!found) {
                node->children[remaining] = new Node();
                node->children[remaining]->isEnd = true;
                break;
            }
        }
    }

private:
    int getCommonPrefix(const string& str1, const string& str2) {
        int common = 0;
        int minLength = min(str1.length(), str2.length());

        while (common < minLength && str1[common] == str2[common]) {
            common++;
        }

        return common;
    }
};
```

### 3. 持久化字典树

持久化字典树支持版本控制，可以访问历史版本的数据。

```cpp
class PersistentTrie {
private:
    struct Node {
        Node* children[26];
        bool isEnd;
        int version;

        Node() {
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
            isEnd = false;
            version = 0;
        }

        Node(const Node* other, int newVersion) {
            for (int i = 0; i < 26; i++) {
                children[i] = other->children[i];
            }
            isEnd = other->isEnd;
            version = newVersion;
        }
    };

    vector<Node*> roots;  // 每个版本的根节点
    int currentVersion;

public:
    PersistentTrie() {
        roots.push_back(new Node());
        currentVersion = 0;
    }

    void insert(const string& word) {
        Node* newRoot = new Node(roots[currentVersion], currentVersion + 1);
        Node* node = newRoot;

        for (char ch : word) {
            int index = ch - 'a';

            if (node->children[index] == nullptr || 
                node->children[index]->version <= currentVersion) {
                // 创建新版本节点
                Node* newNode = new Node();
                newNode->version = currentVersion + 1;
                node->children[index] = newNode;
            } else if (node->children[index]->version == currentVersion + 1) {
                // 已经是最新版本，无需创建
            } else {
                // 需要复制现有节点
                node->children[index] = new Node(node->children[index], currentVersion + 1);
            }

            node = node->children[index];
        }

        node->isEnd = true;
        roots.push_back(newRoot);
        currentVersion++;
    }

    bool search(const string& word, int version = -1) {
        if (version == -1) {
            version = currentVersion;
        }

        if (version >= roots.size()) {
            return false;
        }

        Node* node = roots[version];

        for (char ch : word) {
            int index = ch - 'a';

            if (node->children[index] == nullptr || 
                node->children[index]->version > version) {
                return false;
            }

            node = node->children[index];
        }

        return node->isEnd;
    }

    int getVersionCount() {
        return currentVersion + 1;
    }
};
```

### 4. AC自动机（Aho-Corasick算法）

AC自动机是基于字典树的多模式匹配算法。

```cpp
class AhoCorasick {
private:
    struct Node {
        Node* children[26];
        Node* fail;
        vector<int> output;

        Node() {
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
            fail = nullptr;
        }
    };

    Node* root;
    vector<int> patternLengths;

public:
    AhoCorasick() {
        root = new Node();
    }

    void insert(const string& pattern, int patternId) {
        Node* node = root;

        for (char ch : pattern) {
            int index = ch - 'a';
            if (node->children[index] == nullptr) {
                node->children[index] = new Node();
            }
            node = node->children[index];
        }

        node->output.push_back(patternId);
        patternLengths.push_back(pattern.length());
    }

    void buildFailureLinks() {
        queue<Node*> q;

        // 初始化第一层节点的失败指针
        for (int i = 0; i < 26; i++) {
            if (root->children[i] != nullptr) {
                root->children[i]->fail = root;
                q.push(root->children[i]);
            }
        }

        // BFS构建失败指针
        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            for (int i = 0; i < 26; i++) {
                if (current->children[i] != nullptr) {
                    Node* child = current->children[i];
                    Node* failNode = current->fail;

                    // 找到失败指针
                    while (failNode != nullptr && failNode->children[i] == nullptr) {
                        failNode = failNode->fail;
                    }

                    if (failNode == nullptr) {
                        child->fail = root;
                    } else {
                        child->fail = failNode->children[i];
                        // 合并输出模式
                        child->output.insert(child->output.end(), 
                                           child->fail->output.begin(), 
                                           child->fail->output.end());
                    }

                    q.push(child);
                }
            }
        }
    }

    vector<pair<int, int>> search(const string& text) {
        vector<pair<int, int>> result;  // (位置, 模式ID)
        Node* current = root;

        for (int i = 0; i < text.length(); i++) {
            int index = text[i] - 'a';

            // 找到下一个匹配的节点
            while (current != nullptr && current->children[index] == nullptr) {
                current = current->fail;
            }

            if (current == nullptr) {
                current = root;
                continue;
            }

            current = current->children[index];

            // 输出所有匹配的模式
            for (int patternId : current->output) {
                result.push_back({i - patternLengths[patternId] + 1, patternId});
            }
        }

        return result;
    }
};
```

### 5. 字典树的高级优化技巧

#### 空间优化：双数组字典树

```cpp
class DoubleArrayTrie {
private:
    vector<int> base;
    vector<int> check;
    int size;

public:
    DoubleArrayTrie(int maxSize = 100000) {
        base.resize(maxSize, 0);
        check.resize(maxSize, -1);
        size = 1;
        base[0] = 1;
        check[0] = -1;
    }

    void insert(const string& word) {
        int currentState = 0;
        int i = 0;

        while (i < word.length()) {
            char c = word[i];
            int next = base[currentState] + (c - 'a' + 1);

            if (next >= base.size()) {
                int newSize = base.size() * 2;
                base.resize(newSize, 0);
                check.resize(newSize, -1);
            }

            if (check[next] == -1) {
                check[next] = currentState;
                base[next] = -1;
                currentState = next;
                i++;
            } else if (check[next] == currentState) {
                currentState = next;
                i++;
            } else {
                resolveConflict(currentState, c);
                currentState = 0;
                i = 0;
            }
        }

        base[currentState] = 0;  // 终止状态
    }

    bool search(const string& word) {
        int currentState = 0;

        for (char c : word) {
            int next = base[currentState] + (c - 'a' + 1);

            if (next >= base.size() || check[next] != currentState) {
                return false;
            }

            currentState = next;
        }

        return base[currentState] == 0;
    }

private:
    void resolveConflict(int state, char c) {
        // 冲突解决逻辑
        // 这里简化实现，实际需要更复杂的算法
    }
};
```

### 总结

字典树的变体和扩展应用极大地丰富了其使用场景：

1. **01字典树**：专门处理二进制数，解决异或相关问题
2. **压缩字典树**：通过路径压缩节省空间
3. **持久化字典树**：支持版本控制，处理历史数据查询
4. **AC自动机**：多模式匹配的高效解决方案
5. **双数组字典树**：极高的空间效率，适合大规模数据

这些变体在不同的应用场景中各有优势，选择合适的变体可以显著提高算法的效率和性能。

## 练习题目

1. **基础题**：实现字典树的基本操作（插入、查找、删除）
2. **前缀统计**：统计以某个前缀开头的单词数量
3. **自动补全**：实现搜索引擎的自动补全功能
4. **异或字典树**：实现支持异或操作的字典树
5. **持久化字典树**：实现支持版本控制的字典树

# C++类(Class)的应用

## 封装(Encapsulation)

### 概念

封装是面向对象编程的基本特性之一，它将数据和操作数据的方法捆绑在一起，隐藏对象的内部实现细节，只对外提供公共接口。

### 访问修饰符

- `public`: 公共成员，可以在任何地方访问
- `private`: 私有成员，只能在类内部访问
- `protected`: 保护成员，可以在类内部和派生类中访问

### 示例代码

```cpp
#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int age;
    double score;

public:
    // 构造函数
    Student(string n, int a, double s) {
        name = n;
        age = a;
        score = s;
    }

    // 公共接口方法
    void setName(string n) {
        name = n;
    }

    string getName() {
        return name;
    }

    void setAge(int a) {
        if (a > 0) {  // 数据验证
            age = a;
        }
    }

    int getAge() {
        return age;
    }

    void setScore(double s) {
        if (s >= 0 && s <= 100) {  // 数据验证
            score = s;
        }
    }

    double getScore() {
        return score;
    }

    void displayInfo() {
        cout << "姓名: " << name << ", 年龄: " << age << ", 分数: " << score << endl;
    }
};

int main() {
    Student stu("张三", 18, 95.5);
    stu.displayInfo();

    stu.setAge(19);
    stu.setScore(88.0);
    stu.displayInfo();

    return 0;
}
```

### 封装的优势

1. **数据保护**: 防止外部代码直接修改对象的内部状态
2. **数据验证**: 在setter方法中添加数据验证逻辑
3. **代码维护**: 修改内部实现不会影响外部代码
4. **提高安全性**: 隐藏实现细节，降低耦合度

## 继承(Inheritance)

### 概念

继承允许一个类(派生类)获取另一个类(基类)的属性和方法，实现代码重用和扩展。

### 继承语法

```cpp
class 派生类 : 继承方式 基类 {
    // 派生类的新成员
};
```

### 继承方式

- `public继承`: 基类的public成员在派生类中仍为public，protected成员仍为protected
- `protected继承`: 基类的public和protected成员在派生类中都变为protected
- `private继承`: 基类的public和protected成员在派生类中都变为private

### 示例代码

```cpp
#include <iostream>
#include <string>
using namespace std;

// 基类：动物
class Animal {
protected:
    string name;
    int age;

public:
    Animal(string n, int a) : name(n), age(a) {}

    void eat() {
        cout << name << "正在吃东西" << endl;
    }

    void sleep() {
        cout << name << "正在睡觉" << endl;
    }

    virtual void makeSound() {  // 虚函数，为多态做准备
        cout << name << "发出声音" << endl;
    }
};

// 派生类：狗
class Dog : public Animal {
private:
    string breed;

public:
    Dog(string n, int a, string b) : Animal(n, a), breed(b) {}

    void bark() {
        cout << name << "汪汪叫" << endl;
    }

    void makeSound() override {  // 重写虚函数
        cout << name << "汪汪汪！" << endl;
    }

    void displayInfo() {
        cout << "狗的名字: " << name << ", 年龄: " << age << ", 品种: " << breed << endl;
    }
};

// 派生类：猫
class Cat : public Animal {
private:
    bool isIndoor;

public:
    Cat(string n, int a, bool indoor) : Animal(n, a), isIndoor(indoor) {}

    void meow() {
        cout << name << "喵喵叫" << endl;
    }

    void makeSound() override {  // 重写虚函数
        cout << name << "喵喵喵！" << endl;
    }

    void displayInfo() {
        cout << "猫的名字: " << name << ", 年龄: " << age 
             << ", 是否室内猫: " << (isIndoor ? "是" : "否") << endl;
    }
};

int main() {
    Dog dog("旺财", 3, "金毛");
    Cat cat("咪咪", 2, true);

    dog.eat();     // 继承自基类的方法
    dog.sleep();   // 继承自基类的方法
    dog.bark();    // 派生类特有的方法
    dog.makeSound(); // 重写的方法
    dog.displayInfo();

    cout << "--------------------" << endl;

    cat.eat();     // 继承自基类的方法
    cat.sleep();   // 继承自基类的方法
    cat.meow();    // 派生类特有的方法
    cat.makeSound(); // 重写的方法
    cat.displayInfo();

    return 0;
}
```

### 继承的优势

1. **代码重用**: 避免重复编写相同的代码
2. **逻辑层次**: 建立清晰的类层次结构
3. **扩展性**: 可以在不修改基类的情况下扩展功能
4. **多态基础**: 为实现多态提供基础

## 多态(Polymorphism)

### 概念

多态允许不同类的对象对相同的消息做出不同的响应，主要通过虚函数实现。

### 多态的类型

1. **编译时多态**: 函数重载、运算符重载
2. **运行时多态**: 虚函数实现

### 虚函数

- 使用`virtual`关键字声明
- 在派生类中使用`override`关键字重写
- 通过基类指针或引用调用时，会根据实际对象类型调用相应函数

### 纯虚函数和抽象类

- 纯虚函数：`virtual void functionName() = 0;`
- 包含纯虚函数的类称为抽象类
- 抽象类不能实例化，只能作为基类

### 示例代码

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 抽象基类：图形
class Shape {
protected:
    string name;

public:
    Shape(string n) : name(n) {}

    virtual ~Shape() {}  // 虚析构函数，确保正确释放派生类对象

    // 纯虚函数
    virtual double getArea() = 0;
    virtual double getPerimeter() = 0;

    // 普通虚函数
    virtual void display() {
        cout << "这是一个" << name << endl;
    }
};

// 派生类：圆形
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : Shape("圆形"), radius(r) {}

    double getArea() override {
        return 3.14159 * radius * radius;
    }

    double getPerimeter() override {
        return 2 * 3.14159 * radius;
    }

    void display() override {
        cout << "圆形，半径: " << radius << endl;
        cout << "面积: " << getArea() << ", 周长: " << getPerimeter() << endl;
    }
};

// 派生类：矩形
class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(double w, double h) : Shape("矩形"), width(w), height(h) {}

    double getArea() override {
        return width * height;
    }

    double getPerimeter() override {
        return 2 * (width + height);
    }

    void display() override {
        cout << "矩形，宽: " << width << ", 高: " << height << endl;
        cout << "面积: " << getArea() << ", 周长: " << getPerimeter() << endl;
    }
};

// 派生类：三角形
class Triangle : public Shape {
private:
    double a, b, c;

public:
    Triangle(double side1, double side2, double side3) 
        : Shape("三角形"), a(side1), b(side2), c(side3) {}

    double getArea() override {
        // 使用海伦公式
        double s = getPerimeter() / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    double getPerimeter() override {
        return a + b + c;
    }

    void display() override {
        cout << "三角形，边长: " << a << ", " << b << ", " << c << endl;
        cout << "面积: " << getArea() << ", 周长: " << getPerimeter() << endl;
    }
};

// 多态应用：计算所有图形的总面积
double calculateTotalArea(vector<Shape*>& shapes) {
    double total = 0;
    for (Shape* shape : shapes) {
        total += shape->getArea();
    }
    return total;
}

int main() {
    // 创建不同类型的图形对象
    Circle circle(5.0);
    Rectangle rectangle(4.0, 6.0);
    Triangle triangle(3.0, 4.0, 5.0);

    // 使用基类指针数组存储不同派生类对象
    vector<Shape*> shapes;
    shapes.push_back(&circle);
    shapes.push_back(&rectangle);
    shapes.push_back(&triangle);

    // 多态调用：根据实际对象类型调用相应的函数
    cout << "=== 多态演示 ===" << endl;
    for (Shape* shape : shapes) {
        shape->display();
        cout << "--------------------" << endl;
    }

    // 计算总面积
    double totalArea = calculateTotalArea(shapes);
    cout << "所有图形的总面积: " << totalArea << endl;

    return 0;
}
```

### 运算符重载示例

```cpp
#include <iostream>
using namespace std;

class Complex {
private:
    double real, imag;

public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // 运算符重载：加法
    Complex operator+(const Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }

    // 运算符重载：减法
    Complex operator-(const Complex& other) {
        return Complex(real - other.real, imag - other.imag);
    }

    // 运算符重载：乘法
    Complex operator*(const Complex& other) {
        return Complex(real * other.real - imag * other.imag,
                      real * other.imag + imag * other.real);
    }

    // 运算符重载：输出
    friend ostream& operator<<(ostream& os, const Complex& c) {
        os << c.real;
        if (c.imag >= 0) os << "+";
        os << c.imag << "i";
        return os;
    }

    // 运算符重载：输入
    friend istream& operator>>(istream& is, Complex& c) {
        is >> c.real >> c.imag;
        return is;
    }
};

int main() {
    Complex c1(3.0, 4.0);
    Complex c2(1.0, 2.0);

    Complex sum = c1 + c2;
    Complex diff = c1 - c2;
    Complex product = c1 * c2;

    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;
    cout << "c1 + c2 = " << sum << endl;
    cout << "c1 - c2 = " << diff << endl;
    cout << "c1 * c2 = " << product << endl;

    return 0;
}
```

### 多态的优势

1. **灵活性**: 同一个接口可以处理不同类型的对象
2. **扩展性**: 添加新的派生类不需要修改现有代码
3. **代码简洁**: 减少条件判断，提高代码可读性
4. **解耦**: 降低模块间的耦合度

## 综合应用示例

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

// 抽象基类：员工
class Employee {
protected:
    string name;
    int id;
    double baseSalary;

public:
    Employee(string n, int i, double salary) 
        : name(n), id(i), baseSalary(salary) {}

    virtual ~Employee() {}

    virtual double calculateSalary() = 0;  // 纯虚函数

    virtual void displayInfo() {
        cout << "姓名: " << name << ", 工号: " << id;
    }
};

// 派生类：普通员工
class RegularEmployee : public Employee {
public:
    RegularEmployee(string n, int i, double salary) 
        : Employee(n, i, salary) {}

    double calculateSalary() override {
        return baseSalary;
    }

    void displayInfo() override {
        Employee::displayInfo();
        cout << ", 职位: 普通员工, 工资: " << calculateSalary() << endl;
    }
};

// 派生类：经理
class Manager : public Employee {
private:
    double bonus;

public:
    Manager(string n, int i, double salary, double b) 
        : Employee(n, i, salary), bonus(b) {}

    double calculateSalary() override {
        return baseSalary + bonus;
    }

    void displayInfo() override {
        Employee::displayInfo();
        cout << ", 职位: 经理, 工资: " << calculateSalary() 
             << " (基本工资: " << baseSalary << ", 奖金: " << bonus << ")" << endl;
    }
};

// 派生类：销售员
class Salesperson : public Employee {
private:
    double commissionRate;
    double salesAmount;

public:
    Salesperson(string n, int i, double salary, double rate, double amount) 
        : Employee(n, i, salary), commissionRate(rate), salesAmount(amount) {}

    double calculateSalary() override {
        return baseSalary + salesAmount * commissionRate;
    }

    void setSalesAmount(double amount) {
        salesAmount = amount;
    }

    void displayInfo() override {
        Employee::displayInfo();
        cout << ", 职位: 销售员, 工资: " << calculateSalary() 
             << " (基本工资: " << baseSalary << ", 提成: " 
             << salesAmount * commissionRate << ")" << endl;
    }
};

// 人力资源管理系统
class HRSystem {
private:
    vector<unique_ptr<Employee>> employees;

public:
    void addEmployee(unique_ptr<Employee> emp) {
        employees.push_back(move(emp));
    }

    void displayAllEmployees() {
        cout << "=== 员工信息 ===" << endl;
        for (const auto& emp : employees) {
            emp->displayInfo();
        }
        cout << endl;
    }

    double calculateTotalSalary() {
        double total = 0;
        for (const auto& emp : employees) {
            total += emp->calculateSalary();
        }
        return total;
    }

    void updateSalespersonCommission(int id, double newAmount) {
        for (const auto& emp : employees) {
            Salesperson* sp = dynamic_cast<Salesperson*>(emp.get());
            if (sp && emp->displayInfo, id == id) {
                sp->setSalesAmount(newAmount);
                break;
            }
        }
    }
};

int main() {
    HRSystem hrSystem;

    // 添加不同类型的员工
    hrSystem.addEmployee(make_unique<RegularEmployee>("张三", 1001, 5000));
    hrSystem.addEmployee(make_unique<Manager>("李四", 1002, 8000, 2000));
    hrSystem.addEmployee(make_unique<Salesperson>("王五", 1003, 4000, 0.1, 10000));

    // 显示所有员工信息
    hrSystem.displayAllEmployees();

    // 计算总工资支出
    cout << "公司总工资支出: " << hrSystem.calculateTotalSalary() << endl;

    return 0;
}
```

## 总结

面向对象编程的三大特性：

1. **封装**: 将数据和操作数据的方法捆绑在一起，隐藏实现细节
2. **继承**: 允许一个类获取另一个类的属性和方法，实现代码重用
3. **多态**: 允许不同类的对象对相同的消息做出不同的响应

这些特性使C++程序更加模块化、可维护和可扩展，是现代软件开发的重要基础。

# 二分图

## 概念介绍

二分图（Bipartite Graph）是图论中的一个重要概念，它是一类特殊的图。一个图被称为二分图，如果它的顶点集可以被划分为两个不相交的子集，使得图中的每条边连接的两个顶点分别属于这两个不同的子集。

### 形式化定义

设图 $G=(V,E)$，如果存在顶点集 $V$ 的一个划分 $V=V_1 \cup V_2$，满足：

1. $V_1 \cap V_2 = \emptyset$（两个子集不相交）
2. 对于任意边 $(u,v) \in E$，有 $u \in V_1$ 且 $v \in V_2$，或者 $u \in V_2$ 且 $v \in V_1$

那么称图 $G$ 为二分图。

### 直观理解

二分图可以理解为"两类顶点之间的连接关系图"，同一类顶点之间没有边相连。例如：

- 男生和女生之间的朋友关系图（男生只和女生做朋友，女生只和男生做朋友）
- 工人和任务之间的分配关系图（工人只分配任务，任务只分配给工人）

### 二分图的示例

```
V1: {A, B, C}
V2: {1, 2, 3, 4}

边: (A,1), (A,2), (B,2), (B,3), (C,3), (C,4)

图示：
A --- 1
|     |
|     2
B --- |
|     3
C --- |
     |
     4
```

## 二分图的判定

### 染色法

二分图判定的最常用方法是染色法。其核心思想是：

1. 任意选择一个未染色的顶点，将其染成颜色1
2. 将其所有未染色的邻居染成颜色2
3. 将这些邻居的未染色邻居染成颜色1
4. 重复此过程，直到所有顶点都被染色
5. 如果在染色过程中发现某个顶点的邻居已经染成了相同颜色，则该图不是二分图

### 染色法实现

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 1e5 + 5;

vector<int> g[N];  // 邻接表存储图
int color[N];      // 0表示未染色，1和2表示两种颜色

// BFS染色法判断二分图
bool isBipartite(int n) {
    queue<int> q;

    // 可能存在多个连通分量，所以需要遍历所有顶点
    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) {  // 未染色
            q.push(i);
            color[i] = 1;     // 染成颜色1

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : g[u]) {
                    if (color[v] == 0) {  // 未染色，染成相反颜色
                        color[v] = 3 - color[u];  // 1变2，2变1
                        q.push(v);
                    } else if (color[v] == color[u]) {  // 已染色且颜色相同
                        return false;  // 不是二分图
                    }
                }
            }
        }
    }

    return true;  // 所有点都成功染色，是二分图
}

// DFS染色法判断二分图
bool dfs(int u, int c) {
    color[u] = c;

    for (int v : g[u]) {
        if (color[v] == 0) {  // 未染色
            if (!dfs(v, 3 - c)) {  // 染成相反颜色
                return false;
            }
        } else if (color[v] == color[u]) {  // 已染色且颜色相同
            return false;  // 不是二分图
        }
    }

    return true;
}

bool isBipartiteDFS(int n) {
    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) {  // 未染色
            if (!dfs(i, 1)) {  // 从颜色1开始染色
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n, m;  // n个顶点，m条边
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);  // 无向图
    }

    if (isBipartite(n)) {
        cout << "该图是二分图" << endl;
    } else {
        cout << "该图不是二分图" << endl;
    }

    return 0;
}
```

### 染色法的时间复杂度

- **时间复杂度**：O(N + M)，其中N是顶点数，M是边数
- **空间复杂度**：O(N + M)，用于存储图的邻接表和颜色数组

## 二分图的最大匹配

### 匹配的概念

在二分图中，**匹配**是指一组边的集合，其中任意两条边没有公共端点。**最大匹配**是指边数最多的匹配。

### 匈牙利算法

匈牙利算法是求解二分图最大匹配的经典算法，其核心思想是寻找增广路径。

#### 增广路径

增广路径是指一条从未匹配点出发，交替经过未匹配边和匹配边，最终到达另一个未匹配点的路径。通过将增广路径上的匹配边和非匹配边互换，可以增加匹配的大小。

#### 匈牙利算法实现

```cpp
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int N = 1e5 + 5;

vector<int> g[N];  // 邻接表存储二分图
int match[N];      // 记录右部顶点匹配的左部顶点
bool visited[N];   // 记录在DFS过程中是否访问过

// DFS寻找增广路径
bool dfs(int u) {
    for (int v : g[u]) {
        if (!visited[v]) {  // 如果该右部顶点本轮未访问
            visited[v] = true;

            // 如果v未匹配，或者能为v的当前匹配对象找到新的匹配
            if (match[v] == 0 || dfs(match[v])) {
                match[v] = u;  // 建立新的匹配
                return true;   // 找到增广路径
            }
        }
    }
    return false;  // 未找到增广路径
}

// 匈牙利算法求最大匹配
int hungarian(int n, int m) {
    int result = 0;  // 匹配数

    for (int i = 1; i <= n; i++) {  // 遍历左部顶点
        memset(visited, false, sizeof(visited));  // 重置访问标记

        if (dfs(i)) {  // 如果能为i找到匹配
            result++;
        }
    }

    return result;
}

int main() {
    int n, m, e;  // n个左部顶点，m个右部顶点，e条边
    cin >> n >> m >> e;

    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);  // 从左部到右部的边
    }

    int maxMatch = hungarian(n, m);
    cout << "最大匹配数: " << maxMatch << endl;

    // 输出匹配方案
    cout << "匹配方案:" << endl;
    for (int i = 1; i <= m; i++) {
        if (match[i] != 0) {
            cout << "左部顶点" << match[i] << " -> 右部顶点" << i << endl;
        }
    }

    return 0;
}
```

#### 匈牙利算法的时间复杂度

- **时间复杂度**：O(N × M)，其中N是左部顶点数，M是边数
- **空间复杂度**：O(N + M)，用于存储图的邻接表和辅助数组

## 二分图的最小点覆盖

### 最小点覆盖的概念

**点覆盖**是指一个顶点集合，使得图中的每条边至少有一个端点在该集合中。**最小点覆盖**是指顶点数最少的点覆盖。

### König定理

König定理指出：在二分图中，最大匹配数等于最小点覆盖数。

### 最小点覆盖的求解

利用König定理，我们可以通过最大匹配来求解最小点覆盖：

```cpp
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

const int N = 1e5 + 5;

vector<int> g[N];  // 邻接表存储二分图
int match[N];      // 记录右部顶点匹配的左部顶点
bool visited[N];   // 记录在DFS过程中是否访问过
bool inLeftSide[N]; // 标记左部顶点是否在最小点覆盖中
bool inRightSide[N]; // 标记右部顶点是否在最小点覆盖中

// DFS寻找增广路径
bool dfs(int u) {
    for (int v : g[u]) {
        if (!visited[v]) {
            visited[v] = true;
            if (match[v] == 0 || dfs(match[v])) {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

// BFS寻找从左部未匹配点可达的顶点
void bfs(int n) {
    queue<int> q;
    bool reachable[N] = {false};

    // 找到所有左部未匹配点，加入队列
    for (int i = 1; i <= n; i++) {
        bool isMatched = false;
        for (int j = 1; j <= n; j++) {
            if (match[j] == i) {
                isMatched = true;
                break;
            }
        }
        if (!isMatched) {
            q.push(i);
            reachable[i] = true;
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : g[u]) {
            if (!reachable[v]) {
                reachable[v] = true;

                // 如果v匹配了某个左部顶点w，则将w加入队列
                if (match[v] != 0 && !reachable[match[v]]) {
                    reachable[match[v]] = true;
                    q.push(match[v]);
                }
            }
        }
    }

    // 根据König定理构造最小点覆盖
    for (int i = 1; i <= n; i++) {
        if (!reachable[i]) {
            inLeftSide[i] = true;  // 左部不可达顶点
        }
    }

    for (int i = 1; i <= n; i++) {
        if (reachable[i]) {
            inRightSide[i] = true;  // 右部可达顶点
        }
    }
}

int main() {
    int n, m, e;  // n个左部顶点，m个右部顶点，e条边
    cin >> n >> m >> e;

    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    // 求最大匹配
    int maxMatch = 0;
    for (int i = 1; i <= n; i++) {
        memset(visited, false, sizeof(visited));
        if (dfs(i)) {
            maxMatch++;
        }
    }

    // 求最小点覆盖
    bfs(n);

    cout << "最大匹配数: " << maxMatch << endl;
    cout << "最小点覆盖数: " << maxMatch << endl;

    cout << "最小点覆盖:" << endl;
    cout << "左部顶点: ";
    for (int i = 1; i <= n; i++) {
        if (inLeftSide[i]) {
            cout << i << " ";
        }
    }
    cout << endl;

    cout << "右部顶点: ";
    for (int i = 1; i <= m; i++) {
        if (inRightSide[i]) {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}
```

## 二分图的最大独立集

### 最大独立集的概念

**独立集**是指一个顶点集合，集合中任意两个顶点之间都没有边相连。**最大独立集**是指顶点数最多的独立集。

### 最大独立集的求解

在二分图中，最大独立集与最小点覆盖之间存在互补关系：

```
最大独立集 = 所有顶点 - 最小点覆盖
```

```cpp
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int N = 1e5 + 5;

vector<int> g[N];
int match[N];
bool visited[N];

bool dfs(int u) {
    for (int v : g[u]) {
        if (!visited[v]) {
            visited[v] = true;
            if (match[v] == 0 || dfs(match[v])) {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n, m, e;
    cin >> n >> m >> e;

    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    // 求最大匹配
    int maxMatch = 0;
    for (int i = 1; i <= n; i++) {
        memset(visited, false, sizeof(visited));
        if (dfs(i)) {
            maxMatch++;
        }
    }

    // 最大独立集 = 总顶点数 - 最小点覆盖数
    // 最小点覆盖数 = 最大匹配数
    int maxIndependentSet = n + m - maxMatch;

    cout << "最大匹配数: " << maxMatch << endl;
    cout << "最大独立集大小: " << maxIndependentSet << endl;

    return 0;
}
```

## 二分图的应用

### 1. 任务分配问题

**问题描述**：有n个工人和m个任务，每个工人只能完成某些特定的任务，每个任务只能分配给一个工人。求最多能完成多少个任务。

**解题思路**：将工人作为左部顶点，任务作为右部顶点，如果工人i能完成任务j，则在工人i和任务j之间连边。问题转化为求二分图的最大匹配。

```cpp
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int N = 1e3 + 5;

vector<int> workers[N];  // 工人能完成的任务列表
int taskMatch[N];        // 任务匹配的工人
bool visited[N];        // 访问标记

bool dfs(int worker, int m) {
    for (int task : workers[worker]) {
        if (!visited[task]) {
            visited[task] = true;

            // 如果任务未分配，或者能为当前任务的工人分配其他任务
            if (taskMatch[task] == 0 || dfs(taskMatch[task], m)) {
                taskMatch[task] = worker;
                return true;
            }
        }
    }
    return false;
}

int maxTaskAssignment(int n, int m) {
    int result = 0;

    for (int i = 1; i <= n; i++) {
        memset(visited, false, sizeof(visited));
        if (dfs(i, m)) {
            result++;
        }
    }

    return result;
}

int main() {
    int n, m, e;  // n个工人，m个任务，e种能完成的关系
    cin >> n >> m >> e;

    for (int i = 0; i < e; i++) {
        int worker, task;
        cin >> worker >> task;
        workers[worker].push_back(task);
    }

    int maxTasks = maxTaskAssignment(n, m);
    cout << "最多能完成的任务数: " << maxTasks << endl;

    // 输出分配方案
    cout << "任务分配方案:" << endl;
    for (int i = 1; i <= m; i++) {
        if (taskMatch[i] != 0) {
            cout << "任务" << i << "分配给工人" << taskMatch[i] << endl;
        }
    }

    return 0;
}
```

### 2. 婚姻匹配问题

**问题描述**：有n位男士和n位女士，每位男士对一些女士有好感，每位女士对一些男士有好感。如果一对男女互相有好感，则可以结婚。求最多能有多少对男女结婚。

**解题思路**：将男士作为左部顶点，女士作为右部顶点，如果男士i和女士j互相有好感，则在男士i和女士j之间连边。问题转化为求二分图的最大匹配。

### 3. 课程安排问题

**问题描述**：有n位教师和m门课程，每位教师只能教某些特定的课程，每门课程只能由一位教师教授。求最多能安排多少门课程。

**解题思路**：将教师作为左部顶点，课程作为右部顶点，如果教师i能教授课程j，则在教师i和课程j之间连边。问题转化为求二分图的最大匹配。

### 4. 网络流问题

许多网络流问题可以转化为二分图匹配问题，例如：

- 二分图最大权匹配
- 二分图最小权匹配
- 二分图完美匹配

## 二分图的高级算法

### 1. Hopcroft-Karp算法

Hopcroft-Karp算法是匈牙利算法的优化版本，通过同时寻找多条增广路径来提高效率。

```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int N = 1e5 + 5;
const int INF = 1e9;

vector<int> g[N];
int pairU[N], pairV[N];  // 左部和右部顶点的匹配
int dist[N];             // 距离

// BFS构建层次图
bool bfs(int n, int m) {
    queue<int> q;

    for (int u = 1; u <= n; u++) {
        if (pairU[u] == 0) {  // 未匹配的左部顶点
            dist[u] = 0;
            q.push(u);
        } else {
            dist[u] = INF;
        }
    }

    dist[0] = INF;  // 虚拟节点

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (dist[u] < dist[0]) {  // 优化：剪枝
            for (int v : g[u]) {
                if (dist[pairV[v]] == INF) {
                    dist[pairV[v]] = dist[u] + 1;
                    q.push(pairV[v]);
                }
            }
        }
    }

    return dist[0] != INF;
}

// DFS在层次图中寻找增广路径
bool dfs(int u) {
    if (u != 0) {  // 不是虚拟节点
        for (int v : g[u]) {
            if (dist[pairV[v]] == dist[u] + 1 && dfs(pairV[v])) {
                pairU[u] = v;
                pairV[v] = u;
                return true;
            }
        }

        dist[u] = INF;  // 标记为不可达
        return false;
    }
    return true;
}

// Hopcroft-Karp算法
int hopcroftKarp(int n, int m) {
    memset(pairU, 0, sizeof(pairU));
    memset(pairV, 0, sizeof(pairV));

    int result = 0;

    while (bfs(n, m)) {
        for (int u = 1; u <= n; u++) {
            if (pairU[u] == 0 && dfs(u)) {
                result++;
            }
        }
    }

    return result;
}

int main() {
    int n, m, e;
    cin >> n >> m >> e;

    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    int maxMatch = hopcroftKarp(n, m);
    cout << "最大匹配数: " << maxMatch << endl;

    return 0;
}
```

#### Hopcroft-Karp算法的时间复杂度

- **时间复杂度**：O(√N × M)，其中N是顶点数，M是边数
- **空间复杂度**：O(N + M)

### 2. KM算法（Kuhn-Munkres算法）

KM算法用于求解二分图的最大权完美匹配问题。

```cpp
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 505;
const int INF = 1e9;

int n;  // 顶点数
int weight[N][N];  // 权重矩阵
int lx[N], ly[N];   // 左部和右部顶点的标号
int matchY[N];      // 右部顶点匹配的左部顶点
bool S[N], T[N];    // 访问标记
int slack[N];       // 松弛量

bool dfs(int u) {
    S[u] = true;  // 标记左部顶点u为访问

    for (int v = 1; v <= n; v++) {
        if (!T[v]) {  // 右部顶点v未访问
            int tmp = lx[u] + ly[v] - weight[u][v];

            if (tmp == 0) {  // 在相等子图中
                T[v] = true;

                if (matchY[v] == 0 || dfs(matchY[v])) {
                    matchY[v] = u;
                    return true;
                }
            } else if (slack[v] > tmp) {  // 更新松弛量
                slack[v] = tmp;
            }
        }
    }

    return false;
}

void update() {
    int d = INF;

    for (int v = 1; v <= n; v++) {
        if (!T[v]) {
            d = min(d, slack[v]);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (S[i]) {
            lx[i] -= d;
        }
        if (T[i]) {
            ly[i] += d;
        }
    }
}

int km() {
    memset(matchY, 0, sizeof(matchY));
    memset(ly, 0, sizeof(ly));

    // 初始化左部顶点的标号
    for (int i = 1; i <= n; i++) {
        lx[i] = -INF;
        for (int j = 1; j <= n; j++) {
            lx[i] = max(lx[i], weight[i][j]);
        }
    }

    for (int u = 1; u <= n; u++) {
        memset(slack, 0x3f, sizeof(slack));

        while (true) {
            memset(S, false, sizeof(S));
            memset(T, false, sizeof(T));

            if (dfs(u)) {
                break;  // 找到匹配
            }

            update();  // 更新标号
        }
    }

    // 计算最大权匹配
    int result = 0;
    for (int v = 1; v <= n; v++) {
        if (matchY[v] != 0) {
            result += weight[matchY[v]][v];
        }
    }

    return result;
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> weight[i][j];
        }
    }

    int maxWeight = km();
    cout << "最大权匹配值: " << maxWeight << endl;

    cout << "匹配方案:" << endl;
    for (int v = 1; v <= n; v++) {
        if (matchY[v] != 0) {
            cout << "左部顶点" << matchY[v] << " -> 右部顶点" << v 
                 << " (权重: " << weight[matchY[v]][v] << ")" << endl;
        }
    }

    return 0;
}
```

## 二分图问题的解题技巧

### 1. 建图技巧

在解决实际问题时，关键在于如何将问题转化为二分图模型：

- **识别两类对象**：找出问题中可以分成两类且没有内部连接的对象
- **确定连接关系**：明确两类对象之间的连接条件和方式
- **构建二分图**：将对象作为顶点，连接关系作为边

### 2. 算法选择

根据问题的特点选择合适的算法：

- **判断是否为二分图**：使用染色法
- **求最大匹配**：根据图的稠密程度选择匈牙利算法或Hopcroft-Karp算法
- **求最大权匹配**：使用KM算法
- **求最小点覆盖/最大独立集**：利用König定理和最大匹配

### 3. 优化技巧

- **邻接表优化**：使用合适的邻接表存储方式
- **访问标记优化**：使用时间戳代替重置访问数组
- **DFS优化**：根据图的特性调整DFS顺序
- **剪枝优化**：在搜索过程中添加合理的剪枝条件

## 总结

二分图是图论中的重要概念，在算法竞赛和实际应用中都有广泛的应用。掌握二分图的基本概念、判定方法和匹配算法，对于解决许多组合优化问题非常有帮助。

### 关键点回顾

1. **二分图定义**：顶点可分成两个不相交子集，边只连接不同子集的顶点
2. **判定方法**：染色法，BFS或DFS实现
3. **最大匹配**：匈牙利算法和Hopcroft-Karp算法
4. **König定理**：最大匹配数等于最小点覆盖数
5. **最大独立集**：总顶点数减去最小点覆盖数
6. **应用场景**：任务分配、婚姻匹配、课程安排等

### 练习建议

1. **基础练习**：实现二分图判定和最大匹配算法
2. **应用练习**：将实际问题转化为二分图模型并求解
3. **优化练习**：尝试不同的优化技巧提高算法效率
4. **综合练习**：结合其他算法解决复杂的二分图问题

通过系统学习和大量练习，可以熟练掌握二分图相关算法，为解决更复杂的图论问题打下坚实基础。

# tarjan

tarjan是个人，他发明了一坨**图论算法**，所以我们称他的算法为tarjan,其它的用问题去区分

> **小知识**: tarjan不叫**塔尖**，而是叫**塔儿烟**（中文翻译**陶尔杨**），嘿嘿

## 割点

双联通分量的前置算法之一（因该说是前置算法的前置算法），去掉一个或一些点之后**这个图不联通**，则这些点**被称为割点**
具体思路就不细讲了，**代码里头有注释**，包你看懂

```cpp
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,m;//n->点数,m->边数
vector<ll> g[N];
ll root;
ll idx=0;//时间戳
bool flag[N];//点i是割点的话，flag[i]=1,反之则不是割点
//特色数组
ll num[N];//i节点的时间戳
ll low[N];//i节点当前可以回到的最早时间戳
//核心！！！dfs来啦
void dfs(ll x,ll fa){//x->当前节点编号,fa->当前节点的爸爸(生成树角度)
    ll child=0;//孩子个数
    idx++;
    num[x]=idx;//记录时间戳
    low[x]=idx;//刚开始还没算就是自己（初始化）
    for(auto i:g[x]){
        if(num[i]==0){//说明没被访问过（这里是当vis用的）
            //从生成树的角度来说，此时i为x的儿子
            child++;
            dfs(i,x);//继续dfs
            //维护low数组
            low[x]=min(low[x],low[i]);
            //1.当前点不是根节点，2.low[i]>=num[x]（说明我的儿子不能不通过我上到我的头上）
            if(x!=root&&low[i]>=num[x]){
                flag[x]=1;
            }
            //如果当前节点是根节点，在生成树中必须要有两个儿子，根节点才是割点（一个点断了儿子成根节点就没事呀）
            if(x==root&&child>=2){
                flag[x]=1;
            }
        }
        else if(i!=fa){
            //如果节点i被访问过并且不受当前节点的父亲，则说明i为x的祖先，要更新当前节点的low
            //i都已经是x的祖先了，肯定是可以到的呀
            low[x]=min(low[x],num[i]);
        }
    }
    return;
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        ll u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    root=1;
    dfs(1,root);//从一开始开始dfs
    //输出割点
    for(int i=1;i<=n;i++) if(flag[i]==1) cout<<i<<" ";
}
int main(){
    ll T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}

```

# 线段树

## 概念介绍

线段树（Segment Tree）是一种二叉树形数据结构，用于高效地处理区间查询问题。它将一个区间划分为若干个小区间，每个节点代表一个区间，存储该区间的某些信息（如区间和、区间最大值、区间最小值等）。

### 线段树的基本思想

线段树的核心思想是**分治**：将一个大区间递归地分成两个小区间，直到区间长度为1。每个节点存储其对应区间的信息，通过合并子节点的信息可以得到父节点的信息。

### 线段树的优势

1. **查询效率高**：区间查询的时间复杂度为O(log n)
2. **支持动态修改**：支持单点修改和区间修改
3. **应用范围广**：可用于求区间和、区间最大值、区间最小值等
4. **实现灵活**：可以根据需求定制不同的合并操作

## 线段树的基本结构

### 节点表示

线段树的每个节点通常包含以下信息：

- 区间范围 [l, r]
- 区间信息（如区间和、最大值、最小值等）
- 左子节点和右子节点的指针或索引

### 线段树的高度

对于长度为n的区间，线段树的高度为⌈log₂n⌉，总节点数不超过4n。

## 线段树的实现

### 1. 基本线段树（区间和）

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class SegmentTree {
private:
    vector<int> tree;  // 线段树数组
    vector<int> lazy;  // 懒标记数组（用于区间更新）
    int n;             // 原数组长度

    // 构建线段树
    void build(vector<int>& nums, int node, int start, int end) {
        if (start == end) {
            tree[node] = nums[start];
        } else {
            int mid = start + (end - start) / 2;
            int leftChild = 2 * node + 1;
            int rightChild = 2 * node + 2;

            build(nums, leftChild, start, mid);
            build(nums, rightChild, mid + 1, end);

            tree[node] = tree[leftChild] + tree[rightChild];
        }
    }

    // 区间查询
    int queryRange(int node, int start, int end, int l, int r) {
        // 区间无交集
        if (r < start || end < l) {
            return 0;
        }

        // 当前区间完全包含在查询区间内
        if (l <= start && end <= r) {
            return tree[node];
        }

        // 部分重叠，递归查询
        int mid = start + (end - start) / 2;
        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;

        int leftSum = queryRange(leftChild, start, mid, l, r);
        int rightSum = queryRange(rightChild, mid + 1, end, l, r);

        return leftSum + rightSum;
    }

    // 单点更新
    void updatePoint(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
        } else {
            int mid = start + (end - start) / 2;
            int leftChild = 2 * node + 1;
            int rightChild = 2 * node + 2;

            if (idx <= mid) {
                updatePoint(leftChild, start, mid, idx, val);
            } else {
                updatePoint(rightChild, mid + 1, end, idx, val);
            }

            tree[node] = tree[leftChild] + tree[rightChild];
        }
    }

public:
    SegmentTree(vector<int>& nums) {
        n = nums.size();
        tree.resize(4 * n, 0);
        build(nums, 0, 0, n - 1);
    }

    // 区间查询接口
    int queryRange(int l, int r) {
        return queryRange(0, 0, n - 1, l, r);
    }

    // 单点更新接口
    void updatePoint(int idx, int val) {
        updatePoint(0, 0, n - 1, idx, val);
    }
};

int main() {
    vector<int> nums = {1, 3, 5, 7, 9, 11};
    SegmentTree st(nums);

    cout << "区间[0, 2]的和: " << st.queryRange(0, 2) << endl;  // 1 + 3 + 5 = 9
    cout << "区间[1, 4]的和: " << st.queryRange(1, 4) << endl;  // 3 + 5 + 7 + 9 = 24

    // 更新索引2的值为6
    st.updatePoint(2, 6);
    cout << "更新后区间[0, 2]的和: " << st.queryRange(0, 2) << endl;  // 1 + 3 + 6 = 10

    return 0;
}
```

### 2. 区间最大值线段树

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MaxSegmentTree {
private:
    vector<int> tree;
    int n;

    void build(vector<int>& nums, int node, int start, int end) {
        if (start == end) {
            tree[node] = nums[start];
        } else {
            int mid = start + (end - start) / 2;
            int leftChild = 2 * node + 1;
            int rightChild = 2 * node + 2;

            build(nums, leftChild, start, mid);
            build(nums, rightChild, mid + 1, end);

            tree[node] = max(tree[leftChild], tree[rightChild]);
        }
    }

    int queryRange(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return INT_MIN;  // 表示无效值
        }

        if (l <= start && end <= r) {
            return tree[node];
        }

        int mid = start + (end - start) / 2;
        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;

        int leftMax = queryRange(leftChild, start, mid, l, r);
        int rightMax = queryRange(rightChild, mid + 1, end, l, r);

        return max(leftMax, rightMax);
    }

    void updatePoint(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
        } else {
            int mid = start + (end - start) / 2;
            int leftChild = 2 * node + 1;
            int rightChild = 2 * node + 2;

            if (idx <= mid) {
                updatePoint(leftChild, start, mid, idx, val);
            } else {
                updatePoint(rightChild, mid + 1, end, idx, val);
            }

            tree[node] = max(tree[leftChild], tree[rightChild]);
        }
    }

public:
    MaxSegmentTree(vector<int>& nums) {
        n = nums.size();
        tree.resize(4 * n, 0);
        build(nums, 0, 0, n - 1);
    }

    int queryRange(int l, int r) {
        return queryRange(0, 0, n - 1, l, r);
    }

    void updatePoint(int idx, int val) {
        updatePoint(0, 0, n - 1, idx, val);
    }
};

int main() {
    vector<int> nums = {2, 5, 1, 4, 9, 3};
    MaxSegmentTree st(nums);

    cout << "区间[0, 3]的最大值: " << st.queryRange(0, 3) << endl;  // max(2, 5, 1, 4) = 5
    cout << "区间[2, 5]的最大值: " << st.queryRange(2, 5) << endl;  // max(1, 4, 9, 3) = 9

    // 更新索引1的值为10
    st.updatePoint(1, 10);
    cout << "更新后区间[0, 3]的最大值: " << st.queryRange(0, 3) << endl;  // max(2, 10, 1, 4) = 10

    return 0;
}
```

### 3. 带懒标记的区间更新线段树

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class LazySegmentTree {
private:
    vector<long long> tree;  // 线段树数组
    vector<long long> lazy;  // 懒标记数组
    int n;                   // 原数组长度

    // 下推懒标记
    void pushDown(int node, int start, int end) {
        if (lazy[node] != 0) {
            int mid = start + (end - start) / 2;
            int leftChild = 2 * node + 1;
            int rightChild = 2 * node + 2;

            // 将懒标记传递给子节点
            lazy[leftChild] += lazy[node];
            lazy[rightChild] += lazy[node];

            // 更新子节点的值
            tree[leftChild] += lazy[node] * (mid - start + 1);
            tree[rightChild] += lazy[node] * (end - mid);

            // 清除当前节点的懒标记
            lazy[node] = 0;
        }
    }

    // 构建线段树
    void build(vector<int>& nums, int node, int start, int end) {
        if (start == end) {
            tree[node] = nums[start];
        } else {
            int mid = start + (end - start) / 2;
            int leftChild = 2 * node + 1;
            int rightChild = 2 * node + 2;

            build(nums, leftChild, start, mid);
            build(nums, rightChild, mid + 1, end);

            tree[node] = tree[leftChild] + tree[rightChild];
        }
    }

    // 区间查询
    long long queryRange(int node, int start, int end, int l, int r) {
        // 区间无交集
        if (r < start || end < l) {
            return 0;
        }

        // 当前区间完全包含在查询区间内
        if (l <= start && end <= r) {
            return tree[node];
        }

        // 下推懒标记
        pushDown(node, start, end);

        // 部分重叠，递归查询
        int mid = start + (end - start) / 2;
        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;

        long long leftSum = queryRange(leftChild, start, mid, l, r);
        long long rightSum = queryRange(rightChild, mid + 1, end, l, r);

        return leftSum + rightSum;
    }

    // 区间更新
    void updateRange(int node, int start, int end, int l, int r, int val) {
        // 区间无交集
        if (r < start || end < l) {
            return;
        }

        // 当前区间完全包含在更新区间内
        if (l <= start && end <= r) {
            tree[node] += (long long)val * (end - start + 1);
            lazy[node] += val;
            return;
        }

        // 下推懒标记
        pushDown(node, start, end);

        // 部分重叠，递归更新
        int mid = start + (end - start) / 2;
        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;

        updateRange(leftChild, start, mid, l, r, val);
        updateRange(rightChild, mid + 1, end, l, r, val);

        tree[node] = tree[leftChild] + tree[rightChild];
    }

public:
    LazySegmentTree(vector<int>& nums) {
        n = nums.size();
        tree.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
        build(nums, 0, 0, n - 1);
    }

    // 区间查询接口
    long long queryRange(int l, int r) {
        return queryRange(0, 0, n - 1, l, r);
    }

    // 区间更新接口
    void updateRange(int l, int r, int val) {
        updateRange(0, 0, n - 1, l, r, val);
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    LazySegmentTree st(nums);

    cout << "初始区间[0, 4]的和: " << st.queryRange(0, 4) << endl;  // 1 + 2 + 3 + 4 + 5 = 15

    // 区间[1, 3]每个元素加2
    st.updateRange(1, 3, 2);
    cout << "更新后区间[0, 4]的和: " << st.queryRange(0, 4) << endl;  // 1 + 4 + 5 + 6 + 5 = 21
    cout << "更新后区间[1, 3]的和: " << st.queryRange(1, 3) << endl;  // 4 + 5 + 6 = 15

    // 再次区间[2, 4]每个元素加1
    st.updateRange(2, 4, 1);
    cout << "再次更新后区间[0, 4]的和: " << st.queryRange(0, 4) << endl;  // 1 + 4 + 6 + 7 + 6 = 24

    return 0;
}
```

## 线段树的高级应用

### 1. 区间最大子段和

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int sum;        // 区间和
    int maxSum;     // 区间最大子段和
    int leftMax;    // 区间前缀最大和
    int rightMax;   // 区间后缀最大和

    Node() : sum(0), maxSum(0), leftMax(0), rightMax(0) {}
    Node(int val) : sum(val), maxSum(val), leftMax(val), rightMax(val) {}

    Node merge(const Node& other) {
        Node result;
        result.sum = sum + other.sum;
        result.leftMax = max(leftMax, sum + other.leftMax);
        result.rightMax = max(other.rightMax, other.sum + rightMax);
        result.maxSum = max({maxSum, other.maxSum, rightMax + other.leftMax});
        return result;
    }
};

class MaxSubarraySegmentTree {
private:
    vector<Node> tree;
    int n;

    void build(vector<int>& nums, int node, int start, int end) {
        if (start == end) {
            tree[node] = Node(nums[start]);
        } else {
            int mid = start + (end - start) / 2;
            int leftChild = 2 * node + 1;
            int rightChild = 2 * node + 2;

            build(nums, leftChild, start, mid);
            build(nums, rightChild, mid + 1, end);

            tree[node] = tree[leftChild].merge(tree[rightChild]);
        }
    }

    Node queryRange(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return Node(INT_MIN);  // 返回无效节点
        }

        if (l <= start && end <= r) {
            return tree[node];
        }

        int mid = start + (end - start) / 2;
        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;

        Node leftResult = queryRange(leftChild, start, mid, l, r);
        Node rightResult = queryRange(rightChild, mid + 1, end, l, r);

        if (leftResult.sum == INT_MIN) return rightResult;
        if (rightResult.sum == INT_MIN) return leftResult;

        return leftResult.merge(rightResult);
    }

    void updatePoint(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = Node(val);
        } else {
            int mid = start + (end - start) / 2;
            int leftChild = 2 * node + 1;
            int rightChild = 2 * node + 2;

            if (idx <= mid) {
                updatePoint(leftChild, start, mid, idx, val);
            } else {
                updatePoint(rightChild, mid + 1, end, idx, val);
            }

            tree[node] = tree[leftChild].merge(tree[rightChild]);
        }
    }

public:
    MaxSubarraySegmentTree(vector<int>& nums) {
        n = nums.size();
        tree.resize(4 * n);
        build(nums, 0, 0, n - 1);
    }

    int queryMaxSubarray(int l, int r) {
        return queryRange(0, 0, n - 1, l, r).maxSum;
    }

    void updatePoint(int idx, int val) {
        updatePoint(0, 0, n - 1, idx, val);
    }
};

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    MaxSubarraySegmentTree st(nums);

    cout << "区间[0, 8]的最大子段和: " << st.queryMaxSubarray(0, 8) << endl;  // 6 (子段[3,6])
    cout << "区间[3, 6]的最大子段和: " << st.queryMaxSubarray(3, 6) << endl;  // 6 (子段[3,6])

    // 更新索引4的值为10
    st.updatePoint(4, 10);
    cout << "更新后区间[0, 8]的最大子段和: " << st.queryMaxSubarray(0, 8) << endl;  // 16

    return 0;
}
```

### 2. 区间乘法与加法混合更新

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = 1e9 + 7;

class MixSegmentTree {
private:
    vector<long long> tree;    // 线段树数组
    vector<long long> addLazy; // 加法懒标记
    vector<long long> mulLazy; // 乘法懒标记
    int n;

    // 下推懒标记
    void pushDown(int node, int start, int end) {
        if (addLazy[node] != 0 || mulLazy[node] != 1) {
            int mid = start + (end - start) / 2;
            int leftChild = 2 * node + 1;
            int rightChild = 2 * node + 2;

            // 处理乘法懒标记
            mulLazy[leftChild] = (mulLazy[leftChild] * mulLazy[node]) % MOD;
            mulLazy[rightChild] = (mulLazy[rightChild] * mulLazy[node]) % MOD;

            addLazy[leftChild] = (addLazy[leftChild] * mulLazy[node]) % MOD;
            addLazy[rightChild] = (addLazy[rightChild] * mulLazy[node]) % MOD;

            tree[leftChild] = (tree[leftChild] * mulLazy[node]) % MOD;
            tree[rightChild] = (tree[rightChild] * mulLazy[node]) % MOD;

            // 处理加法懒标记
            int leftLen = mid - start + 1;
            int rightLen = end - mid;

            addLazy[leftChild] = (addLazy[leftChild] + addLazy[node]) % MOD;
            addLazy[rightChild] = (addLazy[rightChild] + addLazy[node]) % MOD;

            tree[leftChild] = (tree[leftChild] + addLazy[node] * leftLen) % MOD;
            tree[rightChild] = (tree[rightChild] + addLazy[node] * rightLen) % MOD;

            // 重置当前节点的懒标记
            addLazy[node] = 0;
            mulLazy[node] = 1;
        }
    }

    void build(vector<int>& nums, int node, int start, int end) {
        if (start == end) {
            tree[node] = nums[start] % MOD;
        } else {
            int mid = start + (end - start) / 2;
            int leftChild = 2 * node + 1;
            int rightChild = 2 * node + 2;

            build(nums, leftChild, start, mid);
            build(nums, rightChild, mid + 1, end);

            tree[node] = (tree[leftChild] + tree[rightChild]) % MOD;
        }
    }

    long long queryRange(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return 0;
        }

        if (l <= start && end <= r) {
            return tree[node];
        }

        pushDown(node, start, end);

        int mid = start + (end - start) / 2;
        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;

        long long leftSum = queryRange(leftChild, start, mid, l, r);
        long long rightSum = queryRange(rightChild, mid + 1, end, l, r);

        return (leftSum + rightSum) % MOD;
    }

    void updateAdd(int node, int start, int end, int l, int r, int val) {
        if (r < start || end < l) {
            return;
        }

        if (l <= start && end <= r) {
            addLazy[node] = (addLazy[node] + val) % MOD;
            tree[node] = (tree[node] + (long long)val * (end - start + 1)) % MOD;
            return;
        }

        pushDown(node, start, end);

        int mid = start + (end - start) / 2;
        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;

        updateAdd(leftChild, start, mid, l, r, val);
        updateAdd(rightChild, mid + 1, end, l, r, val);

        tree[node] = (tree[leftChild] + tree[rightChild]) % MOD;
    }

    void updateMul(int node, int start, int end, int l, int r, int val) {
        if (r < start || end < l) {
            return;
        }

        if (l <= start && end <= r) {
            mulLazy[node] = (mulLazy[node] * val) % MOD;
            addLazy[node] = (addLazy[node] * val) % MOD;
            tree[node] = (tree[node] * val) % MOD;
            return;
        }

        pushDown(node, start, end);

        int mid = start + (end - start) / 2;
        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;

        updateMul(leftChild, start, mid, l, r, val);
        updateMul(rightChild, mid + 1, end, l, r, val);

        tree[node] = (tree[leftChild] + tree[rightChild]) % MOD;
    }

public:
    MixSegmentTree(vector<int>& nums) {
        n = nums.size();
        tree.resize(4 * n, 0);
        addLazy.resize(4 * n, 0);
        mulLazy.resize(4 * n, 1);
        build(nums, 0, 0, n - 1);
    }

    long long queryRange(int l, int r) {
        return queryRange(0, 0, n - 1, l, r);
    }

    void updateAdd(int l, int r, int val) {
        updateAdd(0, 0, n - 1, l, r, val);
    }

    void updateMul(int l, int r, int val) {
        updateMul(0, 0, n - 1, l, r, val);
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    MixSegmentTree st(nums);

    cout << "初始区间[0, 4]的和: " << st.queryRange(0, 4) << endl;  // 15

    // 区间[1, 3]每个元素乘以2
    st.updateMul(1, 3, 2);
    cout << "乘法更新后区间[0, 4]的和: " << st.queryRange(0, 4) << endl;  // 1 + 4 + 6 + 8 + 5 = 24

    // 区间[2, 4]每个元素加3
    st.updateAdd(2, 4, 3);
    cout << "加法更新后区间[0, 4]的和: " << st.queryRange(0, 4) << endl;  // 1 + 4 + 9 + 11 + 8 = 33

    // 区间[0, 2]每个元素乘以3
    st.updateMul(0, 2, 3);
    cout << "再次乘法更新后区间[0, 4]的和: " << st.queryRange(0, 4) << endl;  // 3 + 12 + 27 + 11 + 8 = 61

    return 0;
}
```

## 线段树的优化技巧

### 1. 动态开点线段树

当区间范围很大但实际使用的点很少时，可以使用动态开点线段树来节省空间。

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class DynamicSegmentTree {
private:
    struct Node {
        int val;
        Node *left, *right;

        Node() : val(0), left(nullptr), right(nullptr) {}
    };

    Node* root;
    int leftBound, rightBound;

    void update(Node*& node, int start, int end, int idx, int val) {
        if (!node) {
            node = new Node();
        }

        if (start == end) {
            node->val = val;
            return;
        }

        int mid = start + (end - start) / 2;

        if (idx <= mid) {
            update(node->left, start, mid, idx, val);
        } else {
            update(node->right, mid + 1, end, idx, val);
        }

        node->val = (node->left ? node->left->val : 0) + 
                   (node->right ? node->right->val : 0);
    }

    int query(Node* node, int start, int end, int l, int r) {
        if (!node || r < start || end < l) {
            return 0;
        }

        if (l <= start && end <= r) {
            return node->val;
        }

        int mid = start + (end - start) / 2;

        return query(node->left, start, mid, l, r) + 
               query(node->right, mid + 1, end, l, r);
    }

public:
    DynamicSegmentTree(int left, int right) : leftBound(left), rightBound(right) {
        root = nullptr;
    }

    void update(int idx, int val) {
        update(root, leftBound, rightBound, idx, val);
    }

    int query(int l, int r) {
        return query(root, leftBound, rightBound, l, r);
    }
};

int main() {
    // 处理范围[1, 1e9]的线段树
    DynamicSegmentTree st(1, 1e9);

    // 更新位置1e9的值为100
    st.update(1e9, 100);

    // 查询区间[1e9-1, 1e9]的和
    cout << "区间[1e9-1, 1e9]的和: " << st.query(1e9 - 1, 1e9) << endl;  // 100

    return 0;
}
```

### 2. 线段树合并

当需要处理多个线段树并需要合并它们时，可以使用线段树合并技术。

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MergeSegmentTree {
private:
    struct Node {
        int count;
        Node *left, *right;

        Node() : count(0), left(nullptr), right(nullptr) {}
    };

    vector<Node*> roots;
    int leftBound, rightBound;

    void insert(Node*& node, int start, int end, int val) {
        if (!node) {
            node = new Node();
        }

        node->count++;

        if (start == end) {
            return;
        }

        int mid = start + (end - start) / 2;

        if (val <= mid) {
            insert(node->left, start, mid, val);
        } else {
            insert(node->right, mid + 1, end, val);
        }
    }

    Node* merge(Node* node1, Node* node2) {
        if (!node1) return node2;
        if (!node2) return node1;

        node1->count += node2->count;
        node1->left = merge(node1->left, node2->left);
        node1->right = merge(node1->right, node2->right);

        delete node2;
        return node1;
    }

    int query(Node* node, int start, int end, int l, int r) {
        if (!node || r < start || end < l) {
            return 0;
        }

        if (l <= start && end <= r) {
            return node->count;
        }

        int mid = start + (end - start) / 2;

        return query(node->left, start, mid, l, r) + 
               query(node->right, mid + 1, end, l, r);
    }

public:
    MergeSegmentTree(int left, int right) : leftBound(left), rightBound(right) {}

    void addTree() {
        roots.push_back(nullptr);
    }

    void insert(int treeIndex, int val) {
        insert(roots[treeIndex], leftBound, rightBound, val);
    }

    void mergeTrees(int index1, int index2) {
        roots[index1] = merge(roots[index1], roots[index2]);
        roots[index2] = nullptr;
    }

    int query(int treeIndex, int l, int r) {
        return query(roots[treeIndex], leftBound, rightBound, l, r);
    }
};

int main() {
    MergeSegmentTree st(1, 100);

    // 添加两棵线段树
    st.addTree();
    st.addTree();

    // 向第一棵树插入元素
    st.insert(0, 10);
    st.insert(0, 20);
    st.insert(0, 30);

    // 向第二棵树插入元素
    st.insert(1, 20);
    st.insert(1, 40);
    st.insert(1, 50);

    cout << "第一棵树中[15, 25]的元素个数: " << st.query(0, 15, 25) << endl;  // 1 (只有20)
    cout << "第二棵树中[15, 25]的元素个数: " << st.query(1, 15, 25) << endl;  // 1 (只有20)

    // 合并两棵树
    st.mergeTrees(0, 1);

    cout << "合并后树中[15, 25]的元素个数: " << st.query(0, 15, 25) << endl;  // 2 (两个20)

    return 0;
}
```

## 线段树的应用场景

### 1. 区间统计问题

**问题描述**：给定一个数组，支持以下操作：

1. 查询区间[l, r]的和
2. 将区间[l, r]的每个元素加1
3. 将位置idx的元素更新为val

**解决方案**：使用带懒标记的线段树

```cpp
#include <iostream>
#include <vector>
using namespace std;

class RangeStatistics {
private:
    vector<long long> tree;
    vector<long long> lazy;
    int n;

    void pushDown(int node, int start, int end) {
        if (lazy[node] != 0) {
            int mid = start + (end - start) / 2;
            int leftChild = 2 * node + 1;
            int rightChild = 2 * node + 2;

            lazy[leftChild] += lazy[node];
            lazy[rightChild] += lazy[node];

            tree[leftChild] += lazy[node] * (mid - start + 1);
            tree[rightChild] += lazy[node] * (end - mid);

            lazy[node] = 0;
        }
    }

    void build(vector<int>& nums, int node, int start, int end) {
        if (start == end) {
            tree[node] = nums[start];
        } else {
            int mid = start + (end - start) / 2;
            int leftChild = 2 * node + 1;
            int rightChild = 2 * node + 2;

            build(nums, leftChild, start, mid);
            build(nums, rightChild, mid + 1, end);

            tree[node] = tree[leftChild] + tree[rightChild];
        }
    }

    long long queryRange(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return 0;
        }

        if (l <= start && end <= r) {
            return tree[node];
        }

        pushDown(node, start, end);

        int mid = start + (end - start) / 2;
        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;

        return queryRange(leftChild, start, mid, l, r) + 
               queryRange(rightChild, mid + 1, end, l, r);
    }

    void updateRange(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return;
        }

        if (l <= start && end <= r) {
            tree[node] += (end - start + 1);
            lazy[node] += 1;
            return;
        }

        pushDown(node, start, end);

        int mid = start + (end - start) / 2;
        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;

        updateRange(leftChild, start, mid, l, r);
        updateRange(rightChild, mid + 1, end, l, r);

        tree[node] = tree[leftChild] + tree[rightChild];
    }

    void updatePoint(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
        } else {
            int mid = start + (end - start) / 2;
            int leftChild = 2 * node + 1;
            int rightChild = 2 * node + 2;

            if (idx <= mid) {
                updatePoint(leftChild, start, mid, idx, val);
            } else {
                updatePoint(rightChild, mid + 1, end, idx, val);
            }

            tree[node] = tree[leftChild] + tree[rightChild];
        }
    }

public:
    RangeStatistics(vector<int>& nums) {
        n = nums.size();
        tree.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
        build(nums, 0, 0, n - 1);
    }

    long long queryRange(int l, int r) {
        return queryRange(0, 0, n - 1, l, r);
    }

    void updateRange(int l, int r) {
        updateRange(0, 0, n - 1, l, r);
    }

    void updatePoint(int idx, int val) {
        updatePoint(0, 0, n - 1, idx, val);
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    RangeStatistics rs(nums);

    cout << "初始区间[0, 4]的和: " << rs.queryRange(0, 4) << endl;  // 15

    // 区间[1, 3]每个元素加1
    rs.updateRange(1, 3);
    cout << "区间更新后区间[0, 4]的和: " << rs.queryRange(0, 4) << endl;  // 18

    // 更新位置2的值为10
    rs.updatePoint(2, 10);
    cout << "单点更新后区间[0, 4]的和: " << rs.queryRange(0, 4) << endl;  // 23

    return 0;
}
```

### 2. 区间最值问题

**问题描述**：给定一个数组，支持以下操作：

1. 查询区间[l, r]的最大值
2. 查询区间[l, r]的最小值
3. 更新位置idx的值为val

**解决方案**：使用两个线段树分别维护最大值和最小值

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class RangeMinMax {
private:
    vector<int> maxTree;
    vector<int> minTree;
    int n;

    void build(vector<int>& nums, int node, int start, int end) {
        if (start == end) {
            maxTree[node] = nums[start];
            minTree[node] = nums[start];
        } else {
            int mid = start + (end - start) / 2;
            int leftChild = 2 * node + 1;
            int rightChild = 2 * node + 2;

            build(nums, leftChild, start, mid);
            build(nums, rightChild, mid + 1, end);

            maxTree[node] = max(maxTree[leftChild], maxTree[rightChild]);
            minTree[node] = min(minTree[leftChild], minTree[rightChild]);
        }
    }

    int queryMax(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return INT_MIN;
        }

        if (l <= start && end <= r) {
            return maxTree[node];
        }

        int mid = start + (end - start) / 2;
        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;

        return max(queryMax(leftChild, start, mid, l, r),
                   queryMax(rightChild, mid + 1, end, l, r));
    }

    int queryMin(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return INT_MAX;
        }

        if (l <= start && end <= r) {
            return minTree[node];
        }

        int mid = start + (end - start) / 2;
        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;

        return min(queryMin(leftChild, start, mid, l, r),
                   queryMin(rightChild, mid + 1, end, l, r));
    }

    void updatePoint(int node, int start, int end, int idx, int val) {
        if (start == end) {
            maxTree[node] = val;
            minTree[node] = val;
        } else {
            int mid = start + (end - start) / 2;
            int leftChild = 2 * node + 1;
            int rightChild = 2 * node + 2;

            if (idx <= mid) {
                updatePoint(leftChild, start, mid, idx, val);
            } else {
                updatePoint(rightChild, mid + 1, end, idx, val);
            }

            maxTree[node] = max(maxTree[leftChild], maxTree[rightChild]);
            minTree[node] = min(minTree[leftChild], minTree[rightChild]);
        }
    }

public:
    RangeMinMax(vector<int>& nums) {
        n = nums.size();
        maxTree.resize(4 * n, 0);
        minTree.resize(4 * n, 0);
        build(nums, 0, 0, n - 1);
    }

    int queryMax(int l, int r) {
        return queryMax(0, 0, n - 1, l, r);
    }

    int queryMin(int l, int r) {
        return queryMin(0, 0, n - 1, l, r);
    }

    void updatePoint(int idx, int val) {
        updatePoint(0, 0, n - 1, idx, val);
    }
};

int main() {
    vector<int> nums = {3, 1, 4, 1, 5, 9, 2, 6};
    RangeMinMax rmm(nums);

    cout << "区间[0, 7]的最大值: " << rmm.queryMax(0, 7) << endl;  // 9
    cout << "区间[0, 7]的最小值: " << rmm.queryMin(0, 7) << endl;  // 1

    cout << "区间[2, 5]的最大值: " << rmm.queryMax(2, 5) << endl;  // 9
    cout << "区间[2, 5]的最小值: " << rmm.queryMin(2, 5) << endl;  // 1

    // 更新位置1的值为10
    rmm.updatePoint(1, 10);
    cout << "更新后区间[0, 7]的最大值: " << rmm.queryMax(0, 7) << endl;  // 10

    return 0;
}
```

## 线段树的复杂度分析

### 时间复杂度

- **构建线段树**：O(n)
- **区间查询**：O(log n)
- **单点更新**：O(log n)
- **区间更新**：O(log n)

### 空间复杂度

- **基本线段树**：O(4n)
- **带懒标记的线段树**：O(4n)
- **动态开点线段树**：O(m log n)，其中m是操作次数

## 线段树的优缺点

### 优点

1. **查询效率高**：区间查询的时间复杂度为O(log n)
2. **功能强大**：支持多种区间操作和更新操作
3. **实现灵活**：可以根据需求定制不同的合并操作
4. **应用广泛**：适用于各种区间统计问题

### 缺点

1. **空间开销大**：需要4倍于原数组的空间
2. **实现复杂**：相比树状数组，实现起来更复杂
3. **常数较大**：在实际应用中，常数因子可能较大
4. **不适合点查询**：对于单点查询，不如直接访问数组高效

## 线段树与树状数组的比较

| 特性    | 线段树       | 树状数组      |
| ----- | --------- | --------- |
| 时间复杂度 | O(log n)  | O(log n)  |
| 空间复杂度 | O(4n)     | O(n)      |
| 实现复杂度 | 较复杂       | 较简单       |
| 支持操作  | 区间查询、区间更新 | 区间查询、单点更新 |
| 适用场景  | 复杂区间操作    | 简单区间操作    |
| 扩展性   | 强         | 有限        |

**选择建议**：

- 当需要支持区间更新或复杂的区间操作时，选择线段树
- 当只需要简单的区间查询和单点更新时，选择树状数组

## 总结

线段树是一种强大的数据结构，特别适合处理区间查询和更新问题。通过合理的设计和优化，线段树可以高效地解决各种复杂的区间操作问题。

### 关键点回顾

1. **基本结构**：二叉树形结构，每个节点代表一个区间
2. **核心操作**：构建、查询、更新
3. **懒标记技术**：优化区间更新操作
4. **应用场景**：区间和、区间最值、区间统计等
5. **优化技巧**：动态开点、线段树合并等

### 学习建议

1. **掌握基础**：先理解线段树的基本结构和操作
2. **练习实现**：亲手实现不同类型的线段树
3. **应用实践**：解决实际问题，加深理解
4. **优化探索**：学习各种优化技巧，提高效率

通过系统学习和大量练习，可以熟练掌握线段树这一强大的数据结构，为解决复杂的区间问题提供有力工具。

# 欧拉函数与定理

## 欧拉函数定义

欧拉函数φ(n)是数论中的重要函数，定义为：小于等于n的正整数中与n互质的数的个数。

**数学表示**：
$$\phi(n) = |\{1 \leq k \leq n | \gcd(k,n) = 1\}|$$

## 欧拉函数的基本性质

### 1. 基本值

- φ(1) = 1
- 当n是质数时，φ(n) = n-1
- φ(2) = 1, φ(3) = 2, φ(4) = 2, φ(5) = 4, φ(6) = 2

### 2. 积性性质

若m和n互质，则：
$$\phi(mn) = \phi(m) \times \phi(n)$$

### 3. 质数幂的性质

对于质数p和正整数k：
$$\phi(p^k) = p^k - p^{k-1} = p^k \times (1 - \frac{1}{p})$$

### 4. 通用计算公式

若n的质因数分解为$n = p_1^{a_1} \times p_2^{a_2} \times \cdots \times p_k^{a_k}$，则：
$$\phi(n) = n \times \prod_{i=1}^{k} (1 - \frac{1}{p_i})$$

## 欧拉定理

**定理内容**：若a和n互质，则：
$$a^{\phi(n)} \equiv 1 \pmod{n}$$

**推论**：当n为质数时，φ(n) = n-1，此时欧拉定理退化为费马小定理：
$$a^{n-1} \equiv 1 \pmod{n}$$

## 欧拉函数的求解方法

### 方法一：直接计算（适用于单个数）

```cpp
#include <bits/stdc++.h>
using namespace std;

// 计算单个数的欧拉函数
int euler_phi(int n) {
    int result = n;

    // 对n进行质因数分解
    for (int p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            // p是n的质因数
            while (n % p == 0) {
                n /= p;
            }
            // 应用公式：φ(n) = n × (1 - 1/p)
            result -= result / p;
        }
    }

    // 如果剩下的n > 1，说明n本身是质数
    if (n > 1) {
        result -= result / n;
    }

    return result;
}

int main() {
    int n;
    cin >> n;
    cout << "φ(" << n << ") = " << euler_phi(n) << endl;
    return 0;
}
```

### 方法二：筛法预处理（适用于多次查询）

```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int phi[N];  // 存储欧拉函数值

// 线性筛法预处理欧拉函数
void euler_sieve(int n) {
    // 初始化
    for (int i = 1; i <= n; i++) {
        phi[i] = i;
    }

    // 筛法过程
    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {  // i是质数
            for (int j = i; j <= n; j += i) {
                phi[j] -= phi[j] / i;
            }
        }
    }
}

// 优化的线性筛法
void euler_sieve_optimized(int n) {
    vector<int> primes;
    bool is_composite[N] = {false};

    phi[1] = 1;

    for (int i = 2; i <= n; i++) {
        if (!is_composite[i]) {
            primes.push_back(i);
            phi[i] = i - 1;  // 质数的欧拉函数值为p-1
        }

        for (int j = 0; j < primes.size() && i * primes[j] <= n; j++) {
            is_composite[i * primes[j]] = true;

            if (i % primes[j] == 0) {
                // 如果primes[j]是i的质因数
                phi[i * primes[j]] = phi[i] * primes[j];
                break;
            } else {
                // 如果primes[j]不是i的质因数
                phi[i * primes[j]] = phi[i] * (primes[j] - 1);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    euler_sieve_optimized(n);

    // 输出前10个数的欧拉函数值
    for (int i = 1; i <= 10; i++) {
        cout << "φ(" << i << ") = " << phi[i] << endl;
    }

    return 0;
}
```

## 欧拉函数的应用

### 1. 求解模逆元

当a和n互质时，a的模逆元为：
$$a^{-1} \equiv a^{\phi(n)-1} \pmod{n}$$

```cpp
#include <bits/stdc++.h>
using namespace std;

// 快速幂取模
long long fast_pow(long long a, long long b, long long mod) {
    long long result = 1;
    a %= mod;

    while (b > 0) {
        if (b & 1) {
            result = (result * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }

    return result;
}

// 计算欧拉函数
int euler_phi(int n) {
    int result = n;
    for (int p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            while (n % p == 0) {
                n /= p;
            }
            result -= result / p;
        }
    }
    if (n > 1) {
        result -= result / n;
    }
    return result;
}

// 求模逆元
long long mod_inverse(int a, int mod) {
    int phi_mod = euler_phi(mod);
    return fast_pow(a, phi_mod - 1, mod);
}

int main() {
    int a, mod;
    cin >> a >> mod;

    if (__gcd(a, mod) != 1) {
        cout << a << " 和 " << mod << " 不互质，不存在模逆元" << endl;
    } else {
        cout << a << " 模 " << mod << " 的逆元是: " << mod_inverse(a, mod) << endl;
    }

    return 0;
}
```

### 2. 求解同余方程

利用欧拉定理可以快速求解某些同余方程。

```cpp
#include <bits/stdc++.h>
using namespace std;

// 快速幂取模
long long fast_pow(long long a, long long b, long long mod) {
    long long result = 1;
    a %= mod;

    while (b > 0) {
        if (b & 1) {
            result = (result * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }

    return result;
}

// 计算欧拉函数
int euler_phi(int n) {
    int result = n;
    for (int p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            while (n % p == 0) {
                n /= p;
            }
            result -= result / p;
        }
    }
    if (n > 1) {
        result -= result / n;
    }
    return result;
}

// 求解 a^x ≡ b (mod m)，其中a和m互质
long long solve_congruence(long long a, long long b, long long m) {
    if (__gcd(a, m) != 1) {
        return -1;  // 无解或需要特殊处理
    }

    int phi_m = euler_phi(m);

    // 利用欧拉定理：a^φ(m) ≡ 1 (mod m)
    // 因此 a^(k*φ(m) + r) ≡ a^r (mod m)

    // 简单情况：尝试较小的指数
    for (int x = 0; x < min(phi_m, 1000); x++) {
        if (fast_pow(a, x, m) == b % m) {
            return x;
        }
    }

    return -1;  // 未找到解
}

int main() {
    long long a, b, m;
    cin >> a >> b >> m;

    long long solution = solve_congruence(a, b, m);

    if (solution != -1) {
        cout << "方程 " << a << "^x ≡ " << b << " (mod " << m << ") 的解是: x = " << solution << endl;
    } else {
        cout << "方程无解或解超出搜索范围" << endl;
    }

    return 0;
}
```

### 3. 欧拉降幂

利用欧拉定理可以简化大指数的模运算。

**欧拉降幂公式**：
若b ≥ φ(m)，则：
$$a^b \bmod m = a^{b \bmod \phi(m) + \phi(m)} \bmod m$$

```cpp
#include <bits/stdc++.h>
using namespace std;

// 快速幂取模
long long fast_pow(long long a, long long b, long long mod) {
    long long result = 1;
    a %= mod;

    while (b > 0) {
        if (b & 1) {
            result = (result * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }

    return result;
}

// 计算欧拉函数
int euler_phi(int n) {
    int result = n;
    for (int p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            while (n % p == 0) {
                n /= p;
            }
            result -= result / p;
        }
    }
    if (n > 1) {
        result -= result / n;
    }
    return result;
}

// 欧拉降幂计算
long long euler_pow(long long a, long long b, long long m) {
    if (m == 1) return 0;  // 特殊情况

    int phi_m = euler_phi(m);

    if (b >= phi_m) {
        b = b % phi_m + phi_m;  // 欧拉降幂
    }

    return fast_pow(a, b, m);
}

int main() {
    long long a, b, m;
    cin >> a >> b >> m;

    cout << a << "^" << b << " mod " << m << " = " << euler_pow(a, b, m) << endl;

    return 0;
}
```

## 常见例题

### 例题1：求欧拉函数值之和

题目：求给定范围内所有数的欧拉函数值之和。

```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int phi[N];

// 线性筛预处理欧拉函数
void euler_sieve(int n) {
    vector<int> primes;
    bool is_composite[N] = {false};

    phi[0] = 0;
    phi[1] = 1;

    for (int i = 2; i <= n; i++) {
        if (!is_composite[i]) {
            primes.push_back(i);
            phi[i] = i - 1;
        }

        for (int j = 0; j < primes.size() && i * primes[j] <= n; j++) {
            is_composite[i * primes[j]] = true;

            if (i % primes[j] == 0) {
                phi[i * primes[j]] = phi[i] * primes[j];
                break;
            } else {
                phi[i * primes[j]] = phi[i] * (primes[j] - 1);
            }
        }
    }

    // 计算前缀和
    for (int i = 2; i <= n; i++) {
        phi[i] += phi[i - 1];
    }
}

int main() {
    int n;
    cin >> n;

    euler_sieve(n);

    cout << "1到" << n << "的欧拉函数值之和: " << phi[n] << endl;

    return 0;
}
```

### 例题2：利用欧拉函数求互质数对

题目：给定n，求满足1 ≤ i < j ≤ n且gcd(i,j) = 1的数对(i,j)的个数。

```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int phi[N];

// 线性筛预处理欧拉函数
void euler_sieve(int n) {
    vector<int> primes;
    bool is_composite[N] = {false};

    phi[0] = 0;
    phi[1] = 1;

    for (int i = 2; i <= n; i++) {
        if (!is_composite[i]) {
            primes.push_back(i);
            phi[i] = i - 1;
        }

        for (int j = 0; j < primes.size() && i * primes[j] <= n; j++) {
            is_composite[i * primes[j]] = true;

            if (i % primes[j] == 0) {
                phi[i * primes[j]] = phi[i] * primes[j];
                break;
            } else {
                phi[i * primes[j]] = phi[i] * (primes[j] - 1);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    euler_sieve(n);

    long long result = 0;

    // 对于每个j，计算满足1 ≤ i < j且gcd(i,j) = 1的i的个数
    // 这正好是φ(j)
    for (int j = 2; j <= n; j++) {
        result += phi[j];
    }

    cout << "互质数对的个数: " << result << endl;

    return 0;
}
```

## 总结

欧拉函数和欧拉定理是数论中的重要工具，在信奥竞赛中有广泛应用：

1. **欧拉函数计算**：掌握直接计算和筛法预处理两种方法
2. **欧拉定理应用**：主要用于模运算、求模逆元、求解同余方程
3. **欧拉降幂**：处理大指数模运算的有效方法
4. **互质数对问题**：利用欧拉函数的性质快速求解

掌握这些知识点对于解决数论相关问题非常重要，建议多加练习相关题目。

# 费马小定理
## 余数的性质

### 可加性
设$x \div y = z \dots \dots c$ 
$x' \div y = z' \dots \dots c'$, 
则$(x+x') \div y = z'' \dots \dots (c+c')$

### 可减性
设$x \div y = z \dots \dots c$ 
$x' \div y = z' \dots \dots c'$, 
则$(x - x') \div y = z'' \dots \dots (c-c')$

### 可乘性
设$x \div y = z \dots \dots c$ 
$x' \div y = z' \dots \dots c'$, 
则$(x \times x') \div y = z'' \dots \dots (c \times c')$

### 可乘方性
设$x^t \div y = z \dots \dots c$ ,$a = x \mod y$ ,
则$a^t \div 5 = z' \dots \dots c$ ，
（可以看成可乘性，$t$个$c$相乘，结果大于了除数，然后在重新取个模）

### 公式
有一个质数$p$和一个数$a$,$a \mod p \neq 0$($a$不是$p$的倍数，即$a$和$p$互质)，则:
$$
\begin{aligned}
a^{p-1} &\equiv 1 \pmod{p} \\
a^p &\equiv a \pmod{p}
\end{aligned}
$$

# sin/cos/tan函数理论学习及使用（GESP 7级考点）

![](C:\Users\Administrator\Pictures\Screenshots\zjsjx.png)

这是7级知识点，我在学习7级是写的。

## 前提知识点，弧度

在扇形里：

弧度指的是一个弧长里有几个半径。

公式：$\frac{弧长}{半径}$

然后弧长从哪来呢？

当然是$\frac{圆心角}{360} \times 园的周长$。

然后圆的周长从哪来呢？

当然是$2 \times \pi \times r$。

设圆心角度为$o$,半径为$r$,带入得：

$$
弧长= \frac{2o}{360} \times  \pi \times r，
    弧度= \frac{\frac{2o}{360} \times  \pi \times r}{r}=2 \times \frac{o}{360} \times \pi
$$

### 重大问题：三角形里哪里来的弧？

这是一个非常棒的思考！你发现了一个关键：**三角形本身是没有“弧”的**，它是**直的**。

之所以会出现“弧长”，是因为我们**将三角形放进了一个“圆”里**。

#### 1. 动态图解：三角形是怎么“长”出弧来的？

想象你手里有一把圆规：

1. 定半径：针尖扎在原点 ，笔尖拉开一段距离（这就是半径 ，也是直角三角形的斜边）。

2. 画弧：笔尖从水平位置（x轴）向上转动，直到停在某个点 
   。
   第三步（补全三角形）：从点 
   向下作一条垂线到 x 轴。
   看这个示意图：
   
   ```
                 y轴 (高度)
                  ^
   
                  |           点 P (笔尖位置)
                  |          /|
       弧长 (s)   |        /  | 
        ~~~~~>    |  r (斜边) | y (对边/高度)
     (圆周上的线) |    /      | 
   
                  |  / θ(角)  |
     -------------+-----------+------------> x轴 (宽度)
                圆心         x (临边/宽度)
   
   ```



#### 2. 它们的关系：谁生了谁？

弧长 ($s$)：是笔尖在圆周上滑过的真实路程。

弧度 ($\theta$)：就是这个路程占了半径的几倍？（公式：$\theta = \frac{s}{r}$）。

三角形：是此时笔尖、圆心、投影点构成的直角三角形。

#### 3. 三角形怎么“算”出弧长？

如果你只知道三角形的边长，想反推“弧长”，逻辑是这样的：

1. 先求比例（正切/斜率）：通过三角形的$y \div x$ （对边除以临边），得到 $tan(\theta)$。
2. 求出弧度：用 C++ 的反正切函数 $atan(y \ x)$，电脑会告诉你：“对应的弧度是$\theta$”。
3. 最后算弧长：根据弧度的定义，$弧长 = 弧度 \times 半径 (r)$。


#### 三角形在c++如何快速的算出弧度？

使用atan2(y,x)函数，y指对边，x指临边，可以直接算出弧长。

感情我之前讲的都是废话是吧。。。
## sin
图像：

正弦（$sin$），给你直角三角型的弧度，可以算出对边（高）的。

$sin(x)=直角三角形的对边长$，$x=\theta$

## cos


![[Pasted image 20260315214749.png]]

>[!IMPORTANT]
>他是一个比例（数学中）所以他的所有值在 $1$ 到 $-1$ 之间  ；
>当 $x \mod \pi = 1$时，$y=-1$；
>当 $x \mod \pi = 0$时，$y=1$,  
 

余弦（$cos$），给你直角三角型的弧度，可以算出邻边（底）的。

$cos(x)=直角三角形的底边长$，$x=\theta$ 

## tan
正切（$tan$），正切我不知道有啥用，但是斜率就是正切，可以表示坡度

$tan(x)=直角三角形的斜率$，$x=\theta$ 


# 二叉排序树 (BST) 

在七级中，BST 是必须掌握的重点，通常考察**概念理解**与**基础算法实现**：

- **性质判定**：选择题中常给出先序/中序序列，让你判断是否能构成合法的 $BST$，或者计算特定序列插入后的树高。
- **插入与查找**：要求能手写或完善 `insert` 和 `search` 的递归/非递归函数。
- **中序遍历**：考察“BST 的中序遍历是升序序列”这一特性，常用于解决排序相关的填空题。
- **删除操作**：理解删除节点时的三种情况（叶子节点、单支节点、双支节点），双支节点通常用其**前驱**或**后继**节点替代。

# 平衡二叉树 (AVL)

七级通常不强制要求手写完整的 AVL 树（因为旋转逻辑较复杂），但会考察：

- **定义与特征**：理解“平衡因子”（Balance Factor）的概念，即左、右子树高度差不超过 1。
- **平衡判定**：给出一种树形结构，问这是否是平衡二叉树。
- **时间复杂度分析**：掌握平衡树的查找效率为 $O(\log n)$ ，而普通 BST 在极端情况下会退化为$O(n)$ 。
- **与红黑树对比**：了解红黑树也是一种平衡查找树，虽然平衡要求较宽，但性能更稳定。

# 乘法逆元

## 乘法逆元的概念

### 什么是乘法逆元？

**乘法逆元**是模运算中的一个重要概念。在模运算中，除法不能直接进行，我们需要通过乘法逆元来实现"除法"操作。

**定义**：对于整数a和正整数m，如果存在整数b，使得：
$$a \times b \equiv 1 \pmod{m}$$
那么b称为a模m的乘法逆元，记作$a^{-1} \equiv b \pmod{m}$。

### 为什么需要乘法逆元？

在组合数学和数论中，我们经常需要计算组合数：
$$C(n, k) = \frac{n!}{k!(n-k)!}$$

在模运算中，除法不能直接进行，因为除法本质上是乘以倒数。而在模运算中，倒数就是乘法逆元。

所以，我们需要将除法转换为乘法乘以逆元：
$$\frac{a}{b} \equiv a \times b^{-1} \pmod{m}$$

## 乘法逆元的性质

### 1. 存在性

乘法逆元存在的**充要条件**是：a和m互质，即$\gcd(a, m) = 1$。

### 2. 唯一性

当乘法逆元存在时，它在模m下是唯一的。

### 3. 计算性质

- $(a \times b)^{-1} \equiv a^{-1} \times b^{-1} \pmod{m}$
- $(a^{-1})^{-1} \equiv a \pmod{m}$
- 如果$a \equiv b \pmod{m}$，那么$a^{-1} \equiv b^{-1} \pmod{m}$

## 计算乘法逆元的方法

### 方法1：扩展欧几里得算法

这是最常用的方法，适用于任意模数m。

```cpp
#include <iostream>
using namespace std;

// 扩展欧几里得算法
// 返回gcd(a, b)，并求解x, y使得ax + by = gcd(a, b)
int exgcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    
    int x1, y1;
    int gcd = exgcd(b, a % b, x1, y1);
    
    x = y1;
    y = x1 - (a / b) * y1;
    
    return gcd;
}

// 计算a模m的乘法逆元
int mod_inverse(int a, int m) {
    int x, y;
    int gcd = exgcd(a, m, x, y);
    
    if (gcd != 1) {
        return -1;  // 逆元不存在，因为a和m不互质
    }
    
    // 确保结果为正数
    return (x % m + m) % m;
}

int main() {
    int a, m;
    cin >> a >> m;
    
    int inv = mod_inverse(a, m);
    if (inv == -1) {
        cout << a << " 和 " << m " 不互质，逆元不存在" << endl;
    } else {
        cout << a << " 模 " << m << " 的逆元是: " << inv << endl;
        cout << "验证: " << a << " * " << inv << " = " << (a * inv) % m << endl;
    }
    
    return 0;
}
```

### 方法2：费马小定理（仅适用于m为质数）

当m是质数时，根据费马小定理：
$$a^{m-1} \equiv 1 \pmod{m}$$
因此：
$$a^{-1} \equiv a^{m-2} \pmod{m}$$

```cpp
#include <iostream>
using namespace std;

// 快速幂取模
long long fast_pow(long long a, long long b, long long mod) {
    long long result = 1;
    a %= mod;
    
    while (b > 0) {
        if (b & 1) {
            result = (result * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    
    return result;
}

// 使用费马小定理计算逆元（仅适用于mod为质数）
long long fermat_inverse(long long a, long long mod) {
    return fast_pow(a, mod - 2, mod);
}

int main() {
    long long a, mod;
    cin >> a >> mod;
    
    // 检查mod是否为质数（这里简化处理，实际应该先判断）
    if (mod <= 1) {
        cout << "模数必须是大于1的质数" << endl;
        return 0;
    }
    
    long long inv = fermat_inverse(a, mod);
    cout << a << " 模 " << mod << " 的逆元是: " << inv << endl;
    cout << "验证: " << a << " * " << inv << " = " << (a * inv) % mod << endl;
    
    return 0;
}
```

### 方法3：递推法（适用于连续模数）

当模数是连续的整数时，可以使用递推法：

```cpp
#include <iostream>
using namespace std;

const int N = 1e6 + 5;
int inv[N];  // 存储逆元

// 递推计算逆元，适用于连续模数
void calc_inverse(int n) {
    inv[1] = 1;
    for (int i = 2; i <= n; i++) {
        inv[i] = (long long)(n - n / i) * inv[n % i] % n;
    }
}

int main() {
    int n;
    cin >> n;
    
    calc_inverse(n);
    
    for (int i = 1; i <= n; i++) {
        cout << i << " 的逆元: " << inv[i] << endl;
    }
    
    return 0;
}
```

## 乘法逆元的应用

### 1. 组合数计算

```cpp
#include <iostream>
using namespace std;

const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

long long fact[N], inv_fact[N];

// 快速幂取模
long long fast_pow(long long a, long long b, long long mod) {
    long long result = 1;
    a %= mod;
    
    while (b > 0) {
        if (b & 1) {
            result = (result * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    
    return result;
}

// 预处理阶乘和阶乘的逆元
void precompute(int n) {
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = (fact[i-1] * i) % MOD;
    }
    
    inv_fact[n] = fast_pow(fact[n], MOD-2, MOD);
    for (int i = n-1; i >= 0; i--) {
        inv_fact[i] = (inv_fact[i+1] * (i+1)) % MOD;
    }
}

// 计算组合数 C(n, k)
long long comb(int n, int k) {
    if (k < 0 || k > n) return 0;
    return (fact[n] * inv_fact[k] % MOD) * inv_fact[n-k] % MOD;
}

int main() {
    int n, k;
    cin >> n >> k;
    
    precompute(n);
    
    cout << "C(" << n << ", " << k << ") = " << comb(n, k) << endl;
    
    return 0;
}
```

### 2. 线性递推式求解

```cpp
#include <iostream>
using namespace std;

const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

long long f[N], inv[N];

void solve_linear_recurrence(int n) {
    // 预处理逆元
    inv[1] = 1;
    for (int i = 2; i <= n; i++) {
        inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
    }
    
    // 递推求解 f(n) = f(n-1) + 2 * f(n-2) + ... + n * f(0)
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        f[i] = 0;
        for (int j = 1; j <= i; j++) {
            f[i] = (f[i] + j * f[i-j]) % MOD;
        }
    }
    
    // 使用逆元优化：f(n) = f(n-1) + 2 * f(n-2) + ... + n * f(0)
    // 可以写成：f(n) = sum_{j=1}^{n} j * f(n-j)
    // 使用前缀和优化
}

int main() {
    int n;
    cin >> n;
    
    solve_linear_recurrence(n);
    
    for (int i = 0; i <= n; i++) {
        cout << "f(" << i << ") = " << f[i] << endl;
    }
    
    return 0;
}
```

### 3. 分数取模

```cpp
#include <iostream>
using namespace std;

// 计算a/b mod m
long long fraction_mod(long long a, long long b, long long m) {
    // 先计算b mod m的逆元
    long long inv_b = fast_pow(b, m-2, m);  // 假设m是质数
    return (a % m * inv_b) % m;
}

int main() {
    long long a, b, m;
    cin >> a >> b >> m;
    
    long long result = fraction_mod(a, b, m);
    cout << a << "/" << b << " mod " << m << " = " << result << endl;
    
    return 0;
}
```

## 常见问题与技巧

### 1. 逆元不存在的情况

当a和m不互质时，逆元不存在。在使用扩展欧几里得算法时，需要检查gcd(a, m)是否为1。

```cpp
int mod_inverse(int a, int m) {
    int x, y;
    int gcd = exgcd(a, m, x, y);
    
    if (gcd != 1) {
        return -1;  // 逆元不存在
    }
    
    return (x % m + m) % m;
}
```

### 2. 逆元的正数化

由于逆元可能是负数，需要将其转换为正数：
```cpp
int positive_inv = (x % m + m) % m;
```

### 3. 批量计算逆元

当需要计算多个数的逆元时，可以使用递推法：
```cpp
void calc_inverses(int n, int mod) {
    inv[1] = 1;
    for (int i = 2; i <= n; i++) {
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    }
}
```

### 4. 费马小定理的局限性

费马小定理只适用于模数是质数的情况。当模数不是质数时，必须使用扩展欧几里得算法。

## 实际应用示例

### 1. 组合数求和

```cpp
#include <iostream>
using namespace std;

const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

long long fact[N], inv_fact[N];

long long fast_pow(long long a, long long b, long long mod) {
    long long result = 1;
    a %= mod;
    
    while (b > 0) {
        if (b & 1) {
            result = (result * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    
    return result;
}

void precompute(int n) {
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = (fact[i-1] * i) % MOD;
    }
    
    inv_fact[n] = fast_pow(fact[n], MOD-2, MOD);
    for (int i = n-1; i >= 0; i--) {
        inv_fact[i] = (inv_fact[i+1] * (i+1)) % MOD;
    }
}

long long comb(int n, int k) {
    if (k < 0 || k > n) return 0;
    return (fact[n] * inv_fact[k] % MOD) * inv_fact[n-k] % MOD;
}

int main() {
    int n, k;
    cin >> n >> k;
    
    precompute(n);
    
    long long sum = 0;
    for (int i = 0; i <= n; i++) {
        sum = (sum + comb(n, i)) % MOD;
    }
    
    cout << "组合数求和: " << sum << endl;
    
    return 0;
}
```

### 2. 概率问题

```cpp
#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

long long fast_pow(long long a, long long b, long long mod) {
    long long result = 1;
    a %= mod;
    
    while (b > 0) {
        if (b & 1) {
            result = (result * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    
    return result;
}

// 计算概率：n次独立实验，每次成功概率为p，恰好k次成功的概率
long long probability(int n, int k, long long p) {
    // 将p转换为分数形式：p = a/b
    long long a = p;
    long long b = 100;  // 假设p是以百分数形式输入
    
    // 计算C(n, k) * p^k * (1-p)^(n-k)
    long long comb = 1;
    for (int i = 1; i <= k; i++) {
        comb = comb * (n - k + i) % MOD;
        comb = comb * fast_pow(i, MOD-2, MOD) % MOD;
    }
    
    long long p_pow = fast_pow(a, k, MOD);
    long long q_pow = fast_pow(b - a, n - k, MOD);
    
    return comb * p_pow % MOD * q_pow % MOD;
}

int main() {
    int n, k;
    long long p;
    cin >> n >> k >> p;
    
    long long result = probability(n, k, p);
    cout << "概率: " << result << endl;
    
    return 0;
}
```

## 总结

乘法逆元是数论中的重要概念，在信奥竞赛中有广泛应用：

1. **基本概念**：理解乘法逆元的定义和存在条件
2. **计算方法**：掌握扩展欧几里得算法和费马小定理
3. **应用场景**：组合数计算、分数取模、概率问题等
4. **优化技巧**：批量计算逆元、递推法等

熟练掌握乘法逆元对于解决数论相关问题非常重要，建议多加练习相关题目。

