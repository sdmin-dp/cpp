#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll k,n,m;
ll a[N];
vector<pair<ll,ll>> g[N];
ll dis[N];
void SPFA(ll b){
    memset(dis,0x7f,sizeof(dis));
    dis[b]=0;
    queue<ll> q;
    q.push(b);
    while(!q.empty()){
        auto x=q.front();
        q.pop();
        for(auto i:g[x]){
            if(dis[i.first]>dis[x]+i.second){
                dis[i.first]=dis[x]+i.second;
                q.push(i.first);
            }
        }
    }
}
void solve(){
    cin>>k>>n>>m;
    for(int i=1;i<=k;i++) cin>>a[i];
    for(int j=1;j<=m;j++){
        ll u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    ll ans=INT_MAX;
    for(int i=1;i<=n;i++){
        SPFA(i);
        ll sum=0;
        for(int j=1;j<=k;j++){
            sum+=dis[a[j]];
        }
        ans=min(ans,sum);
    }
    cout<<ans;
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