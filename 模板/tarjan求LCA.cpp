#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=5e5+5;
ll n,m,root;
vector<ll> g[N];
vector<pair<ll,ll>> q[N];
ll ans[N],vis[N];
struct bcj{
    vector<ll> fa;
    void RESIZE(ll len){
        fa.reserve(len+1);
        fa.resize(len+1);
        for(int i=1;i<=len;i++) fa[i]=i;
    }
    ll find(ll x){
        if(x==fa[x]) return x;
        return fa[x]=find(fa[x]);
    }
};
bcj a;
void tarjan(ll x){
    vis[x]=1;
    for(auto i:g[x]){
        if(vis[i]) continue;
        tarjan(i);
        a.fa[i]=x;
    }
    for(auto i:q[x]){
        ll v=i.first,id=i.second;
        if(vis[v]==2) ans[id]=a.find(v);
    }
    vis[x]=2;
}
void solve(){
    cin>>n>>m>>root;
    a.RESIZE(n);
    for(int i=1;i<n;i++){
        ll u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=m;i++){
        ll u,v;
        cin>>u>>v;
        if(u==v) ans[i]=u;
        else{
            q[u].push_back({v,i});
            q[v].push_back({u,i});
        }
    }
    tarjan(root);
    for(int i=1;i<=m;i++) cout<<ans[i]<<el;
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