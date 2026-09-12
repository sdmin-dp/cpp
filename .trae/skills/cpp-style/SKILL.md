---
name: "cpp-style"
description: "按照用户的 C++ 代码风格和习惯生成代码。当用户要求编写 C++ 代码、算法题解或竞赛代码时自动调用此技能，确保生成的代码符合用户的编码风格。"
---
# C++ 代码风格指南

本技能确保 AI 生成的 C++ 代码完全符合用户的编码习惯和风格偏好。

## 核心代码模板

所有 C++ 代码必须遵循以下固定模板结构：

```cpp
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;  // 根据题目调整大小

// 全局变量声明在这里

void solve(){
    // 主逻辑代码
  for ()
}

int main(){
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

## 代码风格规范

### 1. 头文件和预处理

- **必须使用** `#include<bits/stdc++.h>`（万能头文件）
- **必须使用** `using namespace std;`
- **必须定义** `#define ll long long`（统一使用 ll 作为 long long）
- **必须定义** `#define el '\n'`（使用 el 代替 '\n'）

### 2. 常量和数组大小

- 使用 `const ll N=xxx+5;` 定义最大数组大小
- 数组大小通常是 10 的幂次加 5（如 1e5+5, 2e5+5, 1e6+5）
- 对于特殊题目，使用具体的数值（如 50+5, 30+5）

### 3. 变量命名

- 使用简短的单字母或双字母变量名：`n, m, x, y, u, v, w, k, i, j, l, r`
- 数组名使用简短的有意义的名称：`dis[], dp[][], g[], fa[], sum[], mx[]`
- 避免冗长的变量名

### 4. 函数结构

- **主逻辑必须封装在 `solve()` 函数中**
- `main()` 函数只负责：
  - 快速 I/O 设置
  - 处理多组测试数据（while(T--) 循环）
  - 调用 solve()
- 辅助函数（如 DFS、Dijkstra、并查集等）独立定义在 solve() 之前

### 5. 代码格式

- **紧凑风格，不加多余空格**：运算符前后不加空格，如 `for(int i=1;i<=n;i++)` 而不是 `for (int i = 1; i <= n; i++)`
- **大括号跟在行后（K&R 风格）**：`if(x){` 而不是 `if (x) {`，函数定义同理 `void solve(){` 而不是 `void solve() {`
- **关键字后不加空格**：`if(` 而不是 `if (`，`for(` 而不是 `for (`，`while(` 而不是 `while (`
- **逗号后不加空格**：`cin>>u>>v>>w;` 和 `g[u].push_back({v,w});` 而不是 `push_back({v, w})`
- **模板参数间不加空格**：`vector<pair<ll,ll>>` 而不是 `vector<pair<ll, ll>>`
- 使用 `auto` 关键字简化类型声明
- 循环和条件语句可以写在同一行（如果很短）
- 使用 STL 容器：`vector`, `pair`, `queue`, `priority_queue`
- 图论题目使用邻接表：`vector<ll> g[N]` 或 `vector<pair<ll,ll>> g[N]`

### 6. 输入输出

- 使用 `cin` 和 `cout`（配合快速 I/O）
- 不使用 `scanf/printf`
- 输出换行使用 `el` 或 `'\n'`，不使用 `endl`

### 7. 注释风格

- 最少化注释
- 主要注释掉的文件操作代码（freopen）
- 必要时添加简短的中文注释说明关键逻辑

### 8. 常用数据结构和算法实现

#### 并查集（bcj）

```cpp
struct bcj{
    vector<ll> fa;
    bcj(ll len){
        fa.reserve(len+1);
        fa.resize(len+1);
        for(int i=1;i<=len;i++) fa[i]=i;
    }
    ll find(ll x){
        if(fa[x]==x) return x;
        return fa[x]=find(fa[x]);
    }
};
```

#### Dijkstra 算法

```cpp
void dijkstra(){
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
    q.push({0,起点});
    memset(dis,0x3f,sizeof(dis));
    dis[起点]=0;
    while(!q.empty()){
        auto x=q.top();
        q.pop();
        if(x.first>dis[x.second]) continue;
        for(auto i:g[x.second]){
            if(dis[x.second]+i.second<dis[i.first]){
                dis[i.first]=dis[x.second]+i.second;
                q.push({dis[i.first],i.first});
            }
        }
    }
}
```

#### 树形 DP / DFS

```cpp
void dfs(ll x,ll fa){
    for(auto i:g[x]){
        if(i!=fa){
            dfs(i,x);
            // 状态转移
        }
    }
}
```

### 9. 文件命名规范

- 洛谷题目：`Pxxxx.cpp` 或 `Luogu_P_xxxx.cpp`
- Codeforces：`CFxxx.cpp` 或按题目字母命名
- 其他 OJ：按题目编号或名称命名
- 使用中文题目名称（如 `拦截导弹.cpp`）

### 10. 特殊技巧

- 使用 `memset(dp,0x3f,sizeof(dp))` 初始化无穷大
- 使用 `0x3f3f3f3f3f3f3f3f` 表示 long long 的无穷大
- 使用 `(1<<31)-1` 表示 int 的无穷大
- 字符串前加空格使其从 1 开始：`s=' '+s;`
- 使用 `upper_bound` 和 `lower_bound` 进行二分查找

## 禁止事项

- ❌ 不使用 `#include <iostream>` 等多个头文件
- ❌ 不使用 `scanf/printf`
- ❌ 不使用 `endl`（使用 `'\n'` 或 `el`）
- ❌ 不使用冗长的变量名和函数名
- ❌ 不在 main() 函数中写主逻辑
- ❌ 不添加过多的注释
- ❌ 不使用 C++17 的结构化绑定等高级特性（保持简洁）

## 示例代码

```cpp
#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,m;
vector<ll> g[N];
bool vis[N];

void dfs(ll x){
    vis[x]=1;
    for(auto i:g[x]){
        if(!vis[i]) dfs(i);
    }
}

void solve(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        ll u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    cout<<"Done";
}

int main(){
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

## 使用场景

当用户请求以下任务时，自动应用此代码风格：

- 编写算法题解
- 实现数据结构
- 解决竞赛题目
- 编写 C++ 程序
- 任何涉及 C++ 代码生成的任务

**始终确保生成的代码 100% 符合上述风格规范。**
