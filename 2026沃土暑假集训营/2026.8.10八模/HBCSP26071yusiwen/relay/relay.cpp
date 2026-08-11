#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e5+5;
ll n,m;
ll a[N];
ll dp[N];
void solve(){
    cin>>m>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) dp[i]=-1;
    for(int i=1;i<=n;i++){
        for(int j=a[i];j<=m;j++){
            if(dp[j-a[i]]==-1) continue;
            dp[j]=max(dp[j],dp[j-a[i]]+1);
        }
    }
    cout<<dp[m];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("relay.in","r",stdin);
    freopen("relay.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}