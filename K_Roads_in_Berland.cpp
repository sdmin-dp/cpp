#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=300+5;
ll n;
ll dis[N][N];
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>dis[i][j];        
        }
    }
    ll k;cin>>k;
    while(k--){
        ll u,v,w;
        cin>>u>>v>>w;
        if(dis[u][v]>w){
            dis[u][v]=w;
            dis[v][u]=w;
            for(int i=1;i<=n;i++){
                for(int j=i;j<=n;j++){
                    dis[i][j]=min({dis[i][j],dis[i][u]+dis[u][v]+dis[v][j],dis[i][v]+dis[v][u]+dis[u][j]});
                    dis[j][i]=dis[i][j];
                }
            }
        }
        ll ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                ans+=dis[i][j];
            }
        }
        cout<<ans/2<<" ";
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