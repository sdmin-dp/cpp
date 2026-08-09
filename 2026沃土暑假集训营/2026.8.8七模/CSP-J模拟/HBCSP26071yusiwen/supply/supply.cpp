#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e5+5;
ll n,k;
ll a[N];
ll sum[N];
void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    ll ans=1e12;
    for(int i=1;i<=n;i++){
        ll pos=lower_bound(sum+i,sum+n+1,k+sum[i-1])-sum;
        if(pos>n||pos<1) continue;
        ans=min(ans,pos-i+1);
    }
    cout<<(ans==1e12?-1:ans);
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