#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e5+5;
ll n,k;
ll a[N];
map<ll,ll> mp;
void pop(ll x){
    mp[x]--;
    if(mp[x]==0) mp.erase(x);
}
void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    ll l=1,sum=0;
    ll ans=0,ans_l=0,ans_r=0;
    for(int r=1;r<=n;r++){
        mp[a[r]]++;
        if(mp.size()>k) pop(a[l++]);
//        ans=max(ans,r-l+1);
        if(r-l+1>ans){
            ans=r-l+1;
            ans_l=l;ans_r=r;
        }
    }
    cout<<ans<<" "<<ans_l<<" "<<ans_r;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("gallery.in","r",stdin);
    freopen("gallery.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
