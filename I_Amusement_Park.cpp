#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,k;
ll a[N];
bool check(ll x){
    ll sum=0;
    for(int i=1;i<=n;i++){
        sum+=min(a[i]-x,0ll);
    }
    return sum<=k;
}
void erfen(){
    ll l=1,r=1e9,ans=0,mid=0;
    while(l<=r){
        mid=(l+r)/2;
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
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    erfen();
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