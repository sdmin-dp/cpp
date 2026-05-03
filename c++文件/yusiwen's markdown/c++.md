
# 集合

确定性：给定一个集合，任给一个元素，该元素或者属于或者不属于该集合，二者必居其一，不允许有模棱两可的情况出现。

互异性：一个集合中，任何两个元素都认为是不相同的，即每个元素只能出现一次。有时需要对同一元素出现多次的情形进行刻画，可以使用多重集，其中的元素   		允许出现多次。

无序性：一个集合中，每个元素的地位都是相同的，元素之间是无序的。集合上可以定义序关系，定义了序关系后，元素之间就可以按照序关系排序。但就集合本		身的特性而言，元素之间没有必然的序。
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

| 问题类型 | 洪水填充 |    是否可达    | 最小步数 |     路径数量     | 最小路径成本  | 最小成本路径成本 |
| :--: | :--: | :--------: | :--: | :----------: | :-----: | :------: |
|  回溯  |  ✅   |     ❌      |  ✅   |      ✅       |    ✅    |    ✅     |
|  剪枝  |  ❌   |     ❌      |  ✅   |      ❌       |    ✅    |    ✅     |
| 边界条件 | 自然终止 |    达到终点    | 到达终点 |     到达终点     |  到达终点   |   到达终点   |
| 边界处理 |  无   | `exit(0);` | 打擂台  | 复制栈数据 or 打擂台 | 累加和的最小值 |  复制栈数据   |

# 动态规划（`dp`）

>[!IMPORTANT]
>动态规划五部曲
>1. dp 数组以及下标的含义。
>
>
>2. 递推公式。
>
>3. dp 数组如何初始化。
>
>
>4. 遍历顺序。
>
>5. 打印 dp 数组。
>[动态规划五部曲讲解视频](https://www.bilibili.com/video/BV13Q4y197Wg)

## 背包DP
### 01背包

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

#### 一维

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

### 完全背包

> [!IMPORTANT]
>
> 二维状态转移公式：`dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);`
>
> 一维状态转移公式：`dp[j] = max(dp[j], dp[j - weights[i]] + values[i])`



#### 二维DP解法

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

#### 一维DP解法

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

#### 代码解析

**二维解法特点：**

1. 使用二维数组`dp[n+1][W+1]`存储中间结果
2. 外层循环遍历物品，内层循环遍历容量
3. 状态转移时比较不选当前物品和选当前物品的情况
4. 空间复杂度O(N*W)

**一维解法特点：**

1. 使用一维数组`dp[W+1]`优化空间
2. **关键点**：内层循环必须**正向遍历**（从`w[i]`到`W`）
3. 状态转移直接覆盖原数组
4. 空间复杂度O(W)

> [!CAUTION]
>
> **为什么完全背包要正向遍历？**

在完全背包中，同一物品可以选多次。正向遍历时，`dp[j - w[i]]`可能已经包含当前物品的选取，因此可以实现多次选取的效果。例如：

当计算`dp[2]`时：
- 可能已经选取了1个物品（`dp[1]`的值）
- 然后`dp[2] = max(dp[2], dp[1] + v[i])`相当于再选一次

而逆序遍历（如01背包）会保证每个物品只被考虑一次。

**复杂度分析**

两种解法的时间复杂度都是O(N*W)，其中：
- N是物品数量
- W是背包容量

空间复杂度：
- 二维：O(N*W)
- 一维：O(W)

### 多重背包

多重背包问题是背包问题的一个变种，其中每种物品有一定的数量限制（不是无限也不是只有一个）。下面我将介绍多重背包问题的C++实现。

**问题描述**

给定：
- 一个容量为W的背包
- N种物品，每种物品有：
  - 重量 weight[i]
  - 价值value[i]
  - 数量限制amount[i]

目标：在不超过背包容量的前提下，选择物品使得总价值最大。

#### 基本解法：转化为01背包

```cpp
#include <bits/stdc++.h>
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

#### 优化解法：二进制拆分

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

#### 单调队列优化

更高效的解法是使用单调队列优化，可以将时间复杂度进一步降低：

```cpp
#include <bits/stdc++.h>
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

## 区间DP
上述都是线性DP
### 基本框架
1. 要先遍历长度（长度为1**优先处理**）
2. 遍历起点（注意不要**越界**）
3. 进行转移
### 推荐题目
1. 洛谷 石子合并
> [!IMPORTANT]
> Q:怎么区分他和线性DP?
> A:线性不会写，且是区间问题（从一个位置到另一个位置），
## 分组背包

### 原理说明

分组背包核心思想：**每组物品最多选一个**  
相比普通01背包，增加一层组内物品的遍历  
状态转移：`dp[j] = max(不选当前组物品, 选当前组某个物品)`

```cpp
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e2+5;
ll n,m,k;
ll dp[20005];
vector<pair<ll,ll>> group[N]; // group[i]存储第i组物品的{w,v}

void solve()
{
    cin>>m>>n>>k; // m容量 n物品总数 k组数
    for(int i=1;i<=n;i++){
        ll w,v,g; 
        cin>>w>>v>>g; // 输入重量、价值、所属组号
        group[g].push_back({w,v});
    }
    
    memset(dp,0,sizeof(dp));
    for(int g=1;g<=k;g++) // 遍历所有组
    {
        for(int j=m;j>=0;j--) // 逆序枚举容量
        {
            for(auto &[w,v]:group[g]) // 遍历组内物品
            {
                if(j>=w) dp[j]=max(dp[j], dp[j-w]+v);
            }
        }
    }
    cout<<dp[m]<<el;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}
```
## 注意事项

1. 1.容量遍历必须是逆序的（从大到小），这样才能保证每组物品只被选择一次
2. 2.如果题目要求必须选每组中的物品，需要初始化dp数组为负无穷，并设置dp[0]=0
3. 3.分组背包可以转化为01背包问题，但直接使用分组背包模板更直观高效

## 背包变形（常考！）
>[!IMPORTANT]
>problem：
>商店里有 n 个武器，第 i 个武器的强度为 pi​，花费为 ci​。
>小杨想要购买一些武器，满足这些武器的总强度不小于 P，总花费不超过 Q，小杨想知道是否存在满足条件的购买方案，如果有，最少花费又是多少。

### 分析
**Q**:dp 数组以及下标的含义是啥？
**A**:设 $dp_i,_j$​ 为前 i 个武器中购买，总花费不超过$j$，以**最优策略**购买武器后，武器的**强度和**。

**Q**:递推公式是啥？
**A**:
- 若 $c_i​>j$，即该武器的花费大于了总花费（下文称**预算**），则 $dp_i,_j$​ 就直接从$dp_i-1,_j$​ 进行转移。
- 若 $c_i​≤j$，即该武器的花费小于预算，就有买和不买两种情况。
- ```cpp
  dp[i][j]=max(dp[i-1][j-c[i]]+p[i]/*买的情况*/，dp[i-1][j]/*不买的情况*/);
  ```
 **Q**:dp 数组如何初始化?
 **A**:由于 dp 要求**最大的强度和**，所以直接将 dp 数组初始化为 0 即可。

**Q**:遍历顺序?
**A**:由于求 dpi,j​ 牵连到了前 i−1 个武器的最大强度，但 $dp_i,_j$​ 不会牵连到 $dp_i,_k​(k<j)$，所以 $i$ 需要按从小到大的顺序进行遍历，$j$ 哪个顺序遍历都行。

**Q**:cout?
**A**:按照 dp 数组的含义，找到最小的一个$q(1≤q≤Q)$，使得 $dp_n,_q​≥P$ 即可。若没有任何一个 $dp_n,q​≥P$，则直接按题意输出 `-1` 即可。

### 代码
```cpp
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int T, n, P, Q, p[109], c[109], dp[109][50009];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> n >> P >> Q;
		for (int i = 1; i <= n; i++)
			cin >> p[i] >> c[i];
		// 初始状态
		memset(dp, 0, sizeof(dp));
		// DP
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= Q; j++) {
				// 不买
				dp[i][j] = dp[i - 1][j];
				// 若可以买，就把买和不买取最大值
				if (c[i] <= j)
					dp[i][j] = max(dp[i][j], dp[i - 1][j - c[i]] + p[i]);
			}
		}
		// 打印
		bool flag = true;
		for (int q = 1; q <= Q; q++) {
			if (dp[n][q] >= P) {
				cout << q << endl;
				flag = false;
				break;
			}
		}
		if (flag)
			cout << -1 << endl;
	}
	return 0;
}

```
# 质数
## 质数筛
给定l,r，求出l~r之间所有的质数，这样的问题叫做质数筛
### 埃氏筛
#### 基本思想
 任意整数x的倍数，2x,3x……都不是质数
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
### 代码特点

1. **快读优化**​：`ios::sync_with_stdio(0)`加速输入输出
2. ​**紧凑存储**​：用`vector<pair<ll,ll>>`存每组物品
3. ​**三重循环**​：
    
    - 外层：遍历物品组（决策选哪组）
    - 中层：逆序背包容量（保证每组只选一次）
    - 内层：枚举组内物品（决策选哪个物品）
    
4. ​**滚动数组**​：一维`dp`数组空间优化
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
## 定义
a,b,m为正整数,则当(a-b)%m==0(可理解为a%m==b%m)，则称a和b对模m同余，记作：
$$
a /timesb
$$
# 排列组合
## 排列数
从n个元素中**选择每个m个元素排队**,记作$A(n,m)$
$A(n,m)=n*(n-1)*(n-2)*...*(n-m+1)$;
例：$A(5,3)=5*4*3$;
## 组合数
从n个元素中**选择每个m个元素**,记作$C(n,m)$
$C(n,m)=[n*(n-1)*(n-2)*...*(n-m+1)]/m!$;
就是：$C(n,m)=A(n,m)/A(m,m)$;
# 贪心
## 区间贪心
### 区间不相交问题
用于解决时间冲突（如上课，考试，看电视）问题；
右边界排序，last保存上节课右边界，如果接上，维护last，cnt++
```cpp
bool cmp(node a,node b){
    if(a.e!=b.e) return a.e<b.e;
    else return a.s<b.s;
} 
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i].s>>a[i].e;
    sort(a+1,a+n+1,cmp);
    int num=1,last=a[1].e;
    for(int i=2;i<=n;i++){
        if(a[i].s>=last){
            last=a[i].e;
            num++;
        }
    }
    cout<<num;
}
```
### 区间选点问题
在n个区间中选点，要求尽量少（区间有重叠）；
右边界排序，点选r
```cpp

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const int N=1e5+5;
ll n,a,b,c,l=LONG_LONG_MIN;
bool cmp(pair<int,int> x,pair<int,int> y){
	return x.second<y.second;
}
void solve(){
	cin>>n;
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<n;i++){
        if(l<v[i].first){
            c++;
            l=v[i].second;
        }
    }
    cout<<c;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	//freopen("xxx.in","r",stdin);
	//freopen("xxx.out","w",stdout);
	int T=1;
	while(T--){
		solve();
	}
	return 0;
}
```

### 区间分组问题
将n个区间分成m组，要求组内区间互不重叠，求m；
**按左端点排序！！！**
在建一个priority_queue,使用greater(小根堆)
```cpp
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
pair<ll,ll> a[N];
ll n;
priority_queue<ll,vector<ll>,greater<ll>> q;
bool cmp(pair<ll,ll> x,pair<ll,ll> y){
	return x.first<y.first;
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].first>>a[i].second;
	sort(a+1,a+n+1,cmp);
	q.push(a[1].second);
	for(int i=2;i<=n;i++){
		if(q.top()<a[i].first){
			q.pop();
			q.push(a[i].second);
		}
		else{
			q.push(a[i].second);
		}
	}
	cout<<q.size();
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
//	freopen("xxx.in","r",stdin);
//	freopen("xxx.out","w",stdout);
	ll T=1;
//	cin>>T;
	while(T--){
		solve();
	}
}
```
### 区间覆盖问题
用于解决删除区间覆盖等问题
**排序左升序右降序！！！**
```cpp
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e3+5;
pair<ll,ll> a[N];
ll n;
bool cmp(pair<ll,ll> x,pair<ll,ll> y){
	if(x.first!=y.first) return x.first<y.first;
	else return x.second>y.second;
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].first>>a[i].second;
	sort(a+1,a+n+1,cmp);
	ll l=a[1].first,r=a[1].second;
	ll ans=0;
	for(int i=2;i<=n;i++){
		if(l<=a[i].first&&a[i].second<=r){
			ans++;
		}
		else{
			l=a[i].first;
			r=a[i].second;
		}
	}
	cout<<n-ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
//	freopen("xxx.in","r",stdin);
//	freopen("xxx.out","w",stdout);
	ll T=1;
//	cin>>T;
	while(T--){
		solve();
	}
}
```
## 贪心证明
### 数学归纳法
1.（归纳基础）$n=n_0$(选一个基础值)，证明$P(n_0)$为真；
2.（归纳推理）假设$P(k)$为真时，推出$p(k+1)$也为真
3.（结论）所有自然数$n$都使$P(n)$为真

### 反证法
结论$P$成立，证明$\neg P$不成立即可

# 循环队列
## push
`tail=(tail+1)%n;`
## pop
`head=(head+1)%n;`
## empty
`head == tail;`
## 满
`(tail+1)%n == head;`
## size
`(tail-head+n)%n;`
## front
`a[(head+1)%n]`

# 过河问题
## problem
$n$个人坐船过河，过河时间分别为$a_1,a_2,a_3...$,船只能装两个人，请问最快需要多久？

## 解法
### NO.1
让一个最快的人送每个人过河

### NO.2
按速度排序，每两个人过河，在让已经过河的最快的那个送船回去，最后再过去

### 最终解
NO.1和NO.2取min

## CODE
```cpp
#include<bits/stdc++.h>

using namespace std;

#define ll long long

const ll N=1e5+5;

ll n,a[N],ans;

void solve(){

	cin>>n;

	for(int i=1;i<=n;i++){

		cin>>a[i];

	}

	sort(a+1,a+n+1);

	while(n>3){

		ans+=min(a[n]+a[1]+a[n-1]+a[1],a[2]+a[1]+a[n]+a[2]);

		n-=2;

	}

	if(n==3) ans+=a[1]+a[2]+a[3];

	else if(n==2) ans+=a[2];

	else ans+=a[1];

	cout<<ans;

}

int main(){

	ios::sync_with_stdio(0);
	
	cin.tie(0);cout.tie(0);
	
	// freopen("xxx.in","r",stdin);
	
	// freopen("xxx.out","w",stdout);
	
	int T=1;
	
	//cin>>T;
	
	while(T--){
	
		solve();
	
	}
	
	return 0;

}
```

## 推导过程
a b c d e f
1:
a f   f
a     a
a e  e
a     a
2.
a f   f
a     a
b e e
b    b


# Lucas' Theorem (卢卡斯定理)

## 基本概念

Lucas' Theorem是组合数学中的一个重要定理，用于计算大数组合数模一个质数的情况。该定理由法国数学家Édouard Lucas在1878年提出。

## 定理表述

对于质数p和非负整数m和n，将m和n表示为p进制数：

```
m = m₀ + m₁·p + m₂·p² + ... + m_k·p^k
n = n₀ + n₁·p + n₂·p² + ... + n_k·p^k
```

其中$0 ≤ m_i, n_i < p$，则：

```
C(m, n) ≡ ∏(C(m_i, n_i)) (mod p)
```

其中$C(m_i, n_i) = 0$（当$n_i > m_i$时）。

## 基本公式

Lucas' Theorem的核心公式为：

```
C(m, n) ≡ C(m₀, n₀) × C(m₁, n₁) × ... × C(m_k, n_k) (mod p)
```

$$
C(n,m) \mod p = C(\lfloor n \rfloor,\lfloor m \rfloor) \times C(n \mod p,m \mod p) \mod p
$$

其中：
- C(m, n)是组合数，表示从m个元素中选取n个元素的组合数
- p是一个质数
- m_i和n_i分别是m和n在p进制下的第i位数字

## 主要应用

### 1. 大数组合数模质数计算

当m和n非常大时，直接计算C(m, n)是不可能的。Lucas' Theorem可以将大组合数问题分解为多个小组合数的乘积。

### 2. 组合数性质研究

通过Lucas' Theorem可以研究组合数在模p下的性质和分布规律。

### 3. 算法竞赛中的应用

在算法竞赛中，经常需要计算大组合数模某个质数的结果，Lucas' Theorem提供了高效的计算方法。

## C++实现

### 基础实现

```cpp
#include <iostream>
using namespace std;

// 计算组合数C(n, k)模p的结果（当n, k < p时）
int nCr(int n, int k, int p) {
    if (k > n) return 0;
    if (k == 0 || k == n) return 1;
    
    long long res = 1;
    for (int i = 1; i <= k; i++) {
        res = (res * (n - k + i)) % p;
        res = (res * modInverse(i, p)) % p;
    }
    return res;
}

// 计算模逆元（费马小定理）
int modInverse(int a, int p) {
    return power(a, p - 2, p);
}

// 快速幂
int power(int a, int b, int p) {
    int res = 1;
    a = a % p;
    while (b > 0) {
        if (b & 1) res = (res * a) % p;
        a = (a * a) % p;
        b = b >> 1;
    }
    return res;
}

// Lucas' Theorem主函数
int lucas(int m, int n, int p) {
    if (n == 0) return 1;
    
    return (nCr(m % p, n % p, p) * lucas(m / p, n / p, p)) % p;
}

int main() {
    int m, n, p;
    cout << "输入m, n, p: ";
    cin >> m >> n >> p;
    
    cout << "C(" << m << ", " << n << ") mod " << p << " = " << lucas(m, n, p) << endl;
    
    return 0;
}
```

### 优化版本（预处理阶乘和逆元）

```cpp
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1000005;

class LucasTheorem {
private:
    int p;
    vector<long long> fact;  // 阶乘数组
    vector<long long> inv;   // 逆元数组
    
    // 快速幂
    long long power(long long a, long long b, long long mod) {
        long long res = 1;
        a = a % mod;
        while (b > 0) {
            if (b & 1) res = (res * a) % mod;
            a = (a * a) % mod;
            b = b >> 1;
        }
        return res;
    }
    
    // 预处理阶乘和逆元
    void precompute() {
        fact.resize(p);
        inv.resize(p);
        
        fact[0] = 1;
        for (int i = 1; i < p; i++) {
            fact[i] = (fact[i-1] * i) % p;
        }
        
        inv[p-1] = power(fact[p-1], p-2, p);
        for (int i = p-2; i >= 0; i--) {
            inv[i] = (inv[i+1] * (i+1)) % p;
        }
    }
    
public:
    LucasTheorem(int prime) {
        p = prime;
        precompute();
    }
    
    // 计算C(n, k) mod p（当n, k < p时）
    long long nCr(int n, int k) {
        if (k > n) return 0;
        if (k == 0 || k == n) return 1;
        
        return (fact[n] * inv[k] % p) * inv[n-k] % p;
    }
    
    // Lucas' Theorem主函数
    long long lucas(int m, int n) {
        if (n == 0) return 1;
        
        return (nCr(m % p, n % p) * lucas(m / p, n / p)) % p;
    }
};

int main() {
    int m, n, p;
    cout << "输入m, n, p: ";
    cin >> m >> n >> p;
    
    LucasTheorem lucas(p);
    cout << "C(" << m << ", " << n << ") mod " << p << " = " << lucas.lucas(m, n) << endl;
    
    return 0;
}
```

### 多组测试数据优化版本

```cpp
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1000005;

class LucasTheoremOptimized {
private:
    int p;
    vector<long long> fact;
    vector<long long> inv;
    
    long long power(long long a, long long b, long long mod) {
        long long res = 1;
        a = a % mod;
        while (b > 0) {
            if (b & 1) res = (res * a) % mod;
            a = (a * a) % mod;
            b = b >> 1;
        }
        return res;
    }
    
    void precompute() {
        fact.resize(p);
        inv.resize(p);
        
        fact[0] = 1;
        for (int i = 1; i < p; i++) {
            fact[i] = (fact[i-1] * i) % p;
        }
        
        inv[p-1] = power(fact[p-1], p-2, p);
        for (int i = p-2; i >= 0; i--) {
            inv[i] = (inv[i+1] * (i+1)) % p;
        }
    }
    
public:
    LucasTheoremOptimized(int prime) {
        p = prime;
        precompute();
    }
    
    long long nCr(int n, int k) {
        if (k > n) return 0;
        if (k == 0 || k == n) return 1;
        
        return (fact[n] * inv[k] % p) * inv[n-k] % p;
    }
    
    long long lucas(int m, int n) {
        if (n == 0) return 1;
        
        return (nCr(m % p, n % p) * lucas(m / p, n / p)) % p;
    }
    
    // 处理多组测试数据
    void solveMultipleCases() {
        int T;
        cout << "输入测试数据组数: ";
        cin >> T;
        
        while (T--) {
            int m, n;
            cout << "输入m, n: ";
            cin >> m >> n;
            
            cout << "C(" << m << ", " << n << ") mod " << p << " = " << lucas(m, n) << endl;
        }
    }
};

int main() {
    int p;
    cout << "输入质数p: ";
    cin >> p;
    
    LucasTheoremOptimized lucas(p);
    lucas.solveMultipleCases();
    
    return 0;
}
```

## 算法分析

### 时间复杂度

1. **预处理阶段**：O(p)
   - 预处理阶乘数组：O(p)
   - 预处理逆元数组：O(p)

2. **查询阶段**：O(log_p n)
   - 每次递归调用将n除以p，递归深度为log_p n
   - 每层递归需要O(1)时间计算C(m_i, n_i)

### 空间复杂度

1. **存储空间**：O(p)
   - 需要存储阶乘数组和逆元数组

## 应用示例

### 示例1：计算C(100, 20) mod 7

```cpp
#include <iostream>
using namespace std;

int main() {
    int m = 100, n = 20, p = 7;
    
    // Lucas' Theorem
    // 100的7进制表示：202 (2*49 + 0*7 + 2*1)
    // 20的7进制表示：26 (2*7 + 6*1)
    // C(100, 20) mod 7 = C(2, 2) * C(0, 6) * C(2, 0) mod 7
    // C(2, 2) = 1, C(0, 6) = 0, C(2, 0) = 1
    // 结果 = 1 * 0 * 1 = 0
    
    cout << "C(100, 20) mod 7 = 0" << endl;
    
    return 0;
}
```

### 示例2：计算C(12345, 6789) mod 13

```cpp
#include <iostream>
using namespace std;

long long nCr(int n, int k, int p) {
    if (k > n) return 0;
    if (k == 0 || k == n) return 1;
    
    long long res = 1;
    for (int i = 1; i <= k; i++) {
        res = (res * (n - k + i)) % p;
        res = (res * power(i, p-2, p)) % p;
    }
    return res;
}

long long power(long long a, long long b, long long p) {
    long long res = 1;
    a = a % p;
    while (b > 0) {
        if (b & 1) res = (res * a) % p;
        a = (a * a) % p;
        b = b >> 1;
    }
    return res;
}

long long lucas(int m, int n, int p) {
    if (n == 0) return 1;
    return (nCr(m % p, n % p, p) * lucas(m / p, n / p, p)) % p;
}

int main() {
    int m = 12345, n = 6789, p = 13;
    cout << "C(" << m << ", " << n << ") mod " << p << " = " << lucas(m, n, p) << endl;
    
    return 0;
}
```

## 扩展应用

### 1. 多重组合数计算

Lucas' Theorem可以扩展到多重组合数的计算：

```cpp
// 计算多重组合数C(n, k1, k2, ..., km) mod p
long long multinomial(int n, vector<int>& k, int p) {
    if (n != 0) {
        long long res = 1;
        for (int i = 0; i < k.size(); i++) {
            res = (res * nCr(n % p, k[i] % p, p)) % p;
            n = n / p;
            k[i] = k[i] / p;
        }
        return (res * multinomial(n, k, p)) % p;
    }
    return 1;
}
```

### 2. 组合数求和

使用Lucas' Theorem可以高效计算组合数求和：

```cpp
// 计算sum_{k=0}^{n} C(m, k) mod p
long long sumCombinations(int m, int n, int p) {
    long long sum = 0;
    for (int k = 0; k <= n; k++) {
        sum = (sum + lucas(m, k, p)) % p;
    }
    return sum;
}
```

## 注意事项

1. **质数限制**：Lucas' Theorem要求模数p必须是质数
2. **递归深度**：对于非常大的数，递归可能导致栈溢出，可以使用迭代实现
3. **预处理优化**：对于多组测试数据，预处理阶乘和逆元可以显著提高效率
4. **边界条件**：注意处理n > m的情况，此时组合数为0

## 与其他算法的比较

| 算法 | 时间复杂度 | 空间复杂度 | 适用场景 |
|------|------------|------------|----------|
| 直接计算 | O(n) | O(1) | n较小 |
| Lucas' Theorem | O(log_p n) | O(p) | n很大，p较小 |
| 动态规划 | O(n²) | O(n²) | n较小 |
| 生成函数 | O(n log n) | O(n) | 特定模式 |

## 练习题目

1. **基础题**：计算C(2n, n) mod p
2. **进阶题**：计算sum_{k=0}^{n} C(m, k) mod p
3. **挑战题**：计算C(n, k) mod p^r（扩展Lucas定理）
4. **应用题**：计算多项式系数模质数

通过Lucas' Theorem，我们可以高效地解决大数组合数模质数的问题，这在算法竞赛和数学研究中都有重要应用。掌握这个定理对于解决组合数学相关问题非常有帮助。

---

# Tarjan算法（强连通分量 & 双连通分量）

## 前言：为什么我们需要Tarjan算法？

想象一下，你在一个城市里开车，城市的道路有些是单行道（有向图），有些是双向道（无向图）。

**问题来了**：
- 在单行道系统中，从A地出发，能否不违反交通规则地回到A地？这就是**强连通分量**的问题。
- 在双向道路系统中，哪些路口是"必经之路"？如果这条路堵了，整个城市会不会被分割成两半？这就是**双连通分量**的问题。

Tarjan大神（Robert Tarjan）在1972年提出了一个超级优雅的算法，用一次DFS就能解决这些问题！

---

## Part 1: 强连通分量（SCC）

### 什么是强连通分量？

**大白话定义**：在有向图中，如果一组点两两之间都能互相到达，这组点就组成一个强连通分量。

**生活中的例子**：
- 想象一个微信群，如果群里每个人都能私聊联系到其他人，那这个群就是一个"强连通分量"
- 如果有人被踢出群了，其他人的联系不受影响，但这个人再也联系不到群里的人了

### Tarjan算法的核心思想

Tarjan算法用两个关键数组来实现：

| 数组 | 含义 | 生活比喻 |
|------|------|----------|
| `dfn[u]` | 节点u被访问的顺序号（时间戳） | 你是第几个进场的客人 |
| `low[u]` | 从u出发能追溯到的最早祖先的时间戳 | 你能联系到的"最早进场"的人 |

**核心规则**：
1. 第一次访问节点u时，`dfn[u] = low[u] = 当前时间戳`
2. 遍历u的所有邻居v：
   - 如果v没被访问过：递归访问v，然后 `low[u] = min(low[u], low[v])`
   - 如果v在栈中（说明v在当前搜索路径上）：`low[u] = min(low[u], dfn[v])`
3. 如果 `dfn[u] == low[u]`，说明u是强连通分量的"根"，弹出栈中u及以上的所有节点

### 详细图解过程

```
假设有如下有向图：

    1 → 2 → 3
    ↑   ↓
    4 ← 5

边：1→2, 2→3, 2→5, 5→4, 4→1

执行过程（用栈追踪路径）：

步骤1: 访问节点1
  dfn[1]=1, low[1]=1
  栈：[1]

步骤2: 从1出发访问节点2
  dfn[2]=2, low[2]=2
  栈：[1, 2]

步骤3: 从2出发访问节点3
  dfn[3]=3, low[3]=3
  栈：[1, 2, 3]
  3没有出边，dfn[3]==low[3]，弹出3
  栈：[1, 2]
  强连通分量：{3}

步骤4: 回到2，继续访问节点5
  dfn[5]=4, low[5]=4
  栈：[1, 2, 5]

步骤5: 从5出发访问节点4
  dfn[4]=5, low[4]=5
  栈：[1, 2, 5, 4]

步骤6: 从4出发发现节点1已在栈中！
  low[4] = min(low[4], dfn[1]) = min(5, 1) = 1
  回溯：low[5] = min(low[5], low[4]) = 1
  回溯：low[2] = min(low[2], low[5]) = 1
  回溯：low[1] = min(low[1], low[2]) = 1

步骤7: 回到节点1，dfn[1]==low[1]==1
  弹出栈中所有元素：1, 2, 5, 4
  强连通分量：{1, 2, 4, 5}

最终结果：两个强连通分量 {3} 和 {1, 2, 4, 5}
```

### C++代码实现（超详细注释版）

```cpp
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

const int MAXN = 10005;  // 最大节点数

// ==================== 全局变量 ====================
vector<int> adj[MAXN];   // 邻接表存图
int dfn[MAXN];           // 时间戳：节点被访问的顺序
int low[MAXN];           // 能追溯到的最早祖先的时间戳
bool inStack[MAXN];      // 是否在栈中
stack<int> stk;          // 存储当前搜索路径的栈
int timer;               // 时间计数器
int sccCount;            // 强连通分量计数
vector<int> scc[MAXN];   // 存储每个强连通分量的节点

// ==================== Tarjan核心函数 ====================
void tarjan(int u) {
    // ===== 第一步：初始化当前节点 =====
    dfn[u] = low[u] = ++timer;  // 第一次访问，时间戳和low都是当前时间
    stk.push(u);                // 入栈，表示在当前搜索路径上
    inStack[u] = true;          // 标记在栈中

    // ===== 第二步：遍历所有邻居 =====
    for (int v : adj[u]) {
        // 情况1：邻居v没有被访问过
        // 说明v是u的后代，需要递归访问
        if (dfn[v] == 0) {
            tarjan(v);  // 递归访问v

            // 重要！递归返回后，用v的low值更新u的low值
            // 这就像：你能联系到的最早祖先 = 你儿子能联系到的最早祖先
            low[u] = min(low[u], low[v]);
        }
        // 情况2：邻居v已经在栈中
        // 说明v是u的祖先（在当前搜索路径上），形成了一个环！
        else if (inStack[v]) {
            // 用v的时间戳更新u的low值
            // 注意这里用dfn[v]而不是low[v]
            // 因为v在栈中，直接用v的位置标记这个环
            low[u] = min(low[u], dfn[v]);
        }
        // 情况3：v被访问过但不在栈中
        // 说明v已经在其他强连通分量中被处理完了，忽略
    }

    // ===== 第三步：检查是否是强连通分量的根 =====
    // 如果dfn[u] == low[u]，说明u是"根节点"
    // 从u开始的所有节点形成一个强连通分量
    if (dfn[u] == low[u]) {
        sccCount++;  // 新的强连通分量

        // 弹出栈中u及以上的所有节点
        // 这些节点就组成了一个强连通分量
        int v;
        do {
            v = stk.top();        // 取栈顶
            stk.pop();            // 弹出
            inStack[v] = false;   // 标记不在栈中
            scc[sccCount].push_back(v);  // 加入当前强连通分量
        } while (v != u);         // 直到弹到u为止
    }
}

// ==================== 主函数 ====================
int main() {
    int n, m;  // n个节点，m条边
    cout << "请输入节点数n和边数m：";
    cin >> n >> m;

    cout << "请输入" << m << "条有向边（格式：起点 终点）：" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);  // 有向边 u -> v
    }

    // ===== 初始化 =====
    timer = 0;
    sccCount = 0;
    for (int i = 1; i <= n; i++) {
        dfn[i] = 0;
        low[i] = 0;
        inStack[i] = false;
    }

    // ===== 对每个未访问的节点执行Tarjan =====
    // 因为图可能不连通，需要遍历所有节点
    for (int i = 1; i <= n; i++) {
        if (dfn[i] == 0) {  // 如果没被访问过
            tarjan(i);
        }
    }

    // ===== 输出结果 =====
    cout << "\n========== 结果 ==========" << endl;
    cout << "共有 " << sccCount << " 个强连通分量：" << endl;

    for (int i = 1; i <= sccCount; i++) {
        cout << "SCC #" << i << ": ";
        for (int v : scc[i]) {
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
【运行示例】

输入：
5 5
1 2
2 3
2 5
5 4
4 1

图的结构：
    1 → 2 → 3
    ↑   ↓
    4 ← 5

输出：
共有 2 个强连通分量：
SCC #1: 3
SCC #2: 4 5 2 1  （顺序可能不同，但内容一样）

解释：
- 节点3自己形成一个强连通分量
- 节点1,2,4,5形成一个强连通分量（它们可以互相到达）
*/
```

### 为什么这个算法是对的？

**直觉理解**：
想象你在走迷宫（DFS），你用粉笔在每个路口写下"到达顺序号"。

1. 当你发现一个已经写有号码的路口（在栈中），说明你走了一圈回来了！
2. `low`值就像是"我能回到的最远入口"，如果所有人的`low`都指向同一个人，那他们就是一个团队
3. 当`dfn == low`时，这个人就是"团队领袖"，之后的人都是团队成员

**数学证明要点**：
- `low[u]`记录的是从u出发，通过其后代节点，能够到达的仍在栈中的节点的最小dfn值
- 当`dfn[u] == low[u]`时，u无法到达栈中比它更早的节点，所以u及其后代形成一个独立的强连通分量

---

## Part 2: 双连通分量（BCC）

### 什么是双连通分量？

双连通分量分为两种：

| 类型 | 定义 | 生活例子 |
|------|------|----------|
| **点双连通分量** | 删除任意一个点，图仍然连通 | 没有关键人物的小团体 |
| **边双连通分量** | 删除任意一条边，图仍然连通 | 没有必经之路的城市 |

**大白话理解**：
- **点双连通**：一个团队里，没有哪个人是不可或缺的。任何一个人离开，其他人还能互相联系。
- **边双连通**：一个城市里，没有哪条路是唯一的通道。任何一条路封了，还有其他路可以走。

### 割点与桥

在学习双连通分量之前，需要先理解两个关键概念：

**割点（Articulation Point）**：
- 删除这个点后，图的连通分量个数会增加
- 生活例子：公司里唯一的技术骨干，他走了公司就运转不下去了

**桥（Bridge）**：
- 删除这条边后，图的连通分量个数会增加
- 生活例子：两座城市之间唯一的桥，断了就过不去了

### 寻找割点的Tarjan算法

```cpp
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 10005;

// ==================== 全局变量 ====================
vector<int> adj[MAXN];   // 邻接表
int dfn[MAXN];           // 时间戳
int low[MAXN];           // 能追溯到的最早时间戳
bool isCut[MAXN];        // 是否是割点
int timer;
int root;                // 当前DFS的根节点

// ==================== Tarjan找割点 ====================
void findCutVertices(int u, int parent) {
    // 初始化时间戳
    dfn[u] = low[u] = ++timer;
    int childCount = 0;  // 统计u的子树数量

    for (int v : adj[u]) {
        if (v == parent) continue;  // 跳过父节点

        if (dfn[v] == 0) {
            // v未被访问，是u的孩子
            childCount++;
            findCutVertices(v, u);

            // 回溯时更新low值
            low[u] = min(low[u], low[v]);

            // ===== 判断割点的核心逻辑 =====
            // 如果u不是根节点，且v无法绕过u到达u的祖先
            // 那么u就是割点！
            if (u != root && low[v] >= dfn[u]) {
                isCut[u] = true;
            }
        }
        else {
            // v已被访问，说明是回边（指向祖先的边）
            // 用v的时间戳更新low值
            low[u] = min(low[u], dfn[v]);
        }
    }

    // 特殊情况：根节点
    // 根节点是割点的条件：有两个或以上的子树
    // 因为如果只有一个子树，删除根节点不会影响连通性
    if (u == root && childCount >= 2) {
        isCut[u] = true;
    }
}

// ==================== 主函数 ====================
int main() {
    int n, m;
    cout << "请输入节点数n和边数m：";
    cin >> n >> m;

    cout << "请输入" << m << "条无向边（格式：点1 点2）：" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);  // 无向图，双向存
    }

    // 初始化
    timer = 0;
    for (int i = 1; i <= n; i++) {
        dfn[i] = 0;
        low[i] = 0;
        isCut[i] = false;
    }

    // 对每个连通分量执行DFS
    for (int i = 1; i <= n; i++) {
        if (dfn[i] == 0) {
            root = i;  // 记录根节点
            findCutVertices(i, -1);
        }
    }

    // 输出割点
    cout << "\n========== 割点 ==========" << endl;
    bool found = false;
    for (int i = 1; i <= n; i++) {
        if (isCut[i]) {
            cout << "割点：" << i << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "没有割点" << endl;
    }

    return 0;
}

/*
【运行示例】

输入：
5 5
1 2
2 3
3 4
4 5
2 4

图的结构：
1 - 2 - 3
    |   |
    4 - 5

输出：
割点：2
割点：4

解释：
- 删除节点2后，节点1与其它节点断开
- 删除节点4后，节点5与其它节点断开
*/
```

### 寻找桥的Tarjan算法

```cpp
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 10005;

// ==================== 全局变量 ====================
vector<pair<int, int>> adj[MAXN];  // (邻居, 边编号)
int dfn[MAXN];
int low[MAXN];
bool isBridge[MAXN * 2];  // 标记边是否是桥
int timer;
int edgeCount;

// ==================== Tarjan找桥 ====================
void findBridges(int u, int parentEdge) {
    dfn[u] = low[u] = ++timer;

    for (auto& p : adj[u]) {
        int v = p.first;   // 邻居
        int edgeId = p.second;  // 边的编号

        // 跳过从父亲来的那条边（用边编号判断）
        if (edgeId == parentEdge) continue;

        if (dfn[v] == 0) {
            // v未被访问
            findBridges(v, edgeId);

            low[u] = min(low[u], low[v]);

            // ===== 判断桥的核心逻辑 =====
            // 如果v无法绕过当前边到达u的祖先
            // 那么这条边(u,v)就是桥！
            // 注意：这里用 > 而不是 >=
            // 因为如果 low[v] == dfn[u]，说明v可以通过u形成环，边不是桥
            if (low[v] > dfn[u]) {
                isBridge[edgeId] = true;
            }
        }
        else {
            // v已被访问，是回边
            low[u] = min(low[u], dfn[v]);
        }
    }
}

// ==================== 主函数 ====================
int main() {
    int n, m;
    cout << "请输入节点数n和边数m：";
    cin >> n >> m;

    edgeCount = 0;
    cout << "请输入" << m << "条无向边（格式：点1 点2）：" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edgeCount++;
        adj[u].push_back({v, edgeCount});
        adj[v].push_back({u, edgeCount});  // 无向边，同一个编号
    }

    // 初始化
    timer = 0;
    for (int i = 1; i <= n; i++) {
        dfn[i] = 0;
        low[i] = 0;
    }
    for (int i = 1; i <= edgeCount; i++) {
        isBridge[i] = false;
    }

    // 对每个连通分量执行DFS
    for (int i = 1; i <= n; i++) {
        if (dfn[i] == 0) {
            findBridges(i, -1);
        }
    }

    // 输出桥
    cout << "\n========== 桥 ==========" << endl;
    int bridgeCount = 0;
    for (int i = 1; i <= edgeCount; i++) {
        if (isBridge[i]) {
            bridgeCount++;
            cout << "桥：边 #" << i << endl;
        }
    }
    if (bridgeCount == 0) {
        cout << "没有桥" << endl;
    }

    return 0;
}

/*
【核心区别：为什么割点用>=，桥用>？】

关键点：low[v] >= dfn[u] vs low[v] > dfn[u]

1. 对于割点：
   - low[v] >= dfn[u] 说明v无法绕过u到达u的祖先
   - 即使 low[v] == dfn[u]，删除u后v也无法到达u的祖先
   - 所以用 >=

2. 对于桥：
   - low[v] > dfn[u] 说明v完全无法到达u及u的祖先
   - 如果 low[v] == dfn[u]，说明v可以通过其他路径到达u
   - 这时即使删除边(u,v)，v仍可以通过u到达其他地方
   - 所以必须用 >

【图解】

情况1：边(u,v)是桥
    u ---- v
   /        \
  a          b
low[v] = dfn[v] > dfn[u]，边是桥

情况2：边(u,v)不是桥
    u ---- v
    |     /
    a ---
low[v] = dfn[u]，边不是桥（v可以通过a-u形成环）
*/
```

### 边双连通分量（完整代码）

```cpp
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 10005;

// ==================== 全局变量 ====================
vector<pair<int, int>> adj[MAXN];
int dfn[MAXN];
int low[MAXN];
bool visited[MAXN];
bool isBridge[MAXN * 2];
int timer;
int edgeCount;
int bccCount;
vector<int> bcc[MAXN];  // 存储每个边双连通分量的节点

// ==================== 第一步：找桥 ====================
void findBridges(int u, int parentEdge) {
    dfn[u] = low[u] = ++timer;

    for (auto& p : adj[u]) {
        int v = p.first;
        int edgeId = p.second;

        if (edgeId == parentEdge) continue;

        if (dfn[v] == 0) {
            findBridges(v, edgeId);
            low[u] = min(low[u], low[v]);

            if (low[v] > dfn[u]) {
                isBridge[edgeId] = true;
            }
        }
        else {
            low[u] = min(low[u], dfn[v]);
        }
    }
}

// ==================== 第二步：DFS找边双连通分量 ====================
void dfs(int u, int bccId) {
    visited[u] = true;
    bcc[bccId].push_back(u);

    for (auto& p : adj[u]) {
        int v = p.first;
        int edgeId = p.second;

        // 如果这条边是桥，跳过（不能跨过桥）
        if (isBridge[edgeId]) continue;

        if (!visited[v]) {
            dfs(v, bccId);
        }
    }
}

// ==================== 主函数 ====================
int main() {
    int n, m;
    cout << "请输入节点数n和边数m：";
    cin >> n >> m;

    edgeCount = 0;
    cout << "请输入" << m << "条无向边（格式：点1 点2）：" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edgeCount++;
        adj[u].push_back({v, edgeCount});
        adj[v].push_back({u, edgeCount});
    }

    // ===== 第一步：初始化并找桥 =====
    timer = 0;
    for (int i = 1; i <= n; i++) {
        dfn[i] = 0;
        low[i] = 0;
        visited[i] = false;
    }
    for (int i = 1; i <= edgeCount; i++) {
        isBridge[i] = false;
    }

    for (int i = 1; i <= n; i++) {
        if (dfn[i] == 0) {
            findBridges(i, -1);
        }
    }

    // ===== 第二步：通过DFS找边双连通分量 =====
    // 从每个未访问的节点开始，不跨过桥
    bccCount = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            bccCount++;
            dfs(i, bccCount);
        }
    }

    // ===== 输出结果 =====
    cout << "\n========== 边双连通分量 ==========" << endl;
    cout << "共有 " << bccCount << " 个边双连通分量：" << endl;
    for (int i = 1; i <= bccCount; i++) {
        cout << "BCC #" << i << ": ";
        for (int v : bcc[i]) {
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
【运行示例】

输入：
6 6
1 2
2 3
3 1
3 4
4 5
5 6

图的结构：
    1 - 2
     \ /
      3
      |
      4
      |
      5 - 6

输出：
共有 3 个边双连通分量：
BCC #1: 1 2 3
BCC #2: 4
BCC #3: 5 6

解释：
- 边(3,4)和边(4,5)是桥
- 所以{1,2,3}形成一个边双连通分量（环）
- 节点4单独形成一个（它是两条桥的连接点）
- {5,6}形成一个边双连通分量
*/
```

### 点双连通分量（完整代码）

点双连通分量稍微复杂一些，因为一个割点可能属于多个点双连通分量！

```cpp
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int MAXN = 10005;

// ==================== 全局变量 ====================
vector<int> adj[MAXN];
int dfn[MAXN];
int low[MAXN];
bool isCut[MAXN];
int timer;
int bccCount;
vector<int> bcc[MAXN];  // 存储每个点双连通分量
stack<pair<int, int>> stk;  // 存储边的栈

// ==================== Tarjan找点双连通分量 ====================
void tarjan(int u, int parent) {
    dfn[u] = low[u] = ++timer;
    int childCount = 0;

    for (int v : adj[u]) {
        if (v == parent) continue;

        if (dfn[v] == 0) {
            // v未被访问
            childCount++;
            stk.push({u, v});  // 边入栈
            tarjan(v, u);

            low[u] = min(low[u], low[v]);

            // 判断割点
            if ((parent == -1 && childCount >= 2) ||
                (parent != -1 && low[v] >= dfn[u])) {
                isCut[u] = true;

                // 找到一个点双连通分量：弹出边直到(u,v)
                bccCount++;
                while (true) {
                    auto edge = stk.top();
                    stk.pop();
                    bcc[bccCount].push_back(edge.first);
                    bcc[bccCount].push_back(edge.second);
                    // 边去重（因为是无向边，可能重复加入）
                    // 实际使用时可以用set或后续去重
                    if (edge.first == u && edge.second == v) break;
                }
            }
        }
        else if (dfn[v] < dfn[u]) {  // 回边，且v是u的祖先
            stk.push({u, v});
            low[u] = min(low[u], dfn[v]);
        }
    }
}

// ==================== 主函数 ====================
int main() {
    int n, m;
    cout << "请输入节点数n和边数m：";
    cin >> n >> m;

    cout << "请输入" << m << "条无向边（格式：点1 点2）：" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 初始化
    timer = 0;
    bccCount = 0;
    for (int i = 1; i <= n; i++) {
        dfn[i] = 0;
        low[i] = 0;
        isCut[i] = false;
    }

    // 执行Tarjan
    for (int i = 1; i <= n; i++) {
        if (dfn[i] == 0) {
            tarjan(i, -1);

            // 处理剩余的边（当根节点不是割点时）
            if (!stk.empty()) {
                bccCount++;
                while (!stk.empty()) {
                    auto edge = stk.top();
                    stk.pop();
                    bcc[bccCount].push_back(edge.first);
                    bcc[bccCount].push_back(edge.second);
                }
            }
        }
    }

    // 输出割点
    cout << "\n========== 割点 ==========" << endl;
    for (int i = 1; i <= n; i++) {
        if (isCut[i]) {
            cout << "割点：" << i << endl;
        }
    }

    // 输出点双连通分量（需要去重）
    cout << "\n========== 点双连通分量 ==========" << endl;
    for (int i = 1; i <= bccCount; i++) {
        // 去重
        vector<int> uniqueNodes;
        for (int v : bcc[i]) {
            bool found = false;
            for (int u : uniqueNodes) {
                if (u == v) {
                    found = true;
                    break;
                }
            }
            if (!found) uniqueNodes.push_back(v);
        }

        cout << "BCC #" << i << ": ";
        for (int v : uniqueNodes) {
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
【关键理解：为什么割点可以属于多个点双连通分量？】

考虑这个图：
    1
    |
    2
   / \
  3   4

- 节点2是割点
- 删除节点2后，图变成3部分：{1}, {3}, {4}
- 所以有两个点双连通分量：{1, 2} 和 {2, 3, 4}
- 割点2同时属于这两个分量！

对比边双连通分量：
- 删除一条边后，分量就分开了
- 一个节点不可能同时在两个边双连通分量中
- （除非它是孤立点）

生活例子：
- 想象节点2是一个枢纽机场
- 它连接着两个独立的航线网络
- 这个枢纽机场同时服务于两个网络
- 但如果枢纽关闭，两个网络就断开了
*/
```

---

## Part 3: 总结与对比

### 核心公式速记表

| 问题 | 判断条件 | 记忆口诀 |
|------|----------|----------|
| 强连通分量 | `dfn[u] == low[u]` | 自己就是祖先，独自成团 |
| 割点（非根） | `low[v] >= dfn[u]` | 孩子无法绕过我 |
| 割点（根） | 孩子数 >= 2 | 多棵子树，根也重要 |
| 桥 | `low[v] > dfn[u]` | 孩子完全够不着我 |

### 时间复杂度对比

| 算法 | 时间复杂度 | 空间复杂度 |
|------|------------|------------|
| 强连通分量 | O(V + E) | O(V) |
| 找割点 | O(V + E) | O(V) |
| 找桥 | O(V + E) | O(V + E) |
| 边双连通分量 | O(V + E) | O(V + E) |
| 点双连通分量 | O(V + E) | O(V + E) |

### 常见应用场景

1. **强连通分量**：
   - 社交网络分析（找出紧密联系的群体）
   - 编译器优化（找出相互调用的函数）
   - 2-SAT问题（二分图+SCC）

2. **双连通分量**：
   - 网络可靠性分析（找关键节点/边）
   - 电力网络设计（避免单点故障）
   - 道路规划（找出必经之路）

### 练习题目推荐

| 难度 | 题目 | 知识点 |
|------|------|--------|
| 入门 | P2863 [USACO06JAN]牛的舞会 | 强连通分量基础 |
| 入门 | P3388 割点 | 割点模板 |
| 进阶 | P2860 [USACO06JAN]冗余路径 | 边双连通 |
| 进阶 | P2746 [USACO5.3]校园网 | 强连通分量+缩点 |
| 困难 | P3225 [HNOI2012]矿场搭建 | 点双连通 |

---

## 后记

Tarjan算法的美妙之处在于：**一次DFS，多种信息**。

用一个简单的DFS，同时计算出：
- dfn数组（访问顺序）
- low数组（可达最远祖先）
- 顺带找出强连通分量/割点/桥/双连通分量

这就像去超市买东西，一次出门，买齐所有需要的物品，省时省力！

记住Tarjan大神的名言（我编的）：
> "给我一次DFS，我能找出图的所有秘密。"

掌握Tarjan算法，图论问题就攻克了一半！加油！

---

# 图论基础算法

### 前言：图论算法的重要性

图论是算法竞赛的"半壁江山"。无论是网络流、最短路、匹配问题，本质上都是在处理"关系"——这就是图的本质。

**生活中的图论问题**：
- **最短路**：导航软件如何找到最快路线？
- **二分图匹配**：如何安排男生和女生跳舞，让最多人满意？
- **最小生成树**：如何用最少的电缆连接所有城市？

---

## Part 1: 最短路径算法

### 问题引入

想象你是外卖小哥，需要从餐厅送餐到多个顾客家。你想知道：
- 从餐厅到每个顾客家的最短路线是什么？
- 顾客A和顾客B之间的最短距离是多少？

这就是最短路径问题！

### 最短路算法全家福

| 算法 | 适用场景 | 时间复杂度 | 能否处理负权边 |
|------|----------|------------|----------------|
| Dijkstra | 单源最短路，非负权边 | O((V+E)logV) | 不能 |
| Bellman-Ford | 单源最短路，可处理负权 | O(VE) | 能 |
| SPFA | Bellman-Ford的优化版 | 最坏O(VE)，平均O(E) | 能 |
| Floyd | 多源最短路（任意两点间） | O(V³) | 能（但不能有负环） |

---

### 1.1 Dijkstra算法

#### 核心思想

**贪心策略**：每次选择距离起点最近的未访问节点，然后更新它的邻居。

**生活比喻**：
想象你在水中央，水波一圈圈向外扩散。先到达的地方肯定是最先被"湿润"的，也就是距离最近的地方。

#### 详细步骤

1. 初始化：起点距离为0，其他点距离为无穷大
2. 选择未访问节点中距离最小的节点u
3. 用u去"松弛"它的所有邻居：如果 `dis[u] + w(u,v) < dis[v]`，则更新
4. 标记u为已访问
5. 重复步骤2-4，直到所有点都被访问

#### 图解过程

```
图：
        1
       /|\
      1 4 2
     /  |  \
    0---3---2
     \  |  /
      1 1 3
       \|/
        4

边：
0-1: 权重1
0-3: 权重1
1-2: 权重2
1-3: 权重4
2-3: 权重1
2-4: 权重3
3-4: 权重1

求从节点0到其他所有点的最短距离

执行过程：
初始状态：dis = [0, ∞, ∞, ∞, ∞]

第1轮：选择节点0（距离最小=0）
  更新邻居：dis[1] = min(∞, 0+1) = 1
            dis[3] = min(∞, 0+1) = 1
  dis = [0, 1, ∞, 1, ∞]

第2轮：选择节点1或3（距离都是1，选1）
  更新邻居：dis[2] = min(∞, 1+2) = 3
            dis[3] = min(1, 1+4) = 1（不更新）
  dis = [0, 1, 3, 1, ∞]

第3轮：选择节点3（距离=1）
  更新邻居：dis[2] = min(3, 1+1) = 2（更新！）
            dis[4] = min(∞, 1+1) = 2
  dis = [0, 1, 2, 1, 2]

第4轮：选择节点2（距离=2）
  更新邻居：dis[4] = min(2, 2+3) = 2（不更新）
  dis = [0, 1, 2, 1, 2]

第5轮：选择节点4（距离=2）
  没有未访问的邻居了

最终结果：dis = [0, 1, 2, 1, 2]
即：0->0=0, 0->1=1, 0->2=2, 0->3=1, 0->4=2
```

#### C++代码实现（优先队列优化版）

```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

const int MAXN = 100005;
const int INF = INT_MAX;

// ==================== 数据结构 ====================
struct Edge {
    int to;      // 边的终点
    int weight;  // 边的权重
    Edge(int t, int w) : to(t), weight(w) {}
};

// 用于优先队列的比较（小根堆）
struct Node {
    int id;       // 节点编号
    int dist;     // 到起点的距离
    Node(int i, int d) : id(i), dist(d) {}

    // 优先队列默认是大根堆，所以要反过来让它变成小根堆
    // dist小的排在前面（优先被取出）
    bool operator>(const Node& other) const {
        return dist > other.dist;
    }
};

// ==================== 全局变量 ====================
vector<Edge> adj[MAXN];  // 邻接表存图
int dis[MAXN];           // 到起点的最短距离
bool visited[MAXN];      // 是否已访问
int n, m;                // 节点数和边数

// ==================== Dijkstra算法 ====================
void dijkstra(int start) {
    // ===== 第一步：初始化 =====
    for (int i = 1; i <= n; i++) {
        dis[i] = INF;       // 所有点距离初始化为无穷大
        visited[i] = false; // 所有点标记为未访问
    }
    dis[start] = 0;  // 起点到自己的距离是0

    // ===== 第二步：创建优先队列（小根堆） =====
    // priority_queue<类型, 容器, 比较器>
    // greater<> 让它变成小根堆
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push(Node(start, 0));  // 起点入队

    // ===== 第三步：主循环 =====
    while (!pq.empty()) {
        // 取出当前距离最小的节点
        Node current = pq.top();
        pq.pop();

        int u = current.id;

        // 如果这个节点已经访问过，跳过
        // 为什么会有重复？因为同一个节点可能被多次加入队列
        // 但我们只需要第一次（距离最小那次）
        if (visited[u]) continue;
        visited[u] = true;  // 标记为已访问

        // ===== 第四步：松弛操作 =====
        // 遍历u的所有邻居，尝试更新它们的距离
        for (const Edge& edge : adj[u]) {
            int v = edge.to;
            int w = edge.weight;

            // 松弛操作：如果经过u到达v更近，则更新
            // 注意：dis[u]已经是确定的（因为它是最小的）
            if (!visited[v] && dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;  // 更新距离
                pq.push(Node(v, dis[v]));  // 将v加入队列
            }
        }
    }
}

// ==================== 主函数 ====================
int main() {
    cout << "请输入节点数n和边数m：";
    cin >> n >> m;

    cout << "请输入" << m << "条有向边（格式：起点 终点 权重）：" << endl;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(Edge(v, w));  // 有向边
        // 如果是无向图，加上下面这行：
        // adj[v].push_back(Edge(u, w));
    }

    int start;
    cout << "请输入起点：";
    cin >> start;

    // 执行Dijkstra算法
    dijkstra(start);

    // 输出结果
    cout << "\n========== 最短路径结果 ==========" << endl;
    for (int i = 1; i <= n; i++) {
        if (dis[i] == INF) {
            cout << "从" << start << "到" << i << "：不可达" << endl;
        } else {
            cout << "从" << start << "到" << i << "：" << dis[i] << endl;
        }
    }

    return 0;
}

/*
【运行示例】

输入：
5 7
0 1 1
0 3 1
1 2 2
1 3 4
2 3 1
2 4 3
3 4 1
0

输出：
从0到0：0
从0到1：1
从0到2：2
从0到3：1
从0到4：2

【关键理解】

1. 为什么Dijkstra不能处理负权边？
   考虑这个图：A --2--> B --(-3)--> C，A --1--> C
   Dijkstra会先选C（距离1），然后不会再更新C
   但实际最短路是 A->B->C = 2 + (-3) = -1
   贪心策略在负权边下失效！

2. 为什么用优先队列？
   - 朴素Dijkstra每次要找最小距离的点，需要O(V)
   - 用优先队列可以O(logV)取出最小值
   - 总时间从O(V²)优化到O((V+E)logV)

3. visited数组的作用？
   - 防止重复处理
   - Dijkstra的贪心保证：第一次访问某个点时，就是最优解
*/
```

---

### 1.2 Bellman-Ford算法

#### 为什么需要Bellman-Ford？

Dijkstra不能处理负权边，但现实中存在"负权"的情况：
- 股票交易：手续费是"负收益"
- 游戏中：某些技能会减少而非增加时间

Bellman-Ford就是为负权边而生的！

#### 核心思想

**暴力松弛**：对每条边都尝试松弛，重复V-1次。

为什么是V-1次？因为最短路径最多经过V-1条边（不重复走同一个点）。

#### C++代码实现

```cpp
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int INF = INT_MAX;

// ==================== 边的结构体 ====================
struct Edge {
    int from;    // 边的起点
    int to;      // 边的终点
    int weight;  // 边的权重
    Edge(int f, int t, int w) : from(f), to(t), weight(w) {}
};

// ==================== 全局变量 ====================
vector<Edge> edges;  // 存储所有边
int dis[10005];      // 到起点的距离
int n, m;            // 节点数和边数

// ==================== Bellman-Ford算法 ====================
bool bellmanFord(int start) {
    // ===== 第一步：初始化 =====
    for (int i = 1; i <= n; i++) {
        dis[i] = INF;
    }
    dis[start] = 0;

    // ===== 第二步：松弛V-1次 =====
    // 为什么是V-1次？
    // 因为最短路径最多有V-1条边
    // 每次松弛至少能确定一条边的最短路
    for (int i = 1; i <= n - 1; i++) {
        bool updated = false;  // 优化：如果本轮没有更新，提前结束

        // 对每条边进行松弛
        for (const Edge& e : edges) {
            // 注意：如果dis[e.from]是INF，不能松弛（INF + w会溢出）
            if (dis[e.from] != INF && dis[e.from] + e.weight < dis[e.to]) {
                dis[e.to] = dis[e.from] + e.weight;
                updated = true;
            }
        }

        // 如果本轮没有更新，说明已经找到最短路，提前结束
        if (!updated) break;
    }

    // ===== 第三步：检测负环 =====
    // 如果V-1次松弛后还能继续松弛，说明存在负环
    // 负环：环上权值和为负，可以无限绕圈让距离无限减小
    for (const Edge& e : edges) {
        if (dis[e.from] != INF && dis[e.from] + e.weight < dis[e.to]) {
            return false;  // 存在负环
        }
    }

    return true;  // 无负环，算法正常结束
}

// ==================== 主函数 ====================
int main() {
    cout << "请输入节点数n和边数m：";
    cin >> n >> m;

    cout << "请输入" << m << "条有向边（格式：起点 终点 权重）：" << endl;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(Edge(u, v, w));
    }

    int start;
    cout << "请输入起点：";
    cin >> start;

    // 执行Bellman-Ford算法
    bool noNegativeCycle = bellmanFord(start);

    if (!noNegativeCycle) {
        cout << "\n图中存在负权环！无法计算最短路径。" << endl;
        return 0;
    }

    // 输出结果
    cout << "\n========== 最短路径结果 ==========" << endl;
    for (int i = 1; i <= n; i++) {
        if (dis[i] == INF) {
            cout << "从" << start << "到" << i << "：不可达" << endl;
        } else {
            cout << "从" << start << "到" << i << "：" << dis[i] << endl;
        }
    }

    return 0;
}

/*
【运行示例 - 含负权边】

输入：
3 3
1 2 4
2 3 -5
1 3 3
1

输出：
从1到1：0
从1到2：4
从1到3：-1  （走1->2->3比直接走1->3更短）

【负环检测示例】

输入：
3 3
1 2 1
2 3 -2
3 1 -2
1

输出：
图中存在负权环！无法计算最短路径。

解释：
环 1->2->3->1 的权值和 = 1 + (-2) + (-2) = -3
每绕一圈，距离就减少3，可以无限绕圈！
*/
```

---

### 1.3 SPFA算法

#### SPFA是什么？

SPFA = Shortest Path Faster Algorithm，是Bellman-Ford的队列优化版。

**核心思想**：Bellman-Ford每轮对所有边松弛，但很多松弛是无效的。SPFA只处理"有变化的点"的邻居。

**生活比喻**：
- Bellman-Ford：每天给所有人发通知，即使有些人已经知道消息了
- SPFA：只在有新消息时，通知相关的人

#### C++代码实现

```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

const int MAXN = 10005;
const int INF = INT_MAX;

// ==================== 数据结构 ====================
struct Edge {
    int to;
    int weight;
    Edge(int t, int w) : to(t), weight(w) {}
};

// ==================== 全局变量 ====================
vector<Edge> adj[MAXN];  // 邻接表
int dis[MAXN];           // 距离
bool inQueue[MAXN];      // 是否在队列中（避免重复入队）
int count[MAXN];         // 入队次数（用于检测负环）
int n, m;

// ==================== SPFA算法 ====================
bool spfa(int start) {
    // 初始化
    for (int i = 1; i <= n; i++) {
        dis[i] = INF;
        inQueue[i] = false;
        count[i] = 0;
    }

    queue<int> q;
    dis[start] = 0;
    q.push(start);
    inQueue[start] = true;
    count[start] = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inQueue[u] = false;  // 出队后标记不在队列中

        // 松弛所有邻居
        for (const Edge& e : adj[u]) {
            int v = e.to;
            int w = e.weight;

            if (dis[u] != INF && dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;

                // 如果v不在队列中，加入队列
                if (!inQueue[v]) {
                    q.push(v);
                    inQueue[v] = true;
                    count[v]++;  // 入队次数+1

                    // 如果入队次数超过n，说明存在负环
                    // 为什么？因为最坏情况下，每个点最多入队n-1次
                    if (count[v] > n) {
                        return false;  // 存在负环
                    }
                }
            }
        }
    }

    return true;
}

// ==================== 主函数 ====================
int main() {
    cout << "请输入节点数n和边数m：";
    cin >> n >> m;

    cout << "请输入" << m << "条有向边（格式：起点 终点 权重）：" << endl;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(Edge(v, w));
    }

    int start;
    cout << "请输入起点：";
    cin >> start;

    bool noNegativeCycle = spfa(start);

    if (!noNegativeCycle) {
        cout << "\n图中存在负权环！" << endl;
        return 0;
    }

    cout << "\n========== 最短路径结果 ==========" << endl;
    for (int i = 1; i <= n; i++) {
        if (dis[i] == INF) {
            cout << "从" << start << "到" << i << "：不可达" << endl;
        } else {
            cout << "从" << start << "到" << i << "：" << dis[i] << endl;
        }
    }

    return 0;
}

/*
【SPFA vs Bellman-Ford】

Bellman-Ford：对所有边松弛V-1次
- 时间复杂度：O(VE)，恒定
- 适合稠密图

SPFA：只对"有变化"的点的邻居松弛
- 时间复杂度：平均O(E)，最坏O(VE)
- 大多数情况比Bellman-Ford快很多
- 但会被特殊数据卡成O(VE)

【什么时候用SPFA？】

1. 图中有负权边：必须用SPFA或Bellman-Ford
2. 需要检测负环：SPFA更高效
3. 随机数据：SPFA通常很快
4. 被针对性出题：SPFA可能被卡，要用Dijkstra或其他

【注意事项】

竞赛中SPFA可能被卡，很多题目会故意构造卡SPFA的数据。
如果确定没有负权边，优先用Dijkstra！
*/
```

---

### 1.4 Floyd算法

#### 多源最短路问题

前面三个算法都是单源最短路（一个起点到所有点）。
如果我们想知道**任意两点之间**的最短距离呢？

**朴素方法**：对每个点跑一次Dijkstra，时间O(V * (V+E)logV)

**Floyd算法**：用动态规划，时间O(V³)，代码超级简单！

#### 核心思想

**动态规划**：`dis[i][j]` 表示从i到j的最短距离。

状态转移：对于每个中间点k，尝试用k作为中转站：
```
dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j])
```

**生活比喻**：
你想从北京到纽约，可能会经过香港转机。Floyd算法就是尝试所有可能的"中转站"，找出最短路线。

#### C++代码实现

```cpp
#include <iostream>
using namespace std;

const int MAXN = 505;
const int INF = 1e9;  // 用一个足够大的数表示无穷大

// ==================== 全局变量 ====================
int dis[MAXN][MAXN];  // dis[i][j]表示从i到j的最短距离
int n, m;             // 节点数和边数

// ==================== Floyd算法 ====================
void floyd() {
    // 三重循环：k是中转点，i是起点，j是终点
    // 必须k在最外层！因为我们要逐步"引入"中转点

    for (int k = 1; k <= n; k++) {           // 枚举中转点
        for (int i = 1; i <= n; i++) {       // 枚举起点
            for (int j = 1; j <= n; j++) {   // 枚举终点
                // 尝试用k作为中转点，看能否缩短i到j的距离
                // 核心公式：dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j])

                // 注意：要检查dis[i][k]和dis[k][j]都不是INF
                // 否则相加可能溢出
                if (dis[i][k] != INF && dis[k][j] != INF) {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
    }
}

// ==================== 主函数 ====================
int main() {
    cout << "请输入节点数n和边数m：";
    cin >> n >> m;

    // ===== 第一步：初始化距离矩阵 =====
    // dis[i][i] = 0（自己到自己距离为0）
    // dis[i][j] = INF（i和j之间没有边）
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                dis[i][j] = 0;
            } else {
                dis[i][j] = INF;
            }
        }
    }

    // ===== 第二步：读入边 =====
    cout << "请输入" << m << "条有向边（格式：起点 终点 权重）：" << endl;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        // 如果两点之间有多条边，取最小的那条
        dis[u][v] = min(dis[u][v], w);
        // 如果是无向图，加上下面这行：
        // dis[v][u] = min(dis[v][u], w);
    }

    // ===== 第三步：执行Floyd算法 =====
    floyd();

    // ===== 第四步：输出结果 =====
    cout << "\n========== 任意两点最短距离 ==========" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dis[i][j] == INF) {
                cout << "INF\t";
            } else {
                cout << dis[i][j] << "\t";
            }
        }
        cout << endl;
    }

    return 0;
}

/*
【运行示例】

输入：
4 8
1 2 2
1 3 6
1 4 4
2 3 3
3 1 7
3 4 1
4 1 5
4 3 12

输出距离矩阵：
        1       2       3       4
1       0       2       5       4
2       9       0       3       4
3       6       8       0       1
4       5       7       10      0

解读：
- 从1到3的最短距离是5（1->2->3）
- 从2到1的最短距离是9（2->3->4->1）

【Floyd算法的精髓】

为什么k必须在外层？
- 我们定义dis_k[i][j] = 只用前k个点作为中转时，i到j的最短距离
- dis_0[i][j] = 初始图中的直接距离
- dis_k[i][j] = min(dis_{k-1}[i][j], dis_{k-1}[i][k] + dis_{k-1}[k][j])
- 最后dis_n[i][j]就是最终答案

【Floyd能做什么？】

1. 求任意两点最短距离 ✓
2. 检测负环：如果dis[i][i] < 0，说明存在负环 ✓
3. 求传递闭包（可达性问题） ✓
4. 求最小环 ✓

【最小环问题】

如何求图中的最小环？
对于每条边(u,v)，最小环 = dis[u][v] + dis[v][u] - w(u,v)
（即：u到v的最短路 + v到u的最短路 - 这条边的权重）

但要在Floyd的过程中求，因为Floyd完成后dis[u][v]可能包含了边(u,v)自己。
*/
```

#### Floyd求最小环

```cpp
// 在Floyd的过程中求最小环
int minCycle = INF;

for (int k = 1; k <= n; k++) {
    // 在更新dis[i][j]之前，先检查是否存在经过k的环
    // 此时dis[i][j]是不经过k的最短路（因为k还没被当作中转点）
    for (int i = 1; i < k; i++) {
        for (int j = i + 1; j < k; j++) {
            // 环 = i -> ... -> j -> k -> i
            // dis[i][j] + 原始边(j,k) + 原始边(k,i)
            if (dis[i][j] != INF && adj[j][k] != INF && adj[k][i] != INF) {
                minCycle = min(minCycle, dis[i][j] + adj[j][k] + adj[k][i]);
            }
        }
    }

    // 然后正常执行Floyd更新
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dis[i][k] != INF && dis[k][j] != INF) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
}
```

---

### 最短路算法选择指南

```
有负权边吗？
├── 没有
│   └── 单源最短路？── 是 ──> Dijkstra
│                      └── 否 ──> Floyd（点数<500）
├── 有
│   ├── 有负环吗？
│   │   ├── 有 ──> 无法求最短路（可以无限小）
│   │   └── 没有
│   │       ├── 单源 ──> SPFA（注意可能被卡）
│   │       └── 多源 ──> Floyd（点数<500）
```

---

## Part 2: 二分图与匈牙利算法

### 什么是二分图？

**定义**：图的节点可以分成两组，所有边都跨越两组，组内没有边。

**生活例子**：
- **相亲问题**：男生一组，女生一组，连线表示互相喜欢
- **课程分配**：学生一组，课程一组，连线表示学生想选这门课
- **宿舍分配**：学生一组，宿舍一组，连线表示学生愿意住这个宿舍

### 如何判断二分图？

**染色法**：尝试用两种颜色给图染色，相邻节点颜色不同。如果能成功，就是二分图。

```cpp
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 10005;

vector<int> adj[MAXN];  // 邻接表
int color[MAXN];        // 0表示未染色，1和2表示两种颜色
int n, m;

// DFS染色
bool dfs(int u, int c) {
    color[u] = c;  // 将u染成颜色c

    for (int v : adj[u]) {
        if (color[v] == 0) {
            // v未染色，递归染色
            // 如果染色失败，返回false
            if (!dfs(v, 3 - c)) {  // 3-c 让1变2，2变1
                return false;
            }
        }
        else if (color[v] == c) {
            // v已染色，且和u同色
            // 说明相邻节点同色，不是二分图
            return false;
        }
    }

    return true;
}

bool isBipartite() {
    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) {
            if (!dfs(i, 1)) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (isBipartite()) {
        cout << "是二分图" << endl;
    } else {
        cout << "不是二分图" << endl;
    }

    return 0;
}
```

---

### 二分图最大匹配 - 匈牙利算法

#### 什么是匹配？

**匹配**：选一些边，使得每个点最多连一条边。

**最大匹配**：选最多的边。

**生活例子**：
- 男生女生配对，每人只能配对一个
- 目标：让最多人配对成功

#### 匈牙利算法核心思想

**增广路**：从左边的未匹配点出发，交替走"未匹配边-匹配边"，最终到达右边的未匹配点。找到增广路后，交换"匹配/未匹配"状态，匹配数+1。

**大白话**：
- 男1喜欢女1，先配对
- 男2也喜欢女1，发现女1已配对
- 男2问男1：你能换一个吗？
- 男1发现还喜欢女2，于是男1->女2，女1->男2
- 配对成功！

#### 图解过程

```
左（男生）          右（女生）
    1 ────────────  1
    │             /
    │           /
    2 ────────/
    │
    │
    3 ────────────  2
                    │
                    │
                    3

边的连接：男1-女1, 男1-女2, 男2-女1, 男3-女2

执行过程：

第1轮：给男1找对象
  男1喜欢女1，女1空闲 -> 匹配成功！
  匹配：[(男1,女1)]

第2轮：给男2找对象
  男2喜欢女1，女1已匹配
  问女1的当前对象男1：你能换吗？
  男1还喜欢女2，女2空闲 -> 男1换到女2
  男2匹配女1
  匹配：[(男1,女2), (男2,女1)]

第3轮：给男3找对象
  男3喜欢女2，女2已匹配
  问女2的当前对象男1：你能换吗？
  男1还喜欢女1，女1已匹配
  问女1的当前对象男2：你能换吗？
  男2只喜欢女1，换不了 -> 失败
  男3单身

最终匹配数：2
```

#### C++代码实现（详细注释版）

```cpp
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 505;  // 左边最多500个点
const int MAXM = 505;  // 右边最多500个点

// ==================== 全局变量 ====================
vector<int> adj[MAXN];  // adj[u]存储u能匹配的所有右边点
int matchR[MAXM];       // matchR[v] = 与右边点v匹配的左边点，0表示未匹配
bool visited[MAXM];     // 每轮DFS的访问标记，防止重复访问
int n, m, e;            // 左边n个点，右边m个点，e条边

// ==================== 匈牙利算法核心：找增广路 ====================
bool dfs(int u) {
    // 遍历左边点u能匹配的所有右边点
    for (int v : adj[u]) {
        // 如果v在这轮已经被尝试过，跳过
        // 因为这一轮尝试v失败的话，再试还是失败
        if (visited[v]) continue;
        visited[v] = true;  // 标记v在这轮已被尝试

        // ===== 核心逻辑 =====
        // 情况1：v还没有匹配，直接把u和v匹配
        // 情况2：v已经匹配了，问v的当前对象能否换一个
        //        如果能换，就把v让给u

        if (matchR[v] == 0 || dfs(matchR[v])) {
            // v空闲，或者v的当前对象能换人
            // 那么把v分配给u
            matchR[v] = u;
            return true;  // 找到增广路，匹配成功
        }

        // 如果走到这里，说明v已经被匹配且其对象换不了人
        // 继续尝试u的其他喜欢对象
    }

    // u的所有喜欢对象都尝试过了，都失败了
    return false;
}

// ==================== 匈牙利算法主函数 ====================
int hungarian() {
    int result = 0;  // 最大匹配数

    // 初始化：所有右边点都未匹配
    memset(matchR, 0, sizeof(matchR));

    // 尝试为每个左边点找匹配
    for (int u = 1; u <= n; u++) {
        // 每轮DFS前，清空访问标记
        memset(visited, false, sizeof(visited));

        // 尝试为u找匹配
        // 如果找到增广路，匹配数+1
        if (dfs(u)) {
            result++;
        }
    }

    return result;
}

// ==================== 主函数 ====================
int main() {
    cout << "请输入左边点数n、右边点数m、边数e：" << endl;
    cin >> n >> m >> e;

    cout << "请输入" << e << "条边（格式：左边点 右边点）：" << endl;
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);  // u能匹配v
    }

    int maxMatch = hungarian();

    cout << "\n========== 匹配结果 ==========" << endl;
    cout << "最大匹配数：" << maxMatch << endl;

    // 输出具体的匹配方案
    cout << "匹配方案：" << endl;
    for (int v = 1; v <= m; v++) {
        if (matchR[v] != 0) {
            cout << "左边点" << matchR[v] << " <-> 右边点" << v << endl;
        }
    }

    return 0;
}

/*
【运行示例】

输入：
4 4 6
1 1
1 2
2 1
3 2
3 3
4 3

图的结构：
左边：1, 2, 3, 4
右边：1, 2, 3, 4
边：(1,1), (1,2), (2,1), (3,2), (3,3), (4,3)

输出：
最大匹配数：3
匹配方案：
左边点1 <-> 右边点2
左边点2 <-> 右边点1
左边点3 <-> 右边点3
（左边点4未匹配）

【算法复杂度】

时间复杂度：O(V * E)
- 最坏情况：每个左边点都要遍历所有边
- 实际运行通常比最坏情况快很多

空间复杂度：O(V + E)
- 邻接表存图：O(E)
- 匹配数组和访问数组：O(V)

【匈牙利算法的正确性】

基于"增广路定理"：
- 如果找不到增广路，当前匹配就是最大匹配
- 每找到一条增广路，匹配数+1
- 匹配数最多增加n次（左边点的数量）

【为什么叫"匈牙利算法"？】

因为这个算法由匈牙利数学家Harold Kuhn在1955年提出，
之后另一位匈牙利数学家Edmonds进行了改进。
为了纪念他们的贡献，以"匈牙利"命名。
*/
```

---

### 二分图匹配的应用

#### 1. 最小点覆盖

**定义**：选最少的点，使得每条边至少有一个端点被选中。

**König定理**：二分图中，最小点覆盖数 = 最大匹配数

#### 2. 最大独立集

**定义**：选最多的点，使得选出的点之间没有边。

**定理**：最大独立集 = 总点数 - 最小点覆盖 = 总点数 - 最大匹配

#### 3. 最小路径覆盖

**定义**：在有向无环图中，选最少的路径，使得每个点恰好被覆盖一次。

**做法**：
1. 把每个点拆成入点和出点，形成二分图
2. 原图的边(u,v)变成(出点u, 入点v)
3. 最小路径覆盖 = n - 最大匹配

```cpp
/*
【最小路径覆盖示例】

原图：
1 -> 2
2 -> 3
4 -> 2

拆点后：
左（出点）：1', 2', 3', 4'
右（入点）：1'', 2'', 3'', 4''
边：(1',2''), (2',3''), (4',2'')

最大匹配 = 2（比如(1',2'')和(2',3'')）
最小路径覆盖 = 4 - 2 = 2

实际上，可以用两条路径覆盖：
路径1：1 -> 2 -> 3
路径2：4
*/
```

---

## Part 3: 总结与对比

### 最短路算法速查表

| 算法 | 时间复杂度 | 适用场景 | 关键特点 |
|------|------------|----------|----------|
| Dijkstra | O((V+E)logV) | 单源，非负权 | 贪心，优先队列优化 |
| Bellman-Ford | O(VE) | 单源，可负权 | 暴力松弛，可检测负环 |
| SPFA | 平均O(E)，最坏O(VE) | 单源，可负权 | 队列优化，可能被卡 |
| Floyd | O(V³) | 多源 | 三重循环，代码简洁 |

### 二分图算法速查表

| 问题 | 算法 | 时间复杂度 |
|------|------|------------|
| 判断二分图 | 染色法 | O(V+E) |
| 最大匹配 | 匈牙利算法 | O(VE) |
| 最大匹配（优化） | Hopcroft-Karp | O(E√V) |

### 练习题目推荐

| 类型 | 难度 | 题目 | 知识点 |
|------|------|------|--------|
| 最短路 | 入门 | P4779 模板题 | Dijkstra堆优化 |
| 最短路 | 入门 | P3371 模板题 | SPFA |
| 最短路 | 进阶 | P1629 邮递员送信 | 往返最短路 |
| 最短路 | 进阶 | P1119 灾后重建 | Floyd时间维度 |
| 最短路 | 困难 | P1462 通往奥格瑞玛 | 二分+最短路 |
| 二分图 | 入门 | P3386 模板题 | 匈牙利算法 |
| 二分图 | 进阶 | P1640 连续攻击游戏 | 建模技巧 |
| 二分图 | 进阶 | P2756 飞行员配对 | 最大匹配应用 |
| 二分图 | 困难 | P1963 变换序列 | 建模+字典序 |

---

## 后记

图论算法是算法竞赛的基石。最短路和二分图匹配是其中最基础、最重要的两大类问题。

**学习建议**：
1. 先理解原理，再写代码
2. 多画图，手动模拟算法执行过程
3. 每个算法至少亲手实现3遍
4. 做题时注意建图技巧，很多问题本质是图论

记住：
> "图论问题，一半在建图，一半在模板。"

掌握了建图技巧和基础算法，图论问题就迎刃而解！



# 二分图(人工手写)
## 二分图是啥
二分图就是把一个图分成两个点集，然后每个点集直接的点没有**直接连边**（只能从这个点集合跳到那个点集在跳回来）。
## 判断二分图

### 思想
染色，遍历一遍，如果当前这个点没有被染色，把他染成左边（1号），然后开始dfs，染色到染完为止。如果当前这个点被染过色且和应该染的颜色不同，则该图不是二分图。

### 代码
```cpp
#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e4+5;
ll n,m;
ll cnt[3];
ll color[N];
vector<ll> g[N];
bool dfs(ll u,ll c){
    color[u]=c;
    cnt[c]++;
    for(auto v:g[u]){
        if(color[v]==color[u]) return 0;
        if(!color[v]){
            dfs(v,3-c);
        }
    }
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        ll u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        cnt[1]=cnt[2]=0;
        if(!color[i]&&!dfs(i,1)){
            cout<<"Impossible";
            return;
        }
        ans+=min(cnt[1],cnt[2]);
    }
    cout<<ans;
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

## 二分图最大匹配（匈牙利）
二分图最常用的算法
- 就是把每个点都遍历一遍，如果这个点可以匹配一个新的没被匹配的点，就匹配他，结束
- 或者，他把别人的匹配抢走，让别人再去匹配，如果别人抢到了新的，同样成功，结束
- 如果都没有，死
>[!IMPORTANT]
>匈牙利算法的时间复杂度是$O(n^2)$

### 代码
```cpp
#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e3+5;
ll n1,n2,m;
vector<ll> g[N];
ll match[N];
ll vis[N];
bool dfs(ll x){
    for(auto i:g[x]){
        if(!vis[i]){
            vis[i]=1;
            if(!match[i]||dfs(match[i])){
                match[i]=x;
                return 1;
            }
        }
    }
    return 0;
}
void solve(){
    cin>>n1>>n2>>m;
    for(int i=1;i<=m;i++){
        ll x,y;
        cin>>x>>y;
        y+=n1;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    ll cnt=0;
    for(int i=1;i<=n1;i++){
        memset(vis,0,sizeof(vis));
        if(dfs(i)) cnt++;
    }
    cout<<cnt;
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

## 最大独立集
刚开始，每个点就是一个独立集。每出现一个匹配，就会少两个独立集，然后出现一个新的$(-2+1)$
所以，最大独立集=$n$（点数）$-$ 最大匹配

## 最小点覆盖
用最少的边覆盖所有的点，不就是最大匹配吗?
所以，最小点覆盖=最大匹配



# tarjan算法（人工手写）
## 主要思想
1. dfn序：当前这个点的时间戳（访问时间）
2. low:这个点不走来时的边，可以访问到的最早时间戳
## 前置算法
### 割点
如果删掉这个点之后，图的连通块个数会变，那么这个点就是割点
#### 思想
只要我的儿子不通过我回不到**更早的祖宗**，我就是割点
#### 代码
题目：[洛谷P3388](https://www.luogu.com.cn/problem/P3388) 
```cpp
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e4+5;
ll n,m;//n->点数,m->边数
vector<ll> g[N];
ll idx=0;//时间戳
bool flag[N];//点i是割点的话，flag[i]=1,反之则不是割点
//特色数组
ll root;
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
            if(fa!=0&&low[i]>=num[x]){
                flag[x]=1;
            }
            //果当前节点是根节点，在生成树中必须要有两个儿子，根节点才是割点（一个点断了儿子成根节点就没事呀）
            if(fa==0&&child>=2){
                flag[x]=1;
            }
        }
        else{
            //如果节点i被访问过并且不受当前节点的父亲，则说明i为x的祖先，要更新当前节点的low
            //i都已经是x的祖先了，肯定是可以到的
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
    for(int i=1;i<=n;i++){
        if(!num[i]){
            root=i;
            dfs(i,0);
        }
    }
    //从一开始开始dfs
    //输出割点
    vector<ll> ans;
    for(int i=1;i<=n;i++) if(flag[i]==1) ans.push_back(i);
    cout<<ans.size()<<el;
    for(auto i:ans) cout<<i<<" ";
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

### 割边
如果删掉这条边之后，图的连通块个数会变，那么这个点就是割边
#### 思想
只要我的儿子不通过**我到儿子这条边**回不到**我和更早的祖宗**，我到我的儿子这条边就是割边
#### 代码
[洛谷P1656](https://www.luogu.com.cn/problem/P1656) 
```cpp
/*
只需要将low[i]>=num[x]改为low[i]>num[x]然后改一下输出就好
因为割边是不走这条边连爸爸都回不到了，所以把'='删掉就好啦
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,m;
vector<ll> g[N];
ll root;
ll idx=0;
bool flag[N];
ll num[N];//当前时间戳
ll low[N];//可以回到的最早时间戳
vector<pair<ll,ll>> sorted;//存割边的
void dfs(ll x,ll fa){
    ll child=0;//孩子数量（从生成树的角度来说）
    idx++;//时间戳++
    num[x]=idx;
    low[x]=idx;
    for(auto i:g[x]){
        if(num[i]==0){//当前节点还没放问过（时间戳没赋值）
            dfs(i,x);//dfs他
            low[x]=min(low[x],low[i]);//维护这个点能回到的时间戳最早的节点
            if(low[i]>num[x]){//我的儿子
                sorted.push_back({x,i});
            }
        }
        else if(i!=fa){//防止我把我到爸爸那条边也当成了一条不同的路，否则我一条割边都找不到
            low[x]=min(low[x],num[i]);
        }
    }
    return;
}
void solve()
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        ll u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    root=1;
    dfs(1,root);
    //输出割边（注意输出！！！）
    //还要排序
    sort(sorted.begin(),sorted.end());
    for(auto i:sorted){
        cout<<i.first<<" "<<i.second<<el;
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


## e-DCC(边双连通分量)
### 问题描述
就是将一个图，通过割边切分成多个连通块（不走割边），这些连通块称之为边双连通分量。
（附加操作：把这些连通块视作一个点，割边当成新图的边，进行缩点）


>[!IMPORTANT]
>他这个东西缩完点之后的图是个树.

### 代码
```cpp
#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,m;
vector<ll> g[N],ng[N]; // g: 原图邻接表, ng: 缩点后的新图(树)
ll dfn[N],low[N];       // Tarjan 算法的时间戳与回溯值
ll idx;                 // 全局计数器：先用于 dfn 编号，后用于 color 编号
vector<pair<ll,ll>> bridge; // 存储所有找出的割边
map<pair<ll,ll>,bool> mp;   // 标记割边，用于染色时阻断连接
ll color[N];            // color[i] 表示点 i 属于哪个边双连通分量
// 第一步：DFS 寻找割边
void dfs(ll x,ll fa){
    dfn[x]=++idx;
    low[x]=idx;
    for(auto i:g[x]){
        if(dfn[i]==0){ // 未访问过的节点（树枝边）
            dfs(i,x);
            low[x]=min(low[i],low[x]);
            // 【割边判定】子节点 i 无法通过其他路径回到 x 或 x 以上的祖先
            if(low[i]>dfn[x]) bridge.push_back({x,i});
        }
        // 【关键点】此处通过 i!=fa 忽略父节点。
        // 注意：若原图有重边（x, fa 之间多条边），此逻辑会误判，建议改用边编号判断。
        else if(i!=fa) low[x]=min(low[x],dfn[i]);
    }
}
// 第二步：Flood Fill 染色（缩点）
void change(ll x){
    color[x]=idx; // 为当前点赋予新的分量编号
    for(auto i:g[x]) {
        // 【核心逻辑】在原图上扩展，但满足两个条件：
        // 1. 当前边不是割边 (通过 mp 判断)
        // 2. 目标点还没有被染色
        if(!mp[{min(x,i),max(x,i)}] && !color[i]) change(i);
    }
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        ll x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    // 1. 跑 Tarjan 寻找割边（假设原图连通，否则需循环检查未访问点）
    dfs(1,0);
    // 2. 预处理割边：排序并存入 map，方便 change 函数 O(log E) 判定
    for(auto &i:bridge) if(i.first>i.second) swap(i.first,i.second);
    for(auto &i:bridge) mp[{i.first,i.second}]=1;
    // 3. 染色：将每个边双连通分量缩成一个点
    idx=0;
    for(int i=1;i<=n;i++){
        if(!color[i]){
            idx++; // 每个新的分量拥有唯一 ID
            change(i);
        }
    }
    // 4. 建立新图：遍历所有割边，连接它们所属的缩点
    for(auto i:bridge){
        ng[color[i.first]].push_back(color[i.second]);
        ng[color[i.second]].push_back(color[i.first]);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll T=1;
    while(T--){
        solve();
    }
    return 0;
}
```
