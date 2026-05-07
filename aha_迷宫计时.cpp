#include<bits/stdc++.h>
using namespace std;

int n, m, t;
char maze[10][10];
bool vis[10][10];
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
int sx, sy, ex, ey;

// 改成 bool 类型，一旦找到答案立刻收工
bool dfs(int x, int y, int step) {
    // 1. 距离剪枝
    int dis = abs(x - ex) + abs(y - ey);
    int shenyu = t - step;
    if (dis > shenyu || (shenyu - dis) % 2 != 0) return false;

    // 2. 到达终点
    if (x == ex && y == ey) {
        return step == t; // 只有步数刚好等于 t 才叫真找到了
    }

    // 3. 继续探索
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && maze[nx][ny] != 'X' && !vis[nx][ny]) {
            vis[nx][ny] = 1;
            if (dfs(nx, ny, step + 1)) return true; // 如果深层找到了，立刻报喜并退出
            vis[nx][ny] = 0; // 回溯
        }
    }
    return false;
}

int main() {
    // 极其标准的读入方式，防死循环，防多读
    while (scanf("%d%d%d", &n, &m, &t) == 3 && (n || m || t)) {
        int can_walk = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                scanf(" %c", &maze[i][j]);
                if (maze[i][j] == 'S') { sx = i; sy = j; }
                else if (maze[i][j] == 'D') { ex = i; ey = j; }
                if (maze[i][j] != 'X') can_walk++; // 数数有多少地儿能踩
            }
        }

        // 强力剪枝：如果地皮不够踩，直接抬走，下一位
        if (can_walk < t + 1) { // +1 是因为算上了起点
            printf("NO\n");
            continue;
        }

        memset(vis, 0, sizeof(vis));
        vis[sx][sy] = 1; // 起点先踩塌

        if (dfs(sx, sy, 0)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}