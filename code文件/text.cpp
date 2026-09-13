#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll len[90], dp[90][3];
void init() {
len[0] = 1;
len[1] = 2;
dp[1][1] = 1;
for (int i = 2; i <= 86; ++i) {
len[i] = len[i - 1] + len[i - 2];
int op = len[i - 1] % 3;
for (int p = 0; p < 3; ++p)
dp[i][p] = dp[i - 1][p]
+ dp[i - 2][(p - op + 3) % 3];
}
}
int solve1(int n, int p) {
string s = "0", nxt = "01", tmp;
while ((int)nxt.length() < n) {
tmp = nxt + s;
s = nxt;
nxt = tmp;
}
int ans = 0;
for (int i = p; i < n; i += 3)
ans += nxt[i] - '0';
return ans;
}
int value(int pos) {
if (pos <= 1) return pos;
int k = 0;
while (len[k + 1] <= pos) ++k;
return value(pos - len[k]);
}
int solve2(int n, int p) {
int ans = 0;
for (int i = p; i < n; i += 3)
ans += value(i);
return ans;
}
ll solve3(ll n, int p) {
int k = 0;
ll ans = 0;
while (len[k + 1] <= n) ++k;
for (; k >= 0; --k) {
if (len[k] > n) continue;
ans += dp[k][p];
n -= len[k];
p = (p - len[k] % 3 + 3) % 3;
}
return ans;
}
int main() {
ll n;
int p;
cin >> n >> p;
init();
if (n <= 1000000)
cout << solve1((int)n, p) << ' '
<< solve2((int)n, p) << ' '
<< solve3(n, p) << '\n';
else
cout << solve3(n, p) << '\n';
return 0;
}