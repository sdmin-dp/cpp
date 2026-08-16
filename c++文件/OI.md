# OI（信息学竞赛）知识与代码整合

## 基础知识

### 运算符

| 运算符 | 名称  | 例子      | 结果  |
| --- | --- | ------- | --- |
| `+` | 加法  | `3 + 2` | `5` |
| `-` | 减法  | `3 - 2` | `1` |
| `*` | 乘法  | `3 * 2` | `6` |
| `/` | 除法  | `3 / 2` | `1` |
| `%` | 取模  | `3 % 2` | `1` |

| 运算符  | 名称   | 例子       | 结果      |
| ---- | ---- | -------- | ------- |
| `==` | 等于   | `3 == 2` | `false` |
| `!=` | 不等于  | `3 != 2` | `true`  |
| `>`  | 大于   | `3 > 2`  | `true`  |
| `<`  | 小于   | `3 < 2`  | `false` |
| `>=` | 大于等于 | `3 >= 2` | `true`  |
| `<=` | 小于等于 | `3 <= 2` | `false` |

| 运算符  | 名称  | 例子              | 结果      |
| ---- | --- | --------------- | ------- |
| `&&` | 与   | `true && false` | `false` |
| `    |     | `               | 或       |
| `!`  | 非   | `!true`         | `false` |

---

### 变量与常量

```cpp
int a = 5;       // 整数变量
double b = 3.14; // 浮点数变量
char c = 'A';    // 字符变量

const int MAX = 100;       // 整数常量
const double PI = 3.14159; // 浮点数常量
```

---

### 分支与循环

```cpp
// if 语句
if (a > b) {
    cout << "a is greater than b";
} else {
    cout << "a is not greater than b";
}

// switch 语句
switch (grade) {
    case 'A':
        cout << "Excellent!";
        break;
    case 'B':
        cout << "Good!";
        break;
    default:
        cout << "Invalid grade";
}

// for 循环
for (int i = 0; i < 5; i++) {
    cout << i << " ";
}

// while 循环
int i = 0;
while (i < 5) {
    cout << i << " ";
    i++;
}
```

---

### 数组与字符串

```cpp
int arr[5] = {1, 2, 3, 4, 5}; // 整数数组
string s = "Hello, World!";   // 字符串
```

---

## 数据结构

### 栈与队列

```cpp
// 栈
stack<int> s;
s.push(1);
s.push(2);
s.push(3);
cout << s.top(); // 3
s.pop();
cout << s.top(); // 2

// 队列
queue<int> q;
q.push(1);
q.push(2);
q.push(3);
cout << q.front(); // 1
q.pop();
cout << q.front(); // 2

// 循环队列
int head = 0, tail = 0;
int a[100];
a[tail++] = 1; // push
int x = a[head++]; // pop
```

---

### 并查集

```cpp
struct bcj {
    vector<ll> fa;
    bcj(ll len) {
        fa.resize(len + 1);
        for (int i = 1; i <= len; i++) fa[i] = i;
    }
    ll find(ll x) {
        return x == fa[x] ? x : fa[x] = find(fa[x]);
    }
    void merge(ll x, ll y) {
        fa[find(x)] = find(y);
    }
};
```

---

### 单调栈与单调队列

```cpp
// 单调栈：下一个更大元素
ll n;
ll a[N], ans[N];
stack<ll> s;

for (int i = 1; i <= n; i++) {
    while (!s.empty() && a[s.top()] < a[i]) {
        ans[s.top()] = a[i];
        s.pop();
    }
    s.push(i);
}

// 单调队列：滑动窗口最大值
ll n, k;
ll a[N];
deque<ll> dq;

for (int i = 1; i <= n; i++) {
    while (!dq.empty() && a[dq.back()] <= a[i]) dq.pop_back();
    dq.push_back(i);
    if (dq.front() <= i - k) dq.pop_front();
    if (i >= k) cout << a[dq.front()] << " ";
}
```

---

### 树与图

```cpp
// 树的遍历
void dfs(ll x, ll fa) {
    for (auto i : g[x]) {
        if (i != fa) {
            dfs(i, x);
        }
    }
}

// 图的存储
vector<ll> g[N];

void add_edge(ll u, ll v) {
    g[u].push_back(v);
    g[v].push_back(u);
}
```

---

### 堆与优先队列

```cpp
priority_queue<ll> max_heap; // 大根堆
priority_queue<ll, vector<ll>, greater<ll>> min_heap; // 小根堆

max_heap.push(3);
max_heap.push(1);
max_heap.push(4);
cout << max_heap.top(); // 4
```

---

### 线段树

```cpp
struct segment {
    ll l, r, sum, tag;
} t[N * 4];

void pushup(ll idx) {
    t[idx].sum = t[idx * 2].sum + t[idx * 2 + 1].sum;
}

void build(ll l = 1, ll r = n, ll idx = 1) {
    t[idx].l = l, t[idx].r = r;
    if (l == r) {
        t[idx].sum = a[l];
        return;
    }
    ll mid = (l + r) / 2;
    build(l, mid, idx * 2);
    build(mid + 1, r, idx * 2 + 1);
    pushup(idx);
}

void pushdown(ll idx) {
    if (t[idx].tag == 0) return;
    ll l = t[idx].l, r = t[idx].r, tag = t[idx].tag;
    t[idx * 2].sum += (t[idx * 2].r - t[idx * 2].l + 1) * tag;
    t[idx * 2 + 1].sum += (t[idx * 2 + 1].r - t[idx * 2 + 1].l + 1) * tag;
    t[idx * 2].tag += tag;
    t[idx * 2 + 1].tag += tag;
    t[idx].tag = 0;
}

void update(ll s, ll e, ll k, ll idx = 1) {
    ll l = t[idx].l, r = t[idx].r;
    if (s <= l && r <= e) {
        t[idx].sum += (r - l + 1) * k;
        t[idx].tag += k;
        return;
    }
    pushdown(idx);
    ll mid = (l + r) / 2;
    if (s <= mid) update(s, e, k, idx * 2);
    if (e > mid) update(s, e, k, idx * 2 + 1);
    pushup(idx);
}

ll query(ll s, ll e, ll idx = 1) {
    ll l = t[idx].l, r = t[idx].r;
    if (s <= l && r <= e) return t[idx].sum;
    if (s > r || e < l) return 0;
    pushdown(idx);
    return query(s, e, idx * 2) + query(s, e, idx * 2 + 1);
}
```

---

### 字符串算法

#### KMP 算法

```cpp
string s, t;
ll n, m, nxt[N];

// 构建 next 数组
for (int i = 1, j = 0; i < m; i++) {
    while (j > 0 && t[i] != t[j]) j = nxt[j - 1];
    if (t[i] == t[j]) j++;
    nxt[i] = j;
}

// 匹配
for (int i = 0, j = 0; i < n; i++) {
    while (j > 0 && s[i] != t[j]) j = nxt[j - 1];
    if (s[i] == t[j]) j++;
    if (j == m) {
        cout << i - m + 1 << el;
        j = nxt[j - 1];
    }
}
```

#### 字符串哈希

```cpp
const ll base = 131;
const ll mod = 1e9 + 7;
ll h[N], p[N];

void init_hash(string s) {
    p[0] = 1;
    for (int i = 1; i <= s.size(); i++) {
        h[i] = (h[i - 1] * base + s[i - 1]) % mod;
        p[i] = (p[i - 1] * base) % mod;
    }
}

ll get_hash(ll l, ll r) {
    return (h[r] - h[l - 1] * p[r - l + 1] % mod + mod) % mod;
}
```

---

## 算法

### 排序算法

```cpp
// 冒泡排序
for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
        if (arr[j] > arr[j + 1]) {
            swap(arr[j], arr[j + 1]);
        }
    }
}

// 快速排序
void quickSort(int arr[], int left, int right) {
    if (left >= right) return;
    int pivot = arr[left];
    int i = left, j = right;
    while (i < j) {
        while (i < j && arr[j] >= pivot) j--;
        arr[i] = arr[j];
        while (i < j && arr[i] <= pivot) i++;
        arr[j] = arr[i];
    }
    arr[i] = pivot;
    quickSort(arr, left, i - 1);
    quickSort(arr, i + 1, right);
}
```

---

### 贪心算法

#### 区间选点问题

```cpp
pair<ll, ll> a[N];
ll n;

bool cmp(pair<ll, ll> x, pair<ll, ll> y) {
    return x.second < y.second;
}

sort(a + 1, a + n + 1, cmp);
ll last = a[1].second, ans = 1;
for (int i = 2; i <= n; i++) {
    if (a[i].first > last) {
        ans++;
        last = a[i].second;
    }
}
```

#### 区间覆盖问题

```cpp
sort(a + 1, a + n + 1, cmp);
ll l = a[1].first, r = a[1].second, ans = 0;
for (int i = 2; i <= n; i++) {
    if (l <= a[i].first && a[i].second <= r) {
        ans++;
    } else {
        l = a[i].first;
        r = a[i].second;
    }
}
```

---

### 动态规划

#### 01 背包

```cpp
ll W, n;
ll w[N], v[N], dp[N];

for (int i = 1; i <= n; i++) {
    for (int j = W; j >= w[i]; j--) {
        dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    }
}
```

#### 完全背包

```cpp
for (int i = 1; i <= n; i++) {
    for (int j = w[i]; j <= W; j++) {
        dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    }
}
```

#### 多重背包（二进制优化）

```cpp
for (int i = 1; i <= n; i++) {
    ll num, wi, vi;
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
```

#### 区间 DP

```cpp
// 石子合并
for (int len = 2; len <= n; len++) {
    for (int i = 1; i + len - 1 <= n; i++) {
        int j = i + len - 1;
        for (int k = i; k < j; k++) {
            dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1]);
        }
    }
}
```

---

### 搜索与回溯

```cpp
// DFS
void dfs(ll x) {
    vis[x] = 1;
    for (auto i : g[x]) {
        if (!vis[i]) {
            dfs(i);
        }
    }
}

// BFS
queue<ll> q;
q.push(1);
dis[1] = 0;
while (!q.empty()) {
    ll x = q.front();
    q.pop();
    for (auto i : g[x]) {
        if (dis[i] == -1) {
            dis[i] = dis[x] + 1;
            q.push(i);
        }
    }
}
```

---

### 图论算法

#### Dijkstra 算法

```cpp
ll n, m;
vector<pair<ll, ll>> g[N];
ll dis[N];

void dijkstra(ll s) {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    q.push({0, s});
    while (!q.empty()) {
        auto x = q.top();
        q.pop();
        if (x.first > dis[x.second]) continue;
        for (auto i : g[x.second]) {
            if (dis[x.second] + i.second < dis[i.first]) {
                dis[i.first] = dis[x.second] + i.second;
                q.push({dis[i.first], i.first});
            }
        }
    }
}
```

#### Floyd 算法

```cpp
for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        }
    }
}
```

#### 最小生成树（Kruskal）

```cpp
struct edge {
    ll u, v, w;
} e[N];

bool cmp(edge a, edge b) {
    return a.w < b.w;
}

ll kruskal() {
    sort(e + 1, e + m + 1, cmp);
    bcj dsu(n);
    ll ans = 0, cnt = 0;
    for (int i = 1; i <= m; i++) {
        if (dsu.find(e[i].u) != dsu.find(e[i].v)) {
            dsu.merge(e[i].u, e[i].v);
            ans += e[i].w;
            cnt++;
            if (cnt == n - 1) break;
        }
    }
    return ans;
}
```

---

### 数论

#### 质数筛（埃氏筛）

```cpp
bool is_prime[N];
vector<ll> primes;

void aishai(ll n) {
    memset(is_prime, 1, sizeof(is_prime));
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * 2; j <= n; j += i) {
                is_prime[j] = 0;
            }
        }
    }
}
```

#### 欧拉筛（线性筛）

```cpp
void oulashai(ll n) {
    memset(is_prime, 1, sizeof(is_prime));
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) primes.push_back(i);
        for (auto p : primes) {
            if (i * p > n) break;
            is_prime[i * p] = 0;
            if (i % p == 0) break;
        }
    }
}
```

#### 快速幂

```cpp
ll qpow(ll a, ll b, ll mod) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
```

#### 最大公约数（GCD）

```cpp
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}
```

#### 扩展欧几里得算法

```cpp
ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
```

---

### 组合数学

#### 排列组合

```cpp
// 排列数 A(n, m) = n! / (n - m)!
ll A(ll n, ll m) {
    ll res = 1;
    for (int i = n - m + 1; i <= n; i++) {
        res *= i;
    }
    return res;
}

// 组合数 C(n, m) = n! / (m! * (n - m)!)
ll C(ll n, ll m) {
    if (m > n) return 0;
    ll res = 1;
    for (int i = 1; i <= m; i++) {
        res = res * (n - m + i) / i;
    }
    return res;
}
```

#### 容斥原理

```cpp
ll inclusion_exclusion(vector<ll>& conditions) {
    ll res = 0;
    for (int mask = 1; mask < (1 << conditions.size()); mask++) {
        ll lcm = 1, cnt = 0;
        for (int i = 0; i < conditions.size(); i++) {
            if (mask & (1 << i)) {
                lcm = lcm * conditions[i] / gcd(lcm, conditions[i]);
                cnt++;
            }
        }
        if (cnt % 2 == 1) {
            res += n / lcm;
        } else {
            res -= n / lcm;
        }
    }
    return res;
}
```

#### Lucas 定理

```cpp
ll lucas(ll n, ll m, ll p) {
    if (m == 0) return 1;
    return C(n % p, m % p) * lucas(n / p, m / p, p) % p;
}
```

---

## 模板代码

### 常用模板

```cpp
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;

void solve() {
    // 主逻辑
}

int main() {
    ll T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
```

### 并查集

```cpp
struct bcj {
    vector<ll> fa;
    bcj(ll len) {
        fa.resize(len + 1);
        for (int i = 1; i <= len; i++) fa[i] = i;
    }
    ll find(ll x) {
        return x == fa[x] ? x : fa[x] = find(fa[x]);
    }
    void merge(ll x, ll y) {
        fa[find(x)] = find(y);
    }
};
```

### 线段树

```cpp
struct segment {
    ll l, r, sum, tag;
} t[N * 4];

void pushup(ll idx) {
    t[idx].sum = t[idx * 2].sum + t[idx * 2 + 1].sum;
}

void build(ll l, ll r, ll idx) {
    t[idx].l = l, t[idx].r = r;
    if (l == r) {
        t[idx].sum = a[l];
        return;
    }
    ll mid = (l + r) / 2;
    build(l, mid, idx * 2);
    build(mid + 1, r, idx * 2 + 1);
    pushup(idx);
}

void pushdown(ll idx) {
    if (t[idx].tag == 0) return;
    ll l = t[idx].l, r = t[idx].r, tag = t[idx].tag;
    t[idx * 2].sum += (t[idx * 2].r - t[idx * 2].l + 1) * tag;
    t[idx * 2 + 1].sum += (t[idx * 2 + 1].r - t[idx * 2 + 1].l + 1) * tag;
    t[idx * 2].tag += tag;
    t[idx * 2 + 1].tag += tag;
    t[idx].tag = 0;
}

void update(ll s, ll e, ll k, ll idx) {
    ll l = t[idx].l, r = t[idx].r;
    if (s <= l && r <= e) {
        t[idx].sum += (r - l + 1) * k;
        t[idx].tag += k;
        return;
    }
    pushdown(idx);
    ll mid = (l + r) / 2;
    if (s <= mid) update(s, e, k, idx * 2);
    if (e > mid) update(s, e, k, idx * 2 + 1);
    pushup(idx);
}

ll query(ll s, ll e, ll idx) {
    ll l = t[idx].l, r = t[idx].r;
    if (s <= l && r <= e) return t[idx].sum;
    if (s > r || e < l) return 0;
    pushdown(idx);
    return query(s, e, idx * 2) + query(s, e, idx * 2 + 1);
}
```

### KMP 算法

```cpp
vector<ll> build_next(string t) {
    vector<ll> nxt(t.size(), 0);
    for (int i = 1, j = 0; i < t.size(); i++) {
        while (j > 0 && t[i] != t[j]) j = nxt[j - 1];
        if (t[i] == t[j]) j++;
        nxt[i] = j;
    }
    return nxt;
}

vector<ll> kmp(string s, string t) {
    vector<ll> nxt = build_next(t);
    vector<ll> res;
    for (int i = 0, j = 0; i < s.size(); i++) {
        while (j > 0 && s[i] != t[j]) j = nxt[j - 1];
        if (s[i] == t[j]) j++;
        if (j == t.size()) {
            res.push_back(i - j + 1);
            j = nxt[j - 1];
        }
    }
    return res;
}
```

### Dijkstra 算法

```cpp
void dijkstra(ll s) {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    q.push({0, s});
    while (!q.empty()) {
        auto x = q.top();
        q.pop();
        if (x.first > dis[x.second]) continue;
        for (auto i : g[x.second]) {
            if (dis[x.second] + i.second < dis[i.first]) {
                dis[i.first] = dis[x.second] + i.second;
                q.push({dis[i.first], i.first});
            }
        }
    }
}
```

### SPFA 算法

```cpp
void spfa(ll s) {
    queue<ll> q;
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    q.push(s);
    vis[s] = 1;
    while (!q.empty()) {
        ll x = q.front();
        q.pop();
        vis[x] = 0;
        for (auto i : g[x]) {
            if (dis[x] + i.second < dis[i.first]) {
                dis[i.first] = dis[x] + i.second;
                if (!vis[i.first]) {
                    q.push(i.first);
                    vis[i.first] = 1;
                }
            }
        }
    }
}
```

### Floyd 算法

```cpp
for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        }
    }
}
```

### 树状数组

```cpp
ll lowbit(ll x) {
    return x & -x;
}

void update(ll x, ll k) {
    while (x <= n) {
        c[x] += k;
        x += lowbit(x);
    }
}

ll query(ll x) {
    ll res = 0;
    while (x) {
        res += c[x];
        x -= lowbit(x);
    }
    return res;
}
```

### ST 表

```cpp
void init_st() {
    for (int i = 1; i <= n; i++) st[i][0] = a[i];
    for (int j = 1; j <= logn; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}

ll query_st(ll l, ll r) {
    ll k = log2(r - l + 1);
    return max(st[l][k], st[r - (1 << k) + 1][k]);
}
```

---

## 题目解析

### 石子合并

**问题描述**：有 `n` 堆石子排成一排，每次可以合并相邻的两堆，代价为两堆石子的总数。求最小代价。

**解题思路**：区间 DP。

```cpp
for (int len = 2; len <= n; len++) {
    for (int i = 1; i + len - 1 <= n; i++) {
        int j = i + len - 1;
        for (int k = i; k < j; k++) {
            dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1]);
        }
    }
}
```

### 最短路径问题

**问题描述**：给定一个有向图，求从起点到终点的最短路径。

**解题思路**：Dijkstra 或 SPFA。

### 背包问题

**问题描述**：有 `N` 个物品和一个容量为 `W` 的背包，每个物品有重量和价值，求最大价值。

**解题思路**：01 背包或完全背包。

---

## 竞赛技巧

### 二分查找

```cpp
ll l = 0, r = n;
while (l < r) {
    ll mid = (l + r) / 2;
    if (check(mid)) {
        r = mid;
    } else {
        l = mid + 1;
    }
}
```

### 离散化

```cpp
vector<ll> alls;
for (int i = 1; i <= n; i++) {
    alls.push_back(a[i]);
}
sort(alls.begin(), alls.end());
alls.erase(unique(alls.begin(), alls.end()), alls.end());

ll get_id(ll x) {
    return lower_bound(alls.begin(), alls.end(), x) - alls.begin() + 1;
}
```

### 高精度计算

```cpp
vector<int> add(vector<int> a, vector<int> b) {
    vector<int> c;
    int t = 0;
    for (int i = 0; i < a.size() || i < b.size(); i++) {
        if (i < a.size()) t += a[i];
        if (i < b.size()) t += b[i];
        c.push_back(t % 10);
        t /= 10;
    }
    if (t) c.push_back(t);
    return c;
}
```

### 位运算技巧

```cpp
// 判断第 k 位是否为 1
if (x & (1 << k)) {
    // ...
}

// 低位的 1 变为 0
x &= (x - 1);
```
