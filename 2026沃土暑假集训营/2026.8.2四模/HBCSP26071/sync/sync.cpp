//bu shi,zhe jiao tong guo lu 0.2?shi ge ren li mian 8 ge neng AC.
//I will AK!
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e5+5;
ll n,m,k;
ll a[N],b[N];
bool check(ll x){
    ll i=1,j=1,cnt=0;
    while(i<=n&&j<=m){
        if(abs(a[i]-b[j])<=x) i++,j++,cnt++;
        else if(b[j]<a[i]) j++;
        else i++;
    }
    // cerr<<cnt<<el;
    return (cnt>=k);
}
void erfen(){
    ll l=0,r=1e9,mid=0,ans=-1;
    while(l<=r){
        mid=(l+r)/2;
        // cerr<<l<<" "<<r<<" "<<mid<<" "<<ans<<" ";
        if(check(mid)){
            r=mid-1;
            ans=mid;
        }else{
            l=mid+1;
        }
    }
    cout<<ans;
}
void solve(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i];
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    erfen();
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("sync.in","r",stdin);
    freopen("sync.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}