#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 1505;

ll n;
ll ax, ay, bx, by;
char c[N][N];
ll dis[N][N];
ll dx[] = {1, 1, -1, -1}, dy[] = {1, -1, 1, -1};

void bfs() {
    queue<pair<ll, ll>> q;
    memset(dis, -1, sizeof(dis));
    dis[ax][ay] = 0;
    q.push({ax, ay});
    while(!q.empty()) {
        auto t = q.front(); q.pop();
        ll x = t.first, y = t.second;
        if(x == bx && y == by) {
            cout << dis[x][y] << '\n';
            return;
        }
        for(int dir = 0; dir < 4; dir++) {
            ll nx = x + dx[dir], ny = y + dy[dir];
            while(nx >= 1 && nx <= n && ny >= 1 && ny <= n && c[nx][ny] == '.') {
                if(dis[nx][ny] == -1) {
                    dis[nx][ny] = dis[x][y] + 1;
                    q.push({nx, ny});
                }
                else if(dis[nx][ny] <= dis[x][y]) break;
                nx += dx[dir], ny += dy[dir];
            }
        }
    }
    cout << -1 << '\n';
}

void solve() {
    cin >> n >> ax >> ay >> bx >> by;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> c[i][j];
    bfs();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(0);

    int T = 1; // cin >> T;
    while(T--) 
        solve();

    return 0;
}
