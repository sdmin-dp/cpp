#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=20+5;
const ll inf=1e12;
ll n;
ll dp[(1<<20)+2][N];
ll g[N][N];
void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>g[i][j];
        }
    }
    for(int i=1;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            dp[i][j]=inf;
        }
    }
    dp[1][0]=0;
    for(int i=1;i<(1<<n);i++){
        for(int u=0;u<n;u++){
            if(i&(1<<u)){  
                for(int v=0;v<n;v++){
                    ll tv=1<<v;
                    if((i&(1<<v))&&v!=u){
                        ll j=i^tv;
                        dp[i][v]=min(dp[i][v],dp[j][u]+g[u][v]);
                    }
                }
            }
        }
    }
    ll ans=inf;
    for(int i=0;i<n;i++){
        ans=min(ans,dp[(1<<n)-1][i]+g[i][0]);
    }
    cout<<ans<<el;
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