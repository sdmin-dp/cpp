#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,m,b,e;
vector<pair<ll,ll>> g[N];
ll a[N];
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
            ans=min(a[e]-a[b]+stp,ans);
        }
        for(auto v:g[u]){
            if(!vis[v.first]){
                vis[v.first]=1;
                q.push({v.first,stp+1});
            }
        }
    }
    if(ans==INT_MAX) cout<<"No solution";
    else cout<<ans;
}
void solve(){
    cin>>n>>m>>b>>e;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=1;i<=m;i++){
        ll u,v;
        cin>>u>>v;
        g[u].push_back({v,1});
    }
    bfs();
}

int main() {
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