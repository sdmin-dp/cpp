#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N = (1 << 20) + 5;
ll n, m;
bool vis[N];
void solve(){
    cin >> n >> m;
    for(ll i = 1; i <= n; i++){
        ll a;
        cin >> a;
        vis[a] = 1;
    }
    for(ll i = 19; i >= 0; i--){
        for(ll mask = (1 << 20) - 1; mask >= 0; mask--){
            if((mask >> i) & 1){
                if(vis[mask]) vis[mask ^ (1 << i)] = 1;
            }
        }
    }
    for(ll i = 1; i <= m; i++){
        ll x;
        cin >> x;
        if(x >= (1 << 20)) cout << "no"<<el;
        else if(vis[x]) cout<<"yes"<<el;
        else cout<<"no"<<el;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll T=1;
    while(T--){
        solve();
    }
    return 0;
}