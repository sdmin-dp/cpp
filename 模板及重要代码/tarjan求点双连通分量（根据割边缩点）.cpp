#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,m;
vector<ll> g[N];
ll dfn[N],low[N];
ll idx;
vector<pair<ll,ll>> bridge;
ll color[N];
void dfs(ll x,ll fa){
    ll child=0;
    dfn[x]=++idx;
    low[x]=idx;
    for(auto i:g[x]){
        if(dfn[i]==0){
            dfs(i,x);
            low[x]=min(low[i],low[x]);
            if(low[i]>dfn[x]) bridge.push_back({x,i});
        }
        else if(x!=fa) x=min(low[x],dfn[i]);
    }
}
void change(ll x){
    
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        ll x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++) if(!color[i]) change(i);
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