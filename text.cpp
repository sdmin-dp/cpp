#include <bits/stdc++.h>
using namespace std;
bool is_prime[10000];
int dist[10000];
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
    memset(dist, -1, sizeof dist);
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    while (!q.empty()) {
        int t = q.front();
        q.pop();

        if (t == end) return dist[t];
        int p[4];
        p[0] = t / 1000;
        p[1] = t / 100 % 10;
        p[2] = t / 10 % 10;
        p[3] = t % 10;
        for (int i = 0; i < 4; i++) {
            int old = p[i];
            for (int j = 0; j <= 9; j++) {
                if (i == 0 && j == 0) continue;
                p[i] = j;
                int next_num = p[0] * 1000 + p[1] * 100 + p[2] * 10 + p[3];
                if (is_prime[next_num] && dist[next_num] == -1) {
                    dist[next_num] = dist[t] + 1;
                    q.push(next_num);
                }
            }
            p[i] = old;
        }
    }
    return -1;
}
void solve(){
    sieve();
    ll n;
    cin>>n;
    while(n--){
        int a, b;
        cin >> a >> b;
        int res = bfs(a, b);
        if (res == -1) cout << "Impossible" << endl;
        else cout << res << endl;
    }
}
int main() {
    
}