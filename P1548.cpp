#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,m;
void solve(){
    cin>>n>>m;
    ll ans1=0,ans2=0;
    for(ll i=1;i<=min(n,m);i++)
        ans1+=(n-i+1)*(m-i+1);
    for(ll i=1;i<=n;i++)
        for(ll j=1;j<=m;j++)
            ans2+=(n-i+1)*(m-j+1);
    cout<<ans1<<" "<<ans2-(n*m);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}