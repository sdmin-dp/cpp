#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e2+5;
ll n,m;
ll dis[N][N];
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dis[i][j]=1e9;
        }
        dis[i][i]=0;
    }
    for(int i=1;i<=m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        dis[u][v]=w;
        dis[v][u]=w;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
     ll mx=0;
    bool flag=1;
    
    for(int i=1;i<=n;i++){
        if(dis[1][i]==1e9){
            flag=0;
            break;
        }
        mx=max(mx,dis[1][i]);
    }
    if(!flag){
        cout<<-1<<'\n';
    } else {
        cout<<mx<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("xxx.in","r",stdin);
    // freopen("xxx.out","w",stdout);
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}