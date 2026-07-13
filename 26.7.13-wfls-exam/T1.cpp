#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e7+5;
ll l,r;
ll min_prime[N];
bool is_power[N];
vector<ll> prime;
void init(int n){
    is_power[1] = false;
    for(ll i=2; i<=n; i++){
        if(!min_prime[i]){
            min_prime[i] = i;
            is_power[i] = true;
            prime.push_back(i);
        }
        for(auto j:prime){
            if(i*j > n) break;
            min_prime[i*j] = j;
            if(i % j == 0){
                is_power[i*j] = (is_power[i] && (min_prime[i] == j));
                break;
            }
            is_power[i*j] = false;
        }
    }
}
void solve(){
    cin >> l >> r;
    init(r);
    ll ans = 0;
    for(int i = l; i <= r; i++){
        if(i == 1) continue;
        if(is_power[i]) ans += min_prime[i];
        else ans += 1;
    }    
    cout << ans << el;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll T=1;
    while(T--){
        solve();
    }
    return 0;
}