#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n,m,b,e;
vector<ll> g[N];
ll dot[N];
void bfs(){
    ll ans=INT_MAX;
    queue<pair<ll,ll>> q;
    q.push({b,0});
    vector<ll> vis(n+1,0);
    vis[b]=1;
    while(!q.empty()){
        ll u=q.front().first;
        ll stp=q.front().second;
        q.pop();
        if(u==e){
            ans=min(dot[e]-dot[b]+stp,ans);
        }
        for(auto v:g[u]){
            if(!vis[v]){
                vis[v]=1;
                q.push({v,stp+1});
            }
        }
    }
    if(ans==INT_MAX) cout<<"No solution";
    else cout<<ans;
}
void solve(){
    cin>>n>>m>>b>>e;b++;e++;
    for(int i=1;i<=n;i++) cin>>dot[i];
    for(int i=1;i<=m;i++){
        ll u,v;
        cin>>u>>v;
        u++;v++;
        g[u].push_back(v);
    }
    bfs();
    // if(dis[e]==inf) cout<<"No solution";
    // else cout<<dis[e];
    // for(int i=1;i<=n;i++) cerr<<dis[i]<<" ";
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