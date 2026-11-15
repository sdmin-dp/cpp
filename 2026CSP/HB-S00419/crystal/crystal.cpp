#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=5e5+5;
ll n,m;
ll a[N];
ll sum[N];
bool check(ll x){
    ll res=1e18;
    for(int i=x;i<=n;i++){
        ll tmp=a[i]*x-(sum[i]-sum[i-x]);
        res=min(res,tmp);
    }
    return (res<=m);
}
ll erfen(){
    ll l=0,r=n,mid=0,ans=0;
    while(l<=r){
        mid=(l+r)/2;
        if(check(mid)){
           ans=mid;
           l=mid+1; 
        }else{
            r=mid-1;
        }
    }
    return ans;
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    cout<<erfen()<<el;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}