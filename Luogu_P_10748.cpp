#include <iostream>
using namespace std;

int cnt[500005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k, m;
    cin >> n >> k >> m;
    
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
    }
    
    int x;
    for (int i = 0; i < n * k; i++) {
        cin >> x;
        cout << ++cnt[x] << " ";
    }
    
    return 0;
}
