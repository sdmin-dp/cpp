#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=5e5+5;
ll n,m,idx;
vector<ll> g[N];
ll dfn[N],low[N];
vector<pair<ll,ll>> bridge;
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
                low[x]=min(low[x],dfn[i]);
            }
        }
    }
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        ll x,y;cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
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