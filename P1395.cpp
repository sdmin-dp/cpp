#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=5e4+5;
ll n;
vector<ll> g[N];
ll len[N];
ll ans,ai;
ll dis[N];
void dfs(ll x,ll fa){
    for(auto i:g[x]){
        if(i==fa) continue;
        dfs(i,x);
        len[x]+=len[i];
        dis[x]+=dis[i]+len[i];
    }
}
void dfs2(ll x,ll fa){
    if(ans>=dis[x]){
        if(ans>dis[x]){
            ai=x;
        }else{
            ai=min(ai,x);
        }
        ans=dis[x];
    }
    for(auto i:g[x]){
        if(i==fa) continue;
        ll lenu=len[x],lenv=len[i],du=dis[x],dv=dis[i];
        len[x]-=len[i];
        dis[x]-=dis[i]+len[i];
        len[i]+=len[x];
        dis[i]+=dis[x]+len[x];
        dfs2(i,x);
        len[x]=lenu;
        len[i]=lenv;
        dis[x]=du;
        dis[i]=dv;
    }
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        len[i]=1;
        ll x,y;cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    ans=n*n;
    ai=n+1;
    dfs(1,0);
    dfs2(1,0);
    cout<<ai<<" "<<ans;
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