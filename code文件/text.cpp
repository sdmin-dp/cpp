
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const ll N = 1e3 + 10;

ll n, k, b[N];

void solve() {
    cin >> n >> k;

    ll mx = 0, need = k / 2, ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        mx = max (mx, b[i]);
    }
    
    for (int x = 1; x <= mx; x++) {
        ll cnt = 0;
        vector<ll> v;
        for (ll i = 1; i <= n; i++) {
            cnt += (b[i] / x);
            v.push_back (b[i] % x);
        }

        if (cnt < need)
            continue;
        
        ll now = 0;
        if (cnt >= k)
            now = need * x;
        else {
            now = (cnt - need) * x;
            ll needd = k - cnt;
            sort (v.begin (), v.end (), greater<ll> ());
            for (int i = 0; i < needd; i++)
                now += v[i];
        }
        ans = max (ans, now);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio (false);
    cin.tie(nullptr), cout.tie(0);

    // freopen ("badge.in", "r", stdin);
    // freopen ("badge.out", "w", stdout);

    int T = 1; // cin >> T;
    while(T--) 
        solve();

    return 0;
}