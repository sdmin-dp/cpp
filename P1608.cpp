#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=2e3+5;
ll n,m;
ll g[N][N];
ll dis[N],sum[N];
void dijkstra(){
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
    q.push({0,1});
    memset(dis,0x3f,sizeof(dis));
    dis[1]=0;
    sum[1]=1;
    while(!q.empty()){
        auto x=q.top();
        q.pop();
        if(x.first>dis[x.second]) continue;
        for(int i=1;i<=n;i++){
            if(g[x.second][i]!=0x3f3f3f3f3f3f3f3f){
                if(dis[i]>x.first+g[x.second][i]){
                    sum[i]=sum[x.second];
                    dis[i]=x.first+g[x.second][i];
                    q.push({dis[i],i});
                }else if(dis[i]==x.first+g[x.second][i]){
                    sum[i]+=sum[x.second];
        
                }
            }
        }
    }
}
void solve(){
    cin>>n>>m;
    memset(g,0x3f,sizeof(g));
    for(int i=1;i<=m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        g[u][v]=min(w,g[u][v]);
        // g[v].push_back({u,w});
    }
    dijkstra();
    if(dis[n]==0x3f3f3f3f3f3f3f3f) cout<<"No answer"<<el;
    else cout<<dis[n]<<" "<<sum[n];
    //dfsd;
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
