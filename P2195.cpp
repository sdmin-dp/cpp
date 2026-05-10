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
ll dis[N];
bool vis[N];
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
ll get_d(int u){
    ans=-1e12;
    dfs(u,-1,0);
    ans=-1e12;
    dfs(k,-1,0);
    return ans;
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
    for(int i=1;i<=n;i++){
        int fi=a.find(i);
        if(!vis[fi]){
            dis[fi]=get_d(i);
            vis[fi]=1;
        }
    }
    for(int i=1;i<=q;i++){
        ll op,x,y;
        cin>>op>>x;
        if(op==1){
            cout<<dis[a.find(x)]<<el;
        }else{
            cin>>y;
            ll fx=a.fa[x],fy=a.fa[y];
            if(fx!=fy){
                a.fa[fx]=fy;
                dis[fy]=max({dis[fx],dis[fy],(dis[fx]+1)/2+(dis[fy]+1)/2+1});
            }
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