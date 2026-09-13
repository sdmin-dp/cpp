#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=8000+5;
ll n,s,len;
ll a[N],sum[N];
void solve(){
    cin>>n>>s>>len;
    for(ll l=1;l<n;l++) cin>>a[l],sum[l]=sum[l-1]+a[l];
    ll ans=0;
    for(ll l=1;l<=s;l++){
        for(ll r=s;r<=n;r++){
            ll left=sum[s-1]-sum[l-1];
            ll right=sum[r-1]-sum[s-1];
            if(2*(left+right)-max(left,right)<=len) ans=max(ans,r-l+1);
        }
    }
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