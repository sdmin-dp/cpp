#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=5e5+5;
ll n,m,q;
ll w[N];
//地铁线路数、地铁站数、以及出行计划数
//其中aij表示第i条线路经过的第j个地铁站,tij表示从该地铁站的站厅走到第i条线路的站台需要的时间
vector<pair<ll,ll>> g[N+500];
ll color[N];
ll ng[505][505];
void solve(){
    cin>>n>>n>>m>>q>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        ll k;cin>>k;
        for(int j=1;j<=k;j++){
            ll u,v;
            cin>>u>>v;
            g[i+m].push_back({u,v});
            g[u].push_back({i+m,v});
        }
    }
    memset(ng,0x3f,sizeof ng);
    for(int i=1;i<=n;i++) ng[i][i]=0;
    for(int i=1;i<=m;i++)
        for(auto j:g[i])
            for(auto k:g[i])
                if(j.first!=k.first)
                    ng[j.first-m][k.first-m]=j.second+k.second;
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                ng[i][j]=min(ng[i][j],ng[i][k]+ng[k][j]);
    for(int i=1;i<=q;i++){
        ll u,v;
        cin>>u>>v;
        ll ans=1e17;
        for(auto i:g[u])
            for(auto j:g[v])
                ans=min(ans,w[u]+w[v]+i.second+j.second+ng[i.first-m][j.first-m]);
        cout<<ans<<el;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}