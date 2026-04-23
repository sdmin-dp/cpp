#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=30+5;
ll n;
ll dis[N];
ll dp[N][N];
ll root[N][N];
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>dis[i];
        root[i][i]=i;
        dp[i][i]=dis[i];
    }
    for(int len=2;len<=n;len++){
        for(int i=1;i<=n-len+1;i++){
            ll j=i+len-1;
            for(int k=i;k<=j;k++){
                if(max(dp[i][k-1],1ll)*max(dp[k+1][j],1ll)+dis[k]>dp[i][j]){
                    root[i][j]=k;
                    dp[i][j]=max(dp[i][k-1],1ll)*max(dp[k+1][j],1ll)+dis[k];
                }
            }
        }
    }
    cout<<dp[1][n];
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