#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e2+5;
ll n,m;
vector<ll> g[N];
ll match[N];
bool vis[N];
bool dfs(ll u){
    for(auto i:g[u]){
        if(!vis[i]){
            vis[i]=1;
            if(!match[i]||dfs(match[i])){
                match[i]=u;
                return 1;
            }
        }
    }
    return 0;
}
void solve(){
    cin>>m>>n;
    ll u,v;
    while(cin>>u>>v){
        if(u==-1&&v==-1) break;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ll cnt=0;
    vector<pair<ll,ll>> ans;
    for(int i=1;i<=m;i++){
        memset(vis,0,sizeof(vis));
        if(dfs(i)) cnt++;
    }
    for(int i=m+1;i<=n;i++) if(match[i]!=0) ans.push_back({i,match[i]});
    cout<<cnt<<el;
    for(auto &i:ans) cout<<i.first<<" "<<i.second<<el;
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