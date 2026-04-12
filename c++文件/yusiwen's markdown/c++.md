
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

# 背包DP
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
