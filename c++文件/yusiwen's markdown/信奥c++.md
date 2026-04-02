## Lucas' Theorem (卢卡斯定理)

### 基本概念

Lucas' Theorem是组合数学中的一个重要定理，用于计算大数组合数模一个质数的情况。该定理由法国数学家Édouard Lucas在1878年提出。

### 定理表述

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

### 基本公式

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

### 主要应用

#### 1. 大数组合数模质数计算

当m和n非常大时，直接计算C(m, n)是不可能的。Lucas' Theorem可以将大组合数问题分解为多个小组合数的乘积。

#### 2. 组合数性质研究

通过Lucas' Theorem可以研究组合数在模p下的性质和分布规律。

#### 3. 算法竞赛中的应用

在算法竞赛中，经常需要计算大组合数模某个质数的结果，Lucas' Theorem提供了高效的计算方法。

### C++实现

#### 基础实现

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

#### 优化版本（预处理阶乘和逆元）

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

#### 多组测试数据优化版本

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

### 算法分析

#### 时间复杂度

1. **预处理阶段**：O(p)
   - 预处理阶乘数组：O(p)
   - 预处理逆元数组：O(p)

2. **查询阶段**：O(log_p n)
   - 每次递归调用将n除以p，递归深度为log_p n
   - 每层递归需要O(1)时间计算C(m_i, n_i)

#### 空间复杂度

1. **存储空间**：O(p)
   - 需要存储阶乘数组和逆元数组

### 应用示例

#### 示例1：计算C(100, 20) mod 7

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

#### 示例2：计算C(12345, 6789) mod 13

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

### 扩展应用

#### 1. 多重组合数计算

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

#### 2. 组合数求和

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

### 注意事项

1. **质数限制**：Lucas' Theorem要求模数p必须是质数
2. **递归深度**：对于非常大的数，递归可能导致栈溢出，可以使用迭代实现
3. **预处理优化**：对于多组测试数据，预处理阶乘和逆元可以显著提高效率
4. **边界条件**：注意处理n > m的情况，此时组合数为0

### 与其他算法的比较

| 算法 | 时间复杂度 | 空间复杂度 | 适用场景 |
|------|------------|------------|----------|
| 直接计算 | O(n) | O(1) | n较小 |
| Lucas' Theorem | O(log_p n) | O(p) | n很大，p较小 |
| 动态规划 | O(n²) | O(n²) | n较小 |
| 生成函数 | O(n log n) | O(n) | 特定模式 |

### 练习题目

1. **基础题**：计算C(2n, n) mod p
2. **进阶题**：计算sum_{k=0}^{n} C(m, k) mod p
3. **挑战题**：计算C(n, k) mod p^r（扩展Lucas定理）
4. **应用题**：计算多项式系数模质数

通过Lucas' Theorem，我们可以高效地解决大数组合数模质数的问题，这在算法竞赛和数学研究中都有重要应用。掌握这个定理对于解决组合数学相关问题非常有帮助。