#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e5+5;
const ll mod=1e9+7;
ll n,a,b,c;
ll dp[N];
void solve(){
    cin>>n>>a>>b>>c;
    dp[c]=1;
    for(int i=c+1;i<=n;i++){
        ll x,y;
        if(i-a<=c) x=1;
        else x=dp[i-a];
        if(i-b<=c) y=1;
        else y=dp[i-b];
        dp[i]=(x+y)%mod;
    }
    cout<<dp[n]%mod;
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