#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=5e5+5;
ll n,m,idx;
vector<ll> g[N];
ll dfn[N],low[N];
vector<pair<ll,ll>> bridge;
map<pair<ll,ll>,bool> mp;
ll color[N];
void dfs(ll x,ll fa){
    low[x]=dfn[x]=++idx;
    bool flag=0;
    for(auto i:g[x]){
        if(!dfn[i]){
            dfs(i,x);
            low[x]=min(low[x],low[i]);
            if(low[i]>dfn[x]) bridge.push_back({min(x,i),max(x,i)});
        }
        else if(i==fa){
            if(!flag){
                flag=1;
                continue;
            }else{
                low[x]=min(low[x],dfn[i]);
            }
        }else{
            low[x]=min(low[x],dfn[i]);
        }
    }
}
void change(ll x){
    color[x]=idx;
    for(auto i:g[x]) if(!mp[{min(x,i),max(x,i)}]&&!color[i]) change(i);
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        ll x,y;cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i=1;i<=n;i++) if(!dfn[i]) dfs(i,0);
    for(auto &i:bridge) mp[{i.first,i.second}]=1;
    idx=0;
    for(int i=1;i<=n;i++){
        if(!color[i]){
            idx++;
            change(i);
        }
    }
    for(int i=1;i<=idx;i++){
        
        for(int j=1;j<=n;j++){
            if(color[j]==i){

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