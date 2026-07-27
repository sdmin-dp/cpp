#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,q,k,a[N];
bool check(ll x,ll k){
    ll cnt=x-(upper_bound(a+1,a+1+n,x)-a-1);
    return cnt>=k;
}
void solve(){
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    while(q--){
        cin>>k;
        ll l=1,r=2e18+2e5,ans;
        while(l<=r){
            ll mid=(l+r)>>1;
            if(check(mid,k)){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        cout<<ans<<'\n';
    }
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