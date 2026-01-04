#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=9+5;
ll n;
pair<ll,ll> a[N];
bool vis[N];
ll ans=1e18;
void dfs(ll x,ll step,ll id){
    if(x==n+1){
        ans=min(ans,step);
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            ll l=max(a[id].second,a[i].first)+step+1;
            if(x==1) l=1;
            vis[i]=1;
            dfs(x+1,l,i);
            vis[i]=0;
        }
    }
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].first;
    for(int i=1;i<=n;i++) cin>>a[i].second;
    dfs(1,0,0);
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("xxx.in","r",stdin);
    // freopen("xxx.out","w",stdout);
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}