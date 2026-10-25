#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e5+5;
ll n,m;
ll a[N],b[N];
ll mx=0;
bool check(ll x){
    ll t=m;
    for(int i=1;i<=n;i++){
        if(a[i]>=x) continue;
        else if(a[i]+b[i]<x) return 0;
        else t-=(x-a[i]);
    }
    return (t>=0);
}
void erfen(){
    ll l=0,r=mx+m,mid=0,ans=0;
    while(l<=r){
        mid=(l+r)/2;
        if(check(mid)){
            l=mid+1;
            ans=mid;
        }else{
            r=mid-1;
        }
    }
    cout<<ans;
}
void solve(){
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    for(ll j=1;j<=n;j++) cin>>b[j];
    erfen();
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