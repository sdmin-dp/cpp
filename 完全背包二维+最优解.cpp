#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e4+5;
ll n,m,w[N],v[N],dp[N][N];
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>w[i]>>v[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(j<w[i]) dp[i][j]=dp[i-1][j];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-w[i]]+v[i]);
        }
    }
    cout<<dp[n][m]<<endl;
    map<ll,ll> mp;
    for(int i=n;i>=1;i++){
        while(dp[i][m]!=dp[i-1][m]){
            mp[i]++;
            m-=w[i];
        }
    }
    for(auto i:mp) cout<<i.first<<" "<<i.second<<'\n';
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