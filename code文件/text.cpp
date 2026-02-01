<<<<<<< HEAD
#include<bits/stdc++.h>
#define ll long long

using namespace std;

vector<int> g[1005];
int match[1005], vis[1005];

bool dfs(int u) {
    for (auto v : g[u]) {
        if (!vis[v]) {
            vis[v] = true;
            if (!match[v] || dfs(match[v])) {
                match[v] = u;
                return 1 ;
            }
        }
=======
#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> v; // 教练占用数组，v[coach]表示被哪个学生占用
vector<pair<int, int>> p; // 学生志愿，p[i] = (a_i, b_i)
int res = 0; // 全局成功计数器

// 匹配函数：处理学生x的分配
void match(int x) {
    int a = p[x].first;
    int b = p[x].second;
    
    // 尝试第一志愿教练a
    if (v[a] == 0) {
        // 教练空闲，直接占用
        v[a] = x;
        res++;
    } else if (v[a] > x) {
        // 踢出占用者（编号更大的学生）
        int t = v[a];
        res--; // 被踢出学生失去教练
        v[a] = x;
        res++; // 当前学生获得教练
        match(t); // 重新分配被踢出的学生
    } else {
        // 占用者编号更小，无法踢出，尝试第二志愿教练b
        if (v[b] == 0) {
            v[b] = x;
            res++;
        } else if (v[b] > x) {
            int t = v[b];
            res--;
            v[b] = x;
            res++;
            match(t);
        }
        // 如果第二志愿也无法占用，学生x失败，不操作
>>>>>>> dc16c6c01fb6ac99ca5648a22e1ca87f351809a0
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    v.resize(m + 1, 0); // 初始化教练占用数组
    p.resize(n + 1);
    
    // 读入学生志愿
    for (int i = 1; i <= n; i++) {
        cin >> p[i].first >> p[i].second;
    }
    
    vector<int> ans(n + 1); // 答案数组
    // 倒序处理每个学生
    for (int i = n; i >= 1; i--) {
        match(i);
        ans[i] = res; // 记录当前成功人数
    }
    
    // 输出答案
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << "\n";
    }
    
    return 0;
}

void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof(vis));
        cnt += dfs(i);
    }
    cout << cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // freopen("xxx.in", "r", stdin);
    // freopen("xxx.out", "w", stdout);

    int T = 1; // cin >> T;
    while(T--) {
        solve();
    }

    return 0;
}