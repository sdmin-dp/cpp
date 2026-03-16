#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll N, M, K, P;
    if (!(cin >> N >> M >> K >> P)) return 0;

    set<pair<int, int>> cp_set, ps_set;
    vector<ll> countCP(M + 1, 0);
    vector<ll> countPS(M + 1, 0);

    for (int i = 0; i < P; ++i) {
        string type;
        int x, y;
        cin >> type >> x >> y;
        if (type == "CP") {
            if (cp_set.find({x, y}) == cp_set.end()) {
                cp_set.insert({x, y});
                countCP[y]++;
            }
        } else {
            if (ps_set.find({x, y}) == ps_set.end()) {
                ps_set.insert({x, y});
                countPS[x]++; // 这里的x是裤子编号，y是鞋子编号
            }
        }
    }

    ll total = N * M * K;
    ll minusCP = (ll)cp_set.size() * K;
    ll minusPS = (ll)ps_set.size() * N;
    
    ll plusIntersection = 0;
    for (int y = 1; y <= M; ++y) {
        plusIntersection += countCP[y] * countPS[y];
    }

    cout << total - minusCP - minusPS + plusIntersection << endl;

    return 0;
}
