#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+5;
ll n,a[105][105],dp[105][105];
ll f(ll i,ll j){
    if(i==n) return a[i][j];
    if(!dp[i][j]) return a[i][j]+max(f(i+1,j),f(i+1,j+1));
    return dp[i][j];
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++) cin>>a[i][j];
    }
    cout<<f(1,1);
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