#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e2+5;
ll p,f,c;
ll a[N];
ll dp[N][N];
void solve(){
    cin>>p>>f>>c;
    for(int i=1;i<=f;i++){
        cin>>a[i];
    }
    for(int i=1;i<=p;i++){
        for(int j=1;j<=p;j++){
            dp[i][j]=1e9;
        }
        dp[i][i]=0;
    }
    for(int i=1;i<=c;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        dp[u][v]=w;
        dp[v][u]=w;
    }
    for(int k=1;k<=p;k++){
        for(int i=1;i<=p;i++){
            for(int j=1;j<=p;j++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
    ll ans=0,mn=1e9;
    for(int i=1;i<=p;i++){
        ll sum=0;
        for(int j=1;j<=f;j++){
            sum+=dp[i][a[j]];
        }
        if(sum<mn){
            mn=sum;
            ans=i;
        }
    }
    cout<<ans<<'\n';
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