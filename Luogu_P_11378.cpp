#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n;
ll a[N];
vector<ll> g[N];
ll vis[N];
ll dfs(ll x){
    if(vis[x]!=0) return vis[x];
    ll cnt=0;
    for(auto i:g[x]){
        if(a[x]>a[i]){
            cnt+=dfs(i);
        }
    }
    return vis[x]=cnt+1;
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<n;i++){
        ll u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        ll k=dfs(i);
        ans=max(ans,k);
        cerr<<k<<" ";
    }
    cout<<ans;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}