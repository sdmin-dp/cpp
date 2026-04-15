#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=5e4+5;
ll n;
vector<pair<ll,ll>> g[N];
ll len[N];
ll ans=0;
void dfs(ll x,ll fa){
    for(auto i:g[x]){
        ll v=i.first,w=i.second;
        if(v==fa) continue;
        dfs(v,x);
        len[x]+=len[v];
    }
}
void dfs2(ll u,ll fa){
    for(auto i:g[u]){
        ll v=i.first,w=i.second;
        if(v==fa) return;
        ll lenu=len[u],lenv=len[v];
        len[u]-=len[v];
        ans+=abs(len[u]-len[v])*w;
        dfs2(v,u);
        len[u]=lenu;
        len[v]=lenv;
    }
}
void solve(){
    cin>>n;
    for(int i=1;i<n;i++){
        len[i]=1;
        ll x,y,z;
        cin>>x>>y>>z;
        g[x].push_back({x,z});
        g[y].push_back({x,z});
    }
    len[n]=1;
    dfs(1,0);
    dfs2(1,0);
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