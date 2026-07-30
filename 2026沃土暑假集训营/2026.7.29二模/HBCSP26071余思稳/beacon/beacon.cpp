#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e5+5;
ll n,h;
ll a[N];
bool check(ll x){
    ll len=0,last=0;
    for(int i=1;i<=n;i++){;
        if(last<=a[i]){
            len+=x;
            last=a[i]+x;
        }else{
            ll k=a[i]+x;
            len+=k-last;
            last=k;
        }
    }
    return len>=h;
}
void erfen(){
    ll l=1,r=h,mid=0,ans=0;
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
    cin>>n>>h;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    erfen();
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("beacon.in","r",stdin);
    freopen("beacon.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}