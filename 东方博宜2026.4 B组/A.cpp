#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=2e3+5;
ll n;
ll a[N];
ll binary_sear(ll mn,ll mx){
    //返回满足条件的数量
    //二分两次，一个是小于mn+mx的，一个是大于mx-mn的
    //first
    ll x=mn+mx;
    ll res=0,tmp1=0,tmp2=0;
    ll l=1,r=n,mid=0,ans=0;
    while(l<=r){
        mid=(l+r)/2;
        if(a[mid]>x){
            r=mid-1;
        }else{
            ans=mid;
            l=mid+1;
        }
    }
    tmp1=ans;
    x=mx-mn;
    ans=upper_bound(a+1,a+n+1,x)-a;
    res+=n-ans+1;
    return res;
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    ll ans=0;
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            ll x=min(a[i],a[j]),y=max(i,j);
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