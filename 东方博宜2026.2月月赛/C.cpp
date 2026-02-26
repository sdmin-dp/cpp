#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'

const int MAX = 1005;
int n, m;
int g[MAX][MAX];
int dist[MAX][MAX][2]; // 0: 无许可, 1: 有许可

struct Node {
    int x, y, p;
};

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
            dist[i][j][0] = dist[i][j][1] = -1;
        }
    }

    queue<Node> q;
    // 起点处理：注意起点也可能是补给点或快速通道
    int start_p = 0;
    if (g[1][1] == 0) { cout << -1 << el; return; }
    if (g[1][1] == 2) start_p = 1;
    if (g[1][1] == 4) start_p = 0; // 进入4立即失效
    if (g[1][1] == 3 && start_p == 0) { cout << -1 << el; return; }

    dist[1][1][start_p] = 0;
    q.push({1, 1, start_p});

    while (!q.empty()) {
        Node curr = q.front();
        q.pop();

        if (curr.x == n && curr.y == m) {
            cout << dist[curr.x][curr.y][curr.p] << el;
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];

            if (nx < 1 || nx > n || ny < 1 || ny > m || g[nx][ny] == 0) continue;

            int np = curr.p;
            int nstep = dist[curr.x][curr.y][curr.p] + 1;

            // 处理类型 3：无许可不能进
            if (g[nx][ny] == 3 && np == 0) continue;

            // 处理类型 2：获得许可
            if (g[nx][ny] == 2) np = 1;

            // 处理类型 4：快速通道滑行
            if (g[nx][ny] == 4) {
                np = 0; // 许可失效
                int tx = nx, ty = ny;
                // 自动前进逻辑
                while (true) {
                    int next_tx = tx + dx[i];
                    int next_ty = ty + dy[i];
                    // 无法继续前进的情况：越界、类型0、或类型3(因为此时无许可)
                    if (next_tx < 1 || next_tx > n || next_ty < 1 || next_ty > m) break;
                    if (g[next_tx][next_ty] == 0 || g[next_tx][next_ty] == 3) break;
                    
                    // 成功滑入下一格
                    tx = next_tx;
                    ty = next_ty;
                    nstep++;
                    // 如果滑到了非快速通道，停止滑行并判断属性
                    if (g[tx][ty] != 4) {
                        if (g[tx][ty] == 2) np = 1;
                        break;
                    }
                }
                nx = tx; ny = ty;
            }

            if (dist[nx][ny][np] == -1 || dist[nx][ny][np] > nstep) {
                dist[nx][ny][np] = nstep;
                q.push({nx, ny, np});
            }
        }
    }

    cout << -1 << el;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
