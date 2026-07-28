#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,h;
ll a[N];
bool check(ll x){
    ll sum=0;
    for(int i=2;i<=n;i++) sum+=min(a[i]-a[i-1],x);
    sum+=x;
    return (sum>=h);
}
void erfen(){
    ll l=1,r=h,mid,ans;
    while(l<=r){
        mid=(l+r)/2;
        if(check(mid)){
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout<<ans<<el;
}
void solve(){
    cin>>n>>h;
    for(int i=1;i<=n;i++) cin>>a[i];
    erfen();
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}