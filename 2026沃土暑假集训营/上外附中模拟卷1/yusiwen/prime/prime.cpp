#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
const ll mod=1e9+7;
ll n;
ll a[N];
ll cnt=0;
ll prime(ll x){
    ll ans=0;
    for(ll i=2;i*i<=x;i++){
        if(x%i==0){
            ans++;
            while(x%i==0) x/=i;
        }
    }
    if(x!=1) ans++;
    return ans;
}
void dfs(ll x,ll res){
    if(x==n+1){
        // cerr<<res<<" "<<cnt+prime(res)<<el;
        cnt=(cnt+prime(res))%mod;
        return;
    }
    dfs(x+1,res);
    dfs(x+1,res*a[x]);
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1,1);
    cout<<cnt;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("prime.in","r",stdin);
    freopen("prime.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}