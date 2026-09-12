#include <bits/stdc++.h>
using namespace std;

// ====================== 全局常量定义 ======================
const int N = 5e5 + 10;     // 模板支持的最大节点数，适配CSP-J常见的n<=5e5的场景
const int LOG = 21;          // 倍增的最大层数，log2(5e5)≈19，加2冗余保证不越界，2^21=2097152足够覆盖所有情况

// ====================== 倍增LCA核心数组 ======================
// 祖先倍增表：f[u][j] 表示节点 u 的 2^j 级祖先
// 2^j级祖先的意思：从u往上跳 2^j 步，最终到达的节点
// 比如 j=0 就是跳1步（父节点），j=1就是跳2步（爷爷节点），j=2就是跳4步，以此类推
int f[N][LOG];              
int dep[N];                 // 节点的深度，根节点的深度为1，父节点深度比子节点小1，用于深度对齐

// ====================== 路径边权扩展信息 ======================
// 注意：树的边权我们采用「下放到子节点」的存储方式：每条边的权值存在它的子节点上
// 因为每个子节点唯一对应一条到父节点的边，这样处理路径信息非常方便
int max_edge[N][LOG];       // u 到 2^j级祖先 路径上的最大边权
int min_edge[N][LOG];       // u 到 2^j级祖先 路径上的最小边权
long long sum_edge[N][LOG]; // u 到 2^j级祖先 路径上的边权总和（用long long避免溢出）

// ====================== 节点权值扩展信息 ======================
long long sum_val[N];       // 根节点 到 u 节点的路径上，所有节点权值的总和
int xor_val[N];             // 根节点 到 u 节点的路径上，所有节点权值的异或和
int val[N];                 // 每个节点自己的权值，输入时赋值

// ====================== DFS序与子树信息 ======================
int in[N], out[N], dfn[N], tim; 
// in[u]: DFS进入节点u的时间戳（也就是DFS序的下标）
// out[u]: DFS离开节点u的时间戳
// dfn[tim]: 时间戳tim对应的节点，也就是DFS序的第tim个节点
// tim: 时间戳计数器
int sz[N];                  // 节点u的子树大小，包含u自己

// ====================== 邻接表 ======================
// 存储树的边，pair<目标节点v, 边权w>，无向树加边时需要双向添加
vector<pair<int, int>> g[N];

/**
 * @brief DFS预处理函数，递归处理每个节点，初始化所有倍增数组、深度、DFS序等
 * @param u 当前处理的节点
 * @param fa 当前节点的父节点
 * @param w 当前节点到父节点的边权，根节点没有父节点，默认传0
 */
void dfs(int u, int fa, int w = 0) {
    // ---------- 初始化j=0的情况（也就是跳1步，父节点的信息） ----------
    f[u][0] = fa;                // u的1步祖先就是父节点fa
    dep[u] = dep[fa] + 1;       // u的深度 = 父节点深度+1
    max_edge[u][0] = w;         // u到父节点的边，最大边权就是这条边自己的权值
    // 根节点没有父节点，所以min_edge初始为无穷大，避免影响后续的min计算
    min_edge[u][0] = (u == fa ? INT_MAX : w); 
    sum_edge[u][0] = w;         // u到父节点的边，总和就是这条边自己的权值
    
    // ---------- 初始化DFS序与子树大小 ----------
    in[u] = ++tim;              // 记录进入u的时间戳
    dfn[tim] = u;               // 记录这个时间戳对应的节点
    sz[u] = 1;                  // 子树大小初始为1，也就是u自己
    
    // ---------- 预处理所有j>=1的倍增信息 ----------
    // 倍增的核心：大的步可以拆成两个小的步，2^j = 2^(j-1) + 2^(j-1)
    // 所以u的2^j级祖先 = u的2^(j-1)级祖先 的 2^(j-1)级祖先
    for (int j = 1; j < LOG; j++) {
        int mid = f[u][j - 1]; // 先跳2^(j-1)步到达的中间节点
        f[u][j] = f[mid][j - 1]; // 再跳2^(j-1)步，总共跳2^j步
        
        // 同理，路径的最大/最小/和，都可以拆成两段的合并
        max_edge[u][j] = max(max_edge[u][j - 1], max_edge[mid][j - 1]);
        min_edge[u][j] = min(min_edge[u][j - 1], min_edge[mid][j - 1]);
        sum_edge[u][j] = sum_edge[u][j - 1] + sum_edge[mid][j - 1];
    }
    
    // ---------- 递归处理子节点 ----------
    for (auto &e : g[u]) {
        int v = e.first, edge_w = e.second; // 子节点v，u到v的边权edge_w
        if (v == fa) continue; // 跳过父节点，避免往回走
        
        // 预处理根到v的节点权值信息：根到v = 根到u + v自己的权值
        sum_val[v] = sum_val[u] + val[v];
        xor_val[v] = xor_val[u] ^ val[v];
        
        dfs(v, u, edge_w); // 递归处理子节点v
        sz[u] += sz[v];    // 子树大小累加：u的子树大小 += 子节点v的子树大小
    }
    
    out[u] = tim; // 记录离开u的时间戳，此时u的所有子节点都处理完了
}

/**
 * @brief 基础LCA查询：查询节点u和节点v的最近公共祖先
 * @return 最近公共祖先的节点编号
 */
int lca(int u, int v) {
    // 保证u是更深的那个节点，如果u比v浅，交换两者
    if (dep[u] < dep[v]) swap(u, v);
    
    // ---------- 第一步：深度对齐，把u往上跳，直到u和v深度相同 ----------
    // 从最大的步开始贪心跳，优先跳大的步，保证跳的次数最少
    for (int j = LOG - 1; j >= 0; j--) {
        // 如果跳2^j步之后，u的深度仍然大于等于v的深度，就跳
        if (dep[f[u][j]] >= dep[v]) u = f[u][j];
    }
    // 跳完之后，如果u和v已经相同了，说明v就是u的祖先，直接返回v
    if (u == v) return u;
    
    // ---------- 第二步：u和v一起往上跳，直到他们的父节点就是LCA ----------
    for (int j = LOG - 1; j >= 0; j--) {
        // 如果跳完之后u和v的祖先不同，说明还没到LCA，就一起跳
        if (f[u][j] != f[v][j]) {
            u = f[u][j];
            v = f[v][j];
        }
    }
    // 最后，u和v的父节点就是他们的最近公共祖先
    return f[u][0];
}

/**
 * @brief 查询u到v路径上的最大边权
 * @return 路径上的最大边权值
 */
int query_max_edge(int u, int v) {
    int res = 0; // 结果初始为0
    // 保证u是更深的节点
    if (dep[u] < dep[v]) swap(u, v);
    
    // 第一步：深度对齐，把u往上跳，同时累加路径的最大边权
    for (int j = LOG - 1; j >= 0; j--) {
        if (dep[f[u][j]] >= dep[v]) {
            res = max(res, max_edge[u][j]); // 把这段路径的最大边权更新到结果里
            u = f[u][j];
        }
    }
    if (u == v) return res; // 已经到同一个节点，直接返回结果
    
    // 第二步：一起往上跳，同时累加两边的最大边权
    for (int j = LOG - 1; j >= 0; j--) {
        if (f[u][j] != f[v][j]) {
            res = max(res, max_edge[u][j]); // u这边的路径最大
            res = max(res, max_edge[v][j]); // v这边的路径最大
            u = f[u][j];
            v = f[v][j];
        }
    }
    // 最后还要加上u和v到LCA的那两条边，因为上面的循环没处理到
    res = max(res, max_edge[u][0]);
    res = max(res, max_edge[v][0]);
    return res;
}

/**
 * @brief 查询u到v路径上的最小边权
 * @return 路径上的最小边权值
 */
int query_min_edge(int u, int v) {
    int res = INT_MAX; // 结果初始为无穷大
    if (dep[u] < dep[v]) swap(u, v);
    
    // 深度对齐
    for (int j = LOG - 1; j >= 0; j--) {
        if (dep[f[u][j]] >= dep[v]) {
            res = min(res, min_edge[u][j]);
            u = f[u][j];
        }
    }
    if (u == v) return res;
    
    // 一起跳
    for (int j = LOG - 1; j >= 0; j--) {
        if (f[u][j] != f[v][j]) {
            res = min(res, min_edge[u][j]);
            res = min(res, min_edge[v][j]);
            u = f[u][j];
            v = f[v][j];
        }
    }
    // 最后加两条到LCA的边
    res = min(res, min_edge[u][0]);
    res = min(res, min_edge[v][0]);
    return res;
}

/**
 * @brief 查询u到v路径上的边权总和
 * @return 路径上所有边的权值和
 */
long long query_sum_edge(int u, int v) {
    long long res = 0;
    int l = lca(u, v); // 先拿到LCA
    int a = u, b = v;
    
    if (dep[a] < dep[b]) swap(a, b);
    // 深度对齐，累加边权和
    for (int j = LOG - 1; j >= 0; j--) {
        if (dep[f[a][j]] >= dep[b]) {
            res += sum_edge[a][j];
            a = f[a][j];
        }
    }
    if (a != b) {
        // 一起跳，累加两边的和
        for (int j = LOG - 1; j >= 0; j--) {
            if (f[a][j] != f[b][j]) {
                res += sum_edge[a][j];
                res += sum_edge[b][j];
                a = f[a][j];
                b = f[b][j];
            }
        }
        // 最后加两条到LCA的边
        res += sum_edge[a][0];
        res += sum_edge[b][0];
    }
    return res;
}

/**
 * @brief 将节点u向上跳k步，返回最终跳到的节点
 * @param u 起始节点
 * @param k 要跳的步数
 * @return 跳到的目标节点
 */
int jump(int u, int k) {
    // 把k拆成二进制，比如k=5=101，就是跳4步+跳1步
    for (int j = LOG - 1; j >= 0; j--) {
        if (k >= (1 << j)) { // 如果k还够跳2^j步，就跳
            u = f[u][j];
            k -= (1 << j);
        }
    }
    return u;
}

/**
 * @brief O(1)判断u是否是v的祖先（包含u==v的情况）
 * 原理：子树的所有节点的DFS序都在[u的in, u的out]之间
 */
bool is_ancestor(int u, int v) {
    return in[u] <= in[v] && out[v] <= out[u];
}

/**
 * @brief 模板的初始化函数，读入完树和节点权值后调用
 * @param root 树的根节点，一般传1
 * @param n 树的总节点数
 */
void init(int root, int n) {
    tim = 0;          // 时间戳清零
    dep[0] = 0;       // 虚拟节点0的深度为0，保证根的深度为1
    sum_val[root] = val[root]; // 根的节点权值和就是自己
    xor_val[root] = val[root]; // 根的异或和就是自己
    dfs(root, 0);    // 从根开始DFS预处理
}

// ====================== 使用示例 ======================
int main() {
    // 加速cin，解决cin慢的问题，竞赛必加
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    /*
    使用模板的步骤：
    1. 读入n
    2. 读入n-1条边，每条边u,v,w，调用：
       g[u].emplace_back(v, w);
       g[v].emplace_back(u, w);
    3. 读入每个节点的权值val[1], val[2]...val[n]
    4. 调用init(root, n)，root一般是1
    5. 之后就可以调用各个查询函数了！
    
    额外的常用计算：
    - 求u到v的节点权值和：
      int l = lca(u, v);
      long long sum = sum_val[u] + sum_val[v] - 2 * sum_val[l] + val[l];
      （因为sum_val[u]+sum_val[v]把根到l的部分加了两次，减两次，然后l自己的权值被减没了，加回来）
    
    - 求u的子树的节点权值和：
      可以自己加一个前缀和数组sum_dfn，sum_dfn[i] = sum_dfn[i-1] + val[dfn[i]]
      那么子树u的和就是 sum_dfn[out[u]] - sum_dfn[in[u]-1]
    */
    
    return 0;
}
