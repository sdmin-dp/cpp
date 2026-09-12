#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
unordered_map<ll,ll> mp;
void fjzys(ll x){
    for(ll i=2;i<=x;i++){
        while(x%i==0){
            x/=i;
            mp[i]++;
        }
    }
}
ll n;
void solve(){
    cin>>n;
    fjzys(n);
    ll ans=0;
    for(auto i:mp){
        ll x=i.first,y=i.second;
        for(int j=1;j<=y;j++){
            ans++;
            y-=j;
        }
    }
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("xxx.in","r",stdin);
    // freopen("xxx.out","w",stdout);
    ll T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}