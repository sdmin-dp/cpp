#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=2e3+5;
ll n;
ll a[N];
ll binary(ll i,ll j){
    //返回满足条件的数量
    //小于i+j
    ll x=a[i]+a[j];
    ll l=1,r=n,mid=0,ans=n;
    while(l<=r){
        mid=(l+r)/2;
        if(a[mid]>=x){
            r=mid-1;
        }else{
            l=mid+1;
            ans=mid;
        }
    }
    return ans;
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    ll ans=0;
    for(int i=1;i<n;i++){
        for(int j=i+1;j<n;j++){
            ll k=binary(i,j);
            ans+=k-j;
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

/*
6 5

5 100
2 99
3 98
6 97
6 96
4 95
*/