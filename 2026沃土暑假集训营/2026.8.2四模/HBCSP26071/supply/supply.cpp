//yuan ti,zhe ge dong xi nan zai na li?
//hao ba.wo cheng ren wo you ban ge xiao shi ti mei du dong.
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e5+5;
ll n,m;
ll a[N];
ll sum[N];
void solve(){
    cin>>n>>m;
    // cerr<<"gay"<<el;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
        // cerr<<"gay"<<el;
    }
    for(ll i=1;i<=m;i++){
        ll l,r,x;
        cin>>l>>r>>x;
        ll pos=lower_bound(sum+l,sum+r+1,x+sum[l-1])-sum;
        // cerr<<pos<<el;
        if(pos>r||pos<l){
            cout<<-1<<el;
            continue;
        }
        cout<<pos<<" "<<sum[pos]-sum[l-1]-x<<el;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("supply.in","r",stdin);
    freopen("supply.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}