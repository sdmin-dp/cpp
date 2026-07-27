#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n;
pair<ll,ll> a[N];
bool check(ll x){
    vector<ll> t(n+1,0);
    for(int i=1;i<=n;i++){
        ll h=a[i].first;
        ll s=a[i].second;
        if(x<h) return false;
        ll limit=(x-h)/s;
        if(limit<n){
            t[limit]++;
        }
    }
    ll sum=0;
    for(int i=0;i<n;i++){
        sum+=t[i];
        if(sum>i+1){
            return false;
        }
    }
    return true;
}
void erfen(){
    ll l=0,r=2e18,mid=0,ans=0;
    while(l<=r){
        mid=(l+r)/2;
        if(check(mid)){
            r=mid-1;
            ans=mid;
        }else{
            l=mid+1;
        }
    }
    cout<<ans<<el;
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].first>>a[i].second;
    }
    erfen();
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll T=1;
    while(T--){
        solve();
    }
    return 0;
}