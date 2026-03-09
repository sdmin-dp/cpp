# GESP 7级三角函数考点整理

**内容**: sin, cos, tan 手算、特殊值、代码要点和考试应对方法  
**日期**: 2026年3月

---

## 一、三角函数基本概念

### 1.1 直角三角形定义

在直角三角形中，对于角θ：

| 函数 | 定义 |
|------|------|
| sin(θ) | 对边 / 斜边 |
| cos(θ) | 邻边 / 斜边 |
| tan(θ) | 对边 / 邻边 = sin(θ) / cos(θ) |

### 1.2 单位圆定义

在单位圆（半径为1的圆）中，对于角θ：

| 函数 | 定义 |
|------|------|
| sin(θ) | y坐标 |
| cos(θ) | x坐标 |
| tan(θ) | y / x |

---

## 二、特殊角三角函数值（必须背熟！）

### 2.1 基本特殊角

| 角度(°) | 弧度 | sin | cos | tan |
|---------|------|-----|-----|-----|
| 0° | 0 | 0 | 1 | 0 |
| 30° | π/6 | 1/2 | √3/2 | √3/3 |
| 45° | π/4 | √2/2 | √2/2 | 1 |
| 60° | π/3 | √3/2 | 1/2 | √3 |
| 90° | π/2 | 1 | 0 | 无穷大 |

### 2.2 记忆技巧

1. **sin值**: 0, 1/2, √2/2, √3/2, 1（从小到大）
2. **cos值**: 1, √3/2, √2/2, 1/2, 0（从大到小，与sin相反）
3. **tan值** = sin / cos

### 2.3 其他常用角度

| 角度(°) | 弧度 | sin | cos | tan |
|---------|------|-----|-----|-----|
| 15° | π/12 | (√6-√2)/4 | (√6+√2)/4 | 2-√3 |
| 75° | 5π/12 | (√6+√2)/4 | (√6-√2)/4 | 2+√3 |
| 120° | 2π/3 | √3/2 | -1/2 | -√3 |
| 135° | 3π/4 | √2/2 | -√2/2 | -1 |
| 150° | 5π/6 | 1/2 | -√3/2 | -√3/3 |
| 180° | π | 0 | -1 | 0 |

---

## 三、手算三角函数值的方法

### 3.1 方法1：利用特殊角加减

**示例**: sin(15°)

```
sin(15°) = sin(45°-30°)
        = sin45cos30 - cos45sin30
        = (√2/2)(√3/2) - (√2/2)(1/2)
        = (√6 - √2)/4
```

### 3.2 方法2：利用半角公式

**示例**: cos(15°)

```
cos(15°) = cos(30°/2)
        = √[(1+cos30)/2]
        = √[(1+√3/2)/2]
        = √[(2+√3)/4] = (√6+√2)/4
```

### 3.3 方法3：利用三倍角公式

```
sin(3θ) = 3sinθ - 4sin³θ
cos(3θ) = 4cos³θ - 3cosθ
```

### 3.4 方法4：利用和差化积

```
sinA + sinB = 2sin[(A+B)/2]cos[(A-B)/2]
sinA - sinB = 2cos[(A+B)/2]sin[(A-B)/2]
cosA + cosB = 2cos[(A+B)/2]cos[(A-B)/2]
cosA - cosB = -2sin[(A+B)/2]sin[(A-B)/2]
```

---

## 四、三角函数恒等变换（考试重点）

### 4.1 基本关系式

1. **平方关系**: sin²θ + cos²θ = 1
2. **商数关系**: tanθ = sinθ / cosθ
3. **与tan的关系**: 1 + tan²θ = 1/cos²θ

### 4.2 诱导公式

**记忆口诀**: 奇变偶不变，符号看象限

| sin | 结果 |
|-----|------|
| sin(π/2 + θ) | cosθ |
| sin(π/2 - θ) | cosθ |
| sin(π + θ) | -sinθ |
| sin(π - θ) | sinθ |
| sin(2π + θ) | sinθ |
| sin(2π - θ) | -sinθ |

| cos | 结果 |
|-----|------|
| cos(π/2 + θ) | -sinθ |
| cos(π/2 - θ) | sinθ |
| cos(π + θ) | -cosθ |
| cos(π - θ) | -cosθ |
| cos(2π + θ) | cosθ |
| cos(2π - θ) | cosθ |

### 4.3 和差角公式

```
sin(α+β) = sinαcosβ + cosαsinβ
sin(α-β) = sinαcosβ - cosαsinβ
cos(α+β) = cosαcosβ - sinαsinβ
cos(α-β) = cosαcosβ + sinαsinβ
tan(α+β) = (tanα+tanβ)/(1-tanαtanβ)
tan(α-β) = (tanα-tanβ)/(1+tanαtanβ)
```

### 4.4 倍角公式

```
sin(2θ) = 2sinθcosθ
cos(2θ) = cos²θ - sin²θ = 2cos²θ - 1 = 1 - 2sin²θ
tan(2θ) = 2tanθ/(1-tan²θ)
```

### 4.5 半角公式

```
sin(θ/2) = ±√[(1-cosθ)/2]
cos(θ/2) = ±√[(1+cosθ)/2]
tan(θ/2) = sinθ/(1+cosθ) = (1-cosθ)/sinθ
```

### 4.6 万能公式

```
sinθ = 2tan(θ/2) / [1+tan²(θ/2)]
cosθ = [1-tan²(θ/2)] / [1+tan²(θ/2)]
tanθ = 2tan(θ/2) / [1-tan²(θ/2)]
```

---

## 五、C++代码实现要点

### 5.1 常量定义

```cpp
const double PI = acos(-1.0);  // 获取π的精确值
const double EPS = 1e-9;       // 精度控制
```

### 5.2 角度与弧度转换

```cpp
// 角度转弧度
double degToRad(double degree) {
    return degree * PI / 180.0;
}

// 弧度转角度
double radToDeg(double radian) {
    return radian * 180.0 / PI;
}
```

### 5.3 计算三角函数值

```cpp
void calculateTrigonometric(double degree) {
    double rad = degToRad(degree);
    
    cout << "角度: " << degree << "°" << endl;
    cout << "弧度: " << rad << endl;
    cout << "sin: " << sin(rad) << endl;
    cout << "cos: " << cos(rad) << endl;
    cout << "tan: " << tan(rad) << endl;
}
```

### 5.4 精度处理

```cpp
// 判断两个浮点数是否相等
bool isEqual(double a, double b) {
    return fabs(a - b) < EPS;
}
```

### 5.5 反三角函数

```cpp
// asin: arcsin, 返回[-π/2, π/2]
double angle1 = asin(0.5);

// acos: arccos, 返回[0, π]
double angle2 = acos(0.5);

// atan: arctan, 返回[-π/2, π/2]
double angle3 = atan(1.0);

// atan2: 更精确的arctan，返回[-π, π]
// atan2(y, x) 比 atan(y/x) 更好，因为能处理x=0的情况
double angle4 = atan2(1.0, 1.0);
```

### 5.6 三角形面积计算

```cpp
// 已知两边及其夹角，求面积
double triangleAreaBySides(double a, double b, double angleC) {
    // S = (1/2)ab*sin(C)
    return 0.5 * a * b * sin(degToRad(angleC));
}

// 海伦公式（已知三边）
double triangleAreaBySides(double a, double b, double c) {
    double s = (a + b + c) / 2.0;
    double area = s * (s - a) * (s - b) * (s - c);
    if (area < 0) return 0;  // 构不成三角形
    return sqrt(area);
}
```

### 5.7 余弦定理求角度

```cpp
// 已知三角形三边a, b, c，求边c对应的角C
double angleByCosine(double a, double b, double c) {
    // cos(C) = (a² + b² - c²) / (2ab)
    double cosC = (a * a + b * b - c * c) / (2 * a * b);
    
    // 注意：cosC必须在[-1, 1]范围内
    if (cosC > 1) cosC = 1;
    if (cosC < -1) cosC = -1;
    
    return radToDeg(acos(cosC));
}
```

### 5.8 正弦定理求边长

```cpp
// 已知边a和角A、角B，求边b
double sideBySine(double a, double angleA, double angleB) {
    // a/sin(A) = b/sin(B)
    // b = a * sin(B) / sin(A)
    return a * sin(degToRad(angleB)) / sin(degToRad(angleA));
}
```

---

## 六、考试应对方法

### 6.1 必须背熟的内容

- ✓ 0°, 30°, 45°, 60°, 90° 的 sin, cos, tan 值
- ✓ sin²θ + cos²θ = 1
- ✓ tanθ = sinθ / cosθ
- ✓ sin(2θ) = 2sinθcosθ
- ✓ cos(2θ) = cos²θ - sin²θ

### 6.2 常见题型及解法

| 题型 | 解法 | 技巧 |
|------|------|------|
| 求三角函数值 | 利用特殊角、恒等变换 | 将角度转化为特殊角的和差 |
| 化简三角函数表达式 | 运用恒等式、诱导公式 | 统一函数名（都化为sin或cos） |
| 证明三角恒等式 | 从复杂的一边向简单的一边化简 | 灵活运用和差角、倍角公式 |
| 解三角方程 | 化为基本方程，如 sinθ = a | 注意周期性和多解情况 |
| 几何应用（求角度、距离、面积） | 画图，建立三角关系 | 善用正弦定理、余弦定理 |

### 6.3 编程题注意事项

#### ① 度数与弧度的转换
- C++的sin/cos/tan函数使用弧度制
- 必须先转换：`rad = degree * π / 180`

#### ② 精度问题
- 使用EPS进行比较：`fabs(a - b) < EPS`
- 避免直接用 `==` 比较浮点数

#### ③ 反三角函数
- asin返回[-π/2, π/2]
- acos返回[0, π]
- atan2(y, x)比atan(y/x)更精确

#### ④ 边界情况
- tan(90°)无定义
- cosθ在[-1, 1]范围内，超出范围报错

### 6.4 常见错误

| 错误类型 | 错误示例 | 正确做法 |
|---------|---------|---------|
| 忘记角度与弧度的转换 | sin(30) | sin(PI/6) 或 sin(degToRad(30)) |
| 浮点数直接比较 | if (a == b) | if (fabs(a-b) < EPS) |
| 忽略三角函数的定义域 | 当cosθ=0时计算tanθ | 检查分母是否为0 |
| 混淆角度制和弧度制 | sin(180) ≠ 0 | sin(PI) = 0 |

### 6.5 快速检查技巧

#### ① 检查结果是否在合理范围内
- sin值在[-1, 1]
- cos值在[-1, 1]
- tan值可以是任意实数

#### ② 检查特殊角的结果
- sin(0)=0, sin(90°)=1
- cos(0)=1, cos(90°)=0
- tan(45°)=1

#### ③ 检查象限符号
| 象限 | sin | cos | tan |
|------|-----|-----|-----|
| 第一象限 | + | + | + |
| 第二象限 | + | - | - |
| 第三象限 | - | - | + |
| 第四象限 | - | + | - |

### 6.6 时间分配建议

| 题型 | 数量 | 每题时间 | 建议 |
|------|------|---------|------|
| 选择题 | 10道 | 2-3分钟 | 优先利用特殊角判断，排除法快速选择 |
| 填空题 | 5道 | 3-4分钟 | 步骤要清晰，注意精度要求 |
| 编程题 | 2-3道 | 15-20分钟 | 先画图分析，编写关键代码，注意边界测试 |

### 6.7 备考建议

- ✓ 每天背诵特殊角三角函数值
- ✓ 多做化简题，熟练运用公式
- ✓ 练习编程题，熟悉C++三角函数库
- ✓ 总结常见题型和解题模板
- ✓ 做历年真题，熟悉考试风格

### 6.8 高分技巧

#### ① 灵活运用公式
- 不要死记硬背，要理解公式间的关系
- 多种方法解同一题，选择最优方法

#### ② 善于观察规律
- 注意题目中的对称性、周期性
- 利用特殊角进行估算

#### ③ 编程题优化
- 预处理常用值
- 避免重复计算
- 注意时间复杂度

#### ④ 细心检查
- 检查单位（度数还是弧度）
- 检查符号（正负）
- 检查精度（EPS设置）

---

## 七、典型例题代码

### 7.1 例题1：给定三角形三边，求三个角

```cpp
void example1() {
    cout << "【例题1】给定三角形三边，求三个角" << endl;
    double a, b, c;
    cout << "输入三边长度（用空格分隔）: ";
    cin >> a >> b >> c;

    // 检查是否能构成三角形
    if (a + b <= c || a + c <= b || b + c <= a) {
        cout << "无法构成三角形！" << endl;
        return;
    }

    // 利用余弦定理求三个角
    double angleA = angleByCosine(b, c, a);
    double angleB = angleByCosine(a, c, b);
    double angleC = angleByCosine(a, b, c);

    cout << "角A = " << angleA << "°" << endl;
    cout << "角B = " << angleB << "°" << endl;
    cout << "角C = " << angleC << "°" << endl;
    cout << "验证：角度和 = " << angleA + angleB + angleC << "°" << endl;
}
```

### 7.2 例题2：计算两点间距离和方向角

```cpp
void example2() {
    cout << "【例题2】计算两点间距离和方向角" << endl;
    double x1, y1, x2, y2;
    cout << "输入第一个点坐标(x1 y1): ";
    cin >> x1 >> y1;
    cout << "输入第二个点坐标(x2 y2): ";
    cin >> x2 >> y2;

    // 计算距离
    double dx = x2 - x1;
    double dy = y2 - y1;
    double distance = sqrt(dx * dx + dy * dy);

    // 计算方向角（atan2返回[-π, π]）
    double angle = atan2(dy, dx);
    double angleDeg = radToDeg(angle);

    cout << "距离 = " << distance << endl;
    cout << "方向角 = " << angleDeg << "°" << endl;
}
```

### 7.3 例题3：判断点是否在圆内

```cpp
void example3() {
    cout << "【例题3】判断点是否在圆内" << endl;
    double cx, cy, r, px, py;
    cout << "输入圆心坐标(cx cy)和半径r: ";
    cin >> cx >> cy >> r;
    cout << "输入点坐标(px py): ";
    cin >> px >> py;

    // 计算点到圆心的距离
    double dx = px - cx;
    double dy = py - cy;
    double distance = sqrt(dx * dx + dy * dy);

    if (isEqual(distance, r)) {
        cout << "点在圆上" << endl;
    } else if (distance < r) {
        cout << "点在圆内" << endl;
    } else {
        cout << "点在圆外" << endl;
    }
}
```

---

## 八、附录：完整代码框架

```cpp
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const double PI = acos(-1.0);
const double EPS = 1e-9;

// 角度转弧度
double degToRad(double degree) {
    return degree * PI / 180.0;
}

// 弧度转角度
double radToDeg(double radian) {
    return radian * 180.0 / PI;
}

// 判断浮点数相等
bool isEqual(double a, double b) {
    return fabs(a - b) < EPS;
}

int main() {
    // 你的代码...
    return 0;
}
```

---

**祝考试顺利！加油！** 🎯