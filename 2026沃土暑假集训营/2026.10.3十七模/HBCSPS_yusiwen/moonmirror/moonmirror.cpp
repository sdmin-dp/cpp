#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=5000+5;
ll n,k;
ll a[N];
ll dp[N][N];
ll mx=-1e12,mn=1e12;
bool check(ll x){
    memset(dp,0,sizeof(dp));
    for(ll i=1;i<=n;i++) dp[i][i]=1;
    for(ll len=2;len<=n;len++){
        for(ll l=1;l+len-1<=n;l++){
            ll r=l+len-1;
            dp[l][r]=min(dp[l][r-1],dp[l+1][r])+1;
            if(abs(a[r]-a[l])<=x){
                if(len>2) dp[l][r]=min(dp[l][r],dp[l+1][r-1]);
                else dp[l][r]=0;
            }
        }
    }
    return (dp[1][n]<=k);
}   
void erfen(){
    ll l=0,r=mx-mn+5,mid=0,ans=0;
    while(l<=r){
        mid=(l+r)/2;
        if(check(mid)){
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout<<ans;
}
void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);mn=min(mn,a[i]);
    }
    erfen();
}   
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("moonmirror.in","r",stdin);
    freopen("moonmirror.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}