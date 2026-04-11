#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=2e5+5;
ll n;
vector<pair<ll,ll>> g[N];
bool inpath[N];
vector<ll> path;
ll ans=-1e12,k;
ll pre[N];
ll b,e;
ll odis[N],dis[N];
void dfs(ll x,ll fa,ll ds){
    dis[x]=ds;
    if(ds>ans){
        k=x;
        ans=ds;
    }
    for(auto i:g[x]){
        ll v=i.first;
        if(v==fa) continue;
        pre[v]=x;
        dis[v]=ds+i.second;
        dfs(v,x,ds+i.second);
    }
}
//踢边：找出这个点不走直径可以走的最远的路程（一个即可）other_dis->odis
//然后从这个点到第一个顶点的距离（到另外一边直接一减就行）dis
ll dfs_search(ll x,ll fa,ll ds){
    ll res=0;
    for(auto i:g[x]){
        ll v=i.first;
        if(v!=fa&&!inpath[v]) res=max(res,dfs_search(v,x,ds+i.second)+i.second);
    }
}
void solve(){
    cin>>n;
    for(int i=1;i<n;i++){
        ll x,y,z;
        cin>>x>>y>>z;
        g[x].push_back({y,z});
        g[y].push_back({x,z});
    }
    dfs(1,0,0);
    b=k;
    ans=-1e12;
    dfs(k,0,0);
    e=k;
    ll cur=e;
    while(cur!=b){
        path.push_back(cur);
        inpath[cur]=1;
        cur=pre[cur];
    }
    inpath[b]=1;
    path.push_back(b);
    for(auto i:path) odis[i]=dfs_search(i,0,0);
    ll l=0,r=path.size()-1;
    for(ll i=0;i<path.size();i++){
        if(odis[path[i]]==dis[path[i]]){
            l=i;
        }
    }
    for(ll i=path.size()-1;i>=0;i--){
        if(odis[path[i]]==dis[path[i]]){
            r=i;
        }
    }
    cout<<r-l+1;
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