#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

map<ll, ll> mp;

void solve() {
    ll n;
    cin >> n;
    vector<ll> a (n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    vector<ll> dp (100005, 0);
    dp[1] = mp[1];+
    for (int i = 2; i <= n; i++) {
        dp[i] = max (dp[i - 1], dp[i - 2] + (mp[i] * i));
    }
    cout << dp[100000] << " ";
}

int main() {
    ios::sync_with_stdio (false);
    cin.tie(nullptr), cout.tie(0);

    int T = 1; // cin >> T;
    while(T--) 
        solve();

    return 0;
}