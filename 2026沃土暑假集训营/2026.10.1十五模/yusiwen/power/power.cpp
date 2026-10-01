#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2000+5;
ll n;
pair<ll,ll> a[N];
map<ll,ll> mp[N];
map<ll,ll> prime(ll x){
    map<ll,ll> mp;
    ll k=a[x].first;
    for(ll i=2;i*i<=k;i++){
        if(k%i==0){
            ll cnt=0;
            while(k%i==0){
                cnt++;
                k/=i;
            }
            mp[i]=cnt*a[x].second;
        }
    }
    if(k>1){
        mp[k]=a[x].second;
    }
    return mp;
}
bool check(ll x,ll y){
    //判断a[x]是不是a[y]的因数。
    for(auto i:mp[x]){
        ll t1=i.second;
        ll t2=mp[y][i.first];
        if(t2<t1) return 0;
    }
    return 1;
}
void solve(){
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i].first>>a[i].second;
        mp[i]=prime(i);
    }
    ll ans=0;
    for(ll i=1;i<=n;i++){
        for(ll j=i+1;j<=n;j++){
            if(check(i,j)||check(j,i)){
                ans++;
                // cerr<<i<<" "<<j<<el;
            }
        }
    }
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("power.in","r",stdin);
    freopen("power.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}