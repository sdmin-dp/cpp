#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n;
ll a[N],b[N],c[N];
ll dp[N][2][2][4];//第i项，走左/右边，用/没用飞羽，现在连续几次不换边
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=2;i<=n;i++) cin>>c[i];
    dp[1][0][0][1]=a[1];dp[1][1][0][1]=b[1];
    for(int i=2;i<=n;i++){
        
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("skyway.in","r",stdin);
    // freopen("skyway.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}