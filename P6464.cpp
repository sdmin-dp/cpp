#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e2+5;
ll n,m;
ll dis[N][N];
void solve(){
    cin>>n>>m;
    memset(dis,0x3f,sizeof dis);
    for(int i=1;i<=n;i++) dis[i][i]=0;
    for(int i=1;i<=m;i++){
        ll u,v,w;cin>>u>>v>>w;
        dis[u][v]=w;
        dis[v][u]=w;
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(dis[i][k]+dis[k][j]<dis[i][j])
                    dis[i][j]=dis[i][k]+dis[k][j];
    ll sum=0,ans=0;
    ll idx=0,idy=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            // cerr<<dis[i][j]<<" ";
            if(dis[i][j]>=0x3f3f3f3f3f3f3f3f) continue;
            if(dis[i][j]>ans){
                ans=dis[i][j];
                idx=i,idy=j;
            }
            
        }
        // cerr<<el;
    }
    dis[idx][idy]=0;
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(dis[i][k]+dis[k][j]<dis[i][j])
                    dis[i][j]=dis[i][k]+dis[k][j];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            // cerr<<dis[i][j]<<" ";
            if(dis[i][j]>=0x3f3f3f3f3f3f3f3f) continue;
            sum+=dis[i][j];
        }
        // cerr<<el;
    }
    // cerr<<sum/2<<" "<<ans;
    cout<<sum/2-ans;
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