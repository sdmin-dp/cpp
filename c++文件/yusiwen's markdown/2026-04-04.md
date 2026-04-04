# U673047 [MAFC 2026] Abandon

## 题目背景

:::info[图]
![](https://file.murasame.site/aprilfools/A-image.png)
:::

如你所见，最牛逼的模型 Gemini 3.1 Pro 甚至都不能通过这道题的样例。你能超越 Gemini 吗？

为了证明你超越了 Gemini 3.1 Pro，请命名一个变量为 abandon。

## 题目描述

你需要实现一个人工智能。

输入会给定[牛津词典](https://www.oed.com/)中的一项（单词、短语、前后缀等），你需要输出其在[牛津词典](https://www.oed.com/)中的排名。

为了方便，下面提供一些信息和约定：

- 截至出题时间，词典共有 $521,007$ 个项目。词典中可能会加入新的项目，但由于特殊的评分机制，这并不影响本题的解法。
- 某些拼写相同的项目在词典中可能出现多次，但由于特殊的评分机制，这并不影响本题的解法。
- 牛津词典的排序方式大概是，去掉一个项目的**非字母内容**，全部转小写，然后字典序。
- 可以在[这里](https://www.oed.com/search/advanced/Entries?textTermOpt0=WordPhrase&dateOfUseFirstUse=false&page=0&sortOption=AZ)查看单词列表，使用 <https://www.oed.com/search/advanced/Entries?textTermOpt0=WordPhrase&dateOfUseFirstUse=false&page=0&sortOption=AZ&jumpTo=单词> 跳转到对应单词的页面。

### 【评分方式】

对于每个 subtask 的所有测试点，记你输出的答案与标准答案的差的最大值为 $D$。

则你的得分为：

$$
\text{Score}(\%) = 
\begin{cases} 
100 & (D \le 2048) \\
\max \left \{ 1, \left \lfloor 100 \times \frac{\log_{10}(32768) - \log_{10}(D)}{\log_{10}(32768) - \log_{10}(2048)} \right \rfloor \right \} & (2048 < D \le 32768) \\
0 & (D > 32768)
\end{cases}
$$

## 输入格式

[牛津词典](https://www.oed.com/)中的一项。

## 输出格式

排名。

## 输入输出样例 #1

### 输入 #1

```
a
```

### 输出 #1

```
1
```

## 输入输出样例 #2

### 输入 #2

```
abandon
```

### 输出 #2

```
107
```

## 输入输出样例 #3

### 输入 #3

```
April
```

### 输出 #3

```
17157
```

## 输入输出样例 #4

### 输入 #4

```
fools
```

### 输出 #4

```
143682
```

## 输入输出样例 #5

### 输入 #5

```
April fool
```

### 输出 #5

```
17159
```

## 输入输出样例 #6

### 输入 #6

```
viviparism
```

### 输出 #6

```
500000
```

## 输入输出样例 #7

### 输入 #7

```
Zyzzyva
```

### 输出 #7

```
520973
```

## 输入输出样例 #8

### 输入 #8

```
78
```

### 输出 #8

```
521003
```

## 输入输出样例 #9

### 输入 #9

```
supercalifragilisticexpialidocious
```

### 输出 #9

```
439948
```

## 输入输出样例 #10

### 输入 #10

```
pneumonoultramicroscopicsilicovolcanoconiosis
```

### 输出 #10

```
323276
```

## 说明/提示

提示：你可以 abandon。

::cute-table{tuack}
|子任务编号|特殊性质|分值|
|:-:|:-:|:-:|
|1|输入是 abandon|5|
|2|输入是一个整数|10|
|3|输入是一个字母|30|
|4|输入是样例|5|
|5|数据从词典所有的项中随机选取|50|