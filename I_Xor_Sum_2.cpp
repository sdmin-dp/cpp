#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e5+5;
ll n;
ll a[N];
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    ll l=1,r=0;
    ll xr=0,sum=0;
    ll ans=0;
    while(l<=n&&r<n){
        if(xr==sum){
            // cerr<<l<<" "<<r<<el;
            ans+=r-l+1;
            r++;
            xr^=a[r];
            sum+=a[r];
        }else{
            xr^=a[l];
            sum-=a[l];
            l++;
        }
    }
    if(xr==sum) ans+=r-l+1;
    while(xr!=sum){
        xr^=a[l];
        sum-=a[l];
        l++;
        if(xr==sum){
            ans+=r-l+1;
            break;
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