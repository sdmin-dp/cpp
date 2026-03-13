#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,m;
vector<ll> g[N],ng[N];
ll dfn[N],low[N];
ll idx;
vector<pair<ll,ll>> bridge;
map<pair<ll,ll>,bool> mp;
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
/*
染色n步走：
1.将这个东西染色（用新的编号）
2.将他连着的所有没染色的边染色
3.注意不能走割边
*/
void change(ll x){
    color[x]=idx;
    for(auto i:g[x]) if(!mp[{min(x,i),max(x,i)}]&&!color[i]) change(i);
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
    for(auto &i:bridge) if(i.first>i.second) swap(i.first,i.second);
    for(auto &i:bridge) mp[{i.first,i.second}]=1;
    idx=0;
    for(int i=1;i<=n;i++){
        if(!color[i]){
            idx++;
            change(i);
        }
    }
    for(auto i:bridge){
        ng[color[i.first]].push_back(color[i.second]);
        ng[color[i.second]].push_back(color[i.first]);
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