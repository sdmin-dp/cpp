#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e5+5;
const ll inf=-1e12;
ll n;
vector<pair<ll,ll>> g[N];
ll ans,k,b,e,len;
ll pre[N];
vector<ll> path;
ll dis[N],odis[N];
bool inpath[N];
void dfs(ll x,ll fa,ll dis){
    
    if(dis>ans) k=x,ans=dis;
    for(auto i:g[x]){
        if(i.first!=fa){
            dfs(i.first,x,dis+i.second);
            pre[x]=fa;
        }
    }
}
void dfs2(ll x,ll num){
    if(num==path.size()) return;
    for(auto i:g[x]){
        if(i.first==path[num]){
            dis[i.first]=dis[x]+i.second;
            dfs2(i.first,num+1);
            return;
        }
    }
}
ll dfs3(ll x,ll fa,ll ds){
    ll res=0;
    for(auto i:g[x]){
        ll v=i.first;
        if(v!=fa&&!inpath[v]) res=max(res,dfs3(v,x,ds+i.second)+i.second);
    }
    return res;
}
void solve(){
    cin>>n;
    for(int i=1;i<n;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    ans=inf;
    dfs(1,0,0);
    b=k;
    ans=-1e12;
    dfs(k,0,0);
    e=k;
    ll cur=e;
    while(cur!=b){
        inpath[cur]=1;
        path.push_back(cur);
        cur=pre[cur];
    }
    inpath[b]=1;
    path.push_back(b);
    reverse(path.begin(),path.end());
    dfs2(path[0],1);
    for(auto i:path) odis[i]=dfs3(i,0,0);


    ll l=0,r=path.size()-1;

    for(ll i=0;i<path.size();i++)
        if(odis[path[i]]==ans-dis[path[i]])
            l=i;

    
    for(ll i=path.size()-1;i>=0;i--)
        if(odis[path[i]]==dis[path[i]])
            r=i;
    cout<<ans<<el<<r-l;
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