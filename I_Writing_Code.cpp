#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=5e2+5;
ll n,m,b,mod;
ll bug[N];
ll dp[N][N];
void solve(){
    cin>>n>>m>>b>>mod;
    for(int i=1;i<=n;i++) cin>>bug[i];
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=bug[i];k<=b;k++){
                dp[j][k]=(dp[j][k]+dp[j-1][k-bug[i]])%mod;
            }
        }
    }
    ll ans=0;
    for(int k=0;k<=b;k++) ans=(ans+dp[m][k])%mod;
    cout<<ans;
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
