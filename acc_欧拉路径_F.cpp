#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=2005;
const ll M_MAX=50;
vector<pair<ll,ll>> g[M_MAX];
ll deg[M_MAX];
bool vis[N];
vector<ll> ans;
void dfs(ll u){
    for(auto &edge:g[u]){
        ll id=edge.first;
        ll v=edge.second;
        if(!vis[id]){
            vis[id]=1;
            dfs(v);
            ans.push_back(id);
        }
    }
}
void solve(){
    ll u,v,w;
    while(cin>>u>>v){
        for(int i=0;i<M_MAX;i++) g[i].clear();
        memset(deg,0,sizeof(deg));
        memset(vis,0,sizeof(vis));
        ans.clear();
        ll start=min(u,v);
        auto add_edge=[&](ll u,ll v,ll w){
            g[u].push_back({w,v});
            g[v].push_back({w,u});
            deg[u]++;deg[v]++;
        };
        cin>>w;
        add_edge(u,v,w);
        while(cin>>u>>v&&u+v){
            cin>>w;
            add_edge(u,v,w);
        }
        bool ok=1;
        for(int i=1;i<M_MAX;i++){
            if(deg[i]%2){
                ok=0;break;
            }
        }
        if(!ok){
            cout<<"Round trip does not exist."<<el;
            continue;
        }
        for(int i=1;i<M_MAX;i++) sort(g[i].begin(),g[i].end());
        dfs(start);
        for(int i=ans.size()-1;i>=0;i--){
            cout<<ans[i]<<(i==0?"":" ");
        }
        cout<<el;
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
