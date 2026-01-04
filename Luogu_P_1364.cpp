#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e2+5;
ll n;
ll a[N];
ll dis[N][N];
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dis[i][j]=1e9;
        }
        dis[i][i]=0;
    }
    for(int i=1;i<=n;i++){
        ll u,v;
        cin>>a[i]>>u>>v;
        if(u>0) dis[i][u]=dis[u][i]=1;
        if(v>0) dis[i][v]=dis[v][i]=1;
    }
    // floyd
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    ll mn=INT_MAX;
    for(int i=1;i<=n;i++){
        ll x=0;
        for(int j=1;j<=n;j++){
            x+=dis[i][j]*a[j];
        }
        mn=min(mn,x);
    }
    cout<<mn;
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