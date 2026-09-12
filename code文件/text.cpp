#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2000+5;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n,h,l,r;
ll a[N];
ll dp[N][N];
void solve(){
    cin>>n>>h>>l>>r;
    for(int i=1;i<=n;i++) cin>>a[i];
    memset(dp,0x3f,sizeof(dp));
    for(int i=0;i<h;i++) dp[0][i]=0;
    ll sum=0;
    for(int i=1;i<=n;i++){
        sum+=a[i];
        sum%=h;
        ll j=((sum+h)-i)%h;
        bool flag=1;
        while(flag){
            if(j==sum) flag=0;
            if(l<=j&&j<=r){
                if(dp[i-1][(j+h-a[i])%h]<inf)
                    dp[i][j]=0,dp[i][j]=max(dp[i][j],dp[i-1][((j+h)-a[i])%h]+1);
                if(a[i]-1>=0&&dp[i-1][(j+h-a[i]+1)%h]<inf)
                    dp[i][j]=0,dp[i][j]=max(dp[i][j],dp[i-1][((j+h+1)-a[i])%h]+1);
            }
            else{
                // cerr<<i<<" "<<j<<" "<<dp[i-1][((j+h)-a[i])%h]<<el;
                if(dp[i-1][(j+h-a[i])%h]<inf)
                    dp[i][j]=0,dp[i][j]=max(dp[i][j],dp[i-1][((j+h)-a[i])%h]);
                if(a[i]-1>=0&&dp[i-1][(j+h-a[i]+1)%h]<inf)
                    dp[i][j]=0,dp[i][j]=max(dp[i][j],dp[i-1][((j+h+1)-a[i])%h]);
            }
            j=(j+1)%h;
        }
    }
    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<h;j++){
    //         if(dp[i][j]==inf) cout<<"inf"<<" ";
    //         else cout<<setw(3)<<dp[i][j]<<" ";
    //     }
    //     cout<<el;
    // }
    ll ans=0;
    for(int j=l;j<=r;j++){
        if(dp[n][j]>=inf) continue;
        ans=max(ans,dp[n][j]);
    }
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("nightlog.in","r",stdin);
    freopen("nightlog.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}