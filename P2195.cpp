#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=3e5+5;
struct bcj{
    vector<ll> fa;
    bcj(ll len){
        fa.reserve(len+1);
        fa.resize(len+1);
        for(int i=1;i<=len;i++) fa[i]=i;
    }
    ll find(ll x){
        if(x==fa[x]) return x;
        return fa[x]=find(fa[x]);
    }
};
ll n,m,q,ans,k;
vector<ll> g[N];
void dfs(ll x,ll fa,ll dis){
    if(dis>ans){
        k=x;
        ans=dis;
    }
    for(auto i:g[x]){
        ll v=i;
        if(v==fa) continue;
        dfs(v,x,dis+1);
    }
}
void solve(){
    cin>>n>>m>>q;
    bcj a(n);
    for(int i=1;i<=m;i++){
        ll u,v;
        cin>>u>>v;
        a.fa[a.find(u)]=a.find(v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=q;i++){
        ll op,x,y;
        cin>>op>>x;
        if(op==1){
            dfs(x,0,0);
            
        }
    }
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