#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n;
ll color[N];
vector<ll> g[N];
ll ans=0;
void dfs(ll x,ll fa,ll step){
    ans=max(ans,step);
    for(auto i:g[x]){
        if(i==fa) continue;
        if(color[i]==color[x]) continue;
        dfs(i,x,step+1);
    }
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>color[i];
    for(int i=1;i<n;i++){
        ll u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        dfs(i,0,1);
    }
    cout<<ans;
}
int main(){
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