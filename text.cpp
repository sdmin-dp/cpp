#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

// 10000以内的数够用了
bool is_prime[10000];
int dist[10000]; // 记录从起点到这个数需要多少步

// 预处理：先把1000-9999之间的质数全部筛出来
void sieve() {
    fill(is_prime, is_prime + 10000, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < 10000; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j < 10000; j += i)
                is_prime[j] = false;
        }
    }
}

int bfs(int start, int end) {
    memset(dist, -1, sizeof dist); // -1表示还没走过
    queue<int> q;

    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        int t = q.front();
        q.pop();

        if (t == end) return dist[t];

        // 尝试改变每一位数字：千位、百位、十位、个位
        int p[4];
        p[0] = t / 1000;       // 千位
        p[1] = t / 100 % 10;   // 百位
        p[2] = t / 10 % 10;    // 十位
        p[3] = t % 10;         // 个位

        for (int i = 0; i < 4; i++) { // 枚举要改哪一位
            int old = p[i]; // 存一下原来的数，改完记得变回来
            for (int j = 0; j <= 9; j++) { // 枚举这一位变到几
                if (i == 0 && j == 0) continue; // 第一位不能是0
                
                p[i] = j;
                int next_num = p[0] * 1000 + p[1] * 100 + p[2] * 10 + p[3];
                
                // 如果是质数，而且之前没走过
                if (is_prime[next_num] && dist[next_num] == -1) {
                    dist[next_num] = dist[t] + 1;
                    q.push(next_num);
                }
            }
            p[i] = old; // 变回来，方便改下一位
        }
    }
    return -1; // 走不到就返回-1
}

int main() {
    sieve(); // 游戏开始前，先把质数表准备好
    int n;
    cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;
        int res = bfs(a, b);
        if (res == -1) cout << "Impossible" << endl;
        else cout << res << endl;
    }
    return 0;
}