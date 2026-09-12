#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,m,deg[N];
bool vis[N];
vector<ll> g[N],nodes;
void dfs(ll u){
    vis[u]=1;
    nodes.push_back(u);
    for(auto v:g[u])if(!vis[v])dfs(v);
}
void solve(){
    while(cin>>n>>m){
        for(int i=1;i<=n;i++){g[i].clear();vis[i]=0;deg[i]=0;}
        for(int i=1;i<=m;i++){
            ll x,y;cin>>x>>y;
            g[x].push_back(y);g[y].push_back(x);
            deg[x]++;deg[y]++;
        }
        ll ans=0;
        for(int i=1;i<=n;i++){
            if(!vis[i]&&deg[i]>0){
                nodes.clear();
                dfs(i);
                ll cnt=0;
                for(auto u:nodes)if(deg[u]%2==1)cnt++;
                if(cnt==0)ans++;
                else ans+=cnt/2;
            }
        }
        cout<<ans<<el;
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
