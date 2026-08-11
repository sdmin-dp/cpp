#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=4e3+5;
ll n,q;
ll a[N];
bool ispal[N][N];
ll dp[N][N];
void solve(){
    cin>>n>>q;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        dp[i][i]=1;
        ispal[i][i]=1;
    }
    for(ll len=2;len<=n;len++){
        for(ll l=1;l+len-1<=n;l++){
            ll r=l+len-1;
            if(a[l]==a[r]&&(ispal[l+1][r-1]||r-l+1==2)) ispal[l][r]=1;
        }
    }
    for(ll len=2;len<=n;len++){
        for(ll l=1;l+len-1<=n;l++){
            ll r=l+len-1;
            dp[l][r]=dp[l+1][r]+dp[l][r-1]-dp[l+1][r-1]+ispal[l][r];
        }
    }
    while(q--){
        ll l,r;
        cin>>l>>r;
        cout<<dp[l][r]<<el;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("mirror.in","r",stdin);
    freopen("mirror.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}