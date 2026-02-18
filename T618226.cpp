#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
#define gcd __gcd
const ll N=1e5+5;

int count_coprime(int n_prime, int m_prime) {
    if (m_prime == 0) return 0;
    vector<int> factors;
    int temp = n_prime;
    for (int i = 2; i * i <= temp; i++) {
        if (temp % i == 0) {
            factors.push_back(i);
            while (temp % i == 0) temp /= i;
        }
    }
    if (temp > 1) factors.push_back(temp);
    int len = factors.size();
    int cnt = m_prime;
    for (int mask = 1; mask < (1 << len); mask++) {
        int product = 1, bits = 0;
        for (int i = 0; i < len; i++) {
            if (mask & (1 << i)) {
                product *= factors[i];
                bits++;
            }
        }
        if (bits & 1) cnt -= m_prime / product;
        else cnt += m_prime / product;
    }
    return cnt;
}
void solve(){
    int n, m;
    cin >> n >> m;
    
    map<int, int> freq;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        freq[x]++;
    }
    int G = 0;
    for (auto& p : freq) {
        G = gcd(G, p.second);
    }
    vector<int> divs;
    for (int d = 1; d * d <= n; d++) {
        if (n % d == 0) {
            divs.push_back(d);
            if (d != n / d) divs.push_back(n / d);
        }
    }
    int ans = 0;
    for (int d : divs) {
        if (d > m) continue;
        int g = n / d;
        if (G%g!=0) continue;
        int m_prime=m/d;
        if (m_prime==0) continue;
        ans+=count_coprime(g, m_prime);
    }
    cout<<ans<<el;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}