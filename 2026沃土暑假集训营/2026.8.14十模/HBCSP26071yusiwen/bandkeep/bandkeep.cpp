#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e5+5;
const ll mxlog=20;
ll n,d;
ll a[N];
pair<ll,ll> st[N][25];
ll lg2[N];
void init(){
    for(int i=1;i<=n;i++) st[i][0].first=st[i][0].second=a[i];
    for(int j=1;j<=mxlog;j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            st[i][j]={max(st[i][j-1].first,st[i+(1<<(j-1))][j-1].first),min(st[i][j-1].second,st[i+(1<<(j-1))][j-1].second)}; 
        }
    }
    for(int i=2;i<=n;i++) lg2[i]=lg2[i/2]+1;
}
pair<ll,ll> query(ll l,ll r){
    ll k=lg2[r-l+1];
    return {max(st[l][k].first,st[r-(1<<k)+1][k].first),min(st[l][k].second,st[r-(1<<k)+1][k].second)};
}
void solve(){
    cin>>n>>d;
    for(int i=1;i<=n;i++) cin>>a[i];
    init();
    ll l=1,mx=l,mn=l;
    ll ans=0;
    for(ll r=1;r<=n;r++){
        auto t=query(l,r);
        mx=t.first,mn=t.second;
        while(mx-mn>d){
            l++;
            auto t=query(l,r);
            mx=t.first,mn=t.second;
        }
        ans=max(ans,r-l+1);
    }
    cout<<n-ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("bandkeep.in","r",stdin);
    freopen("bandkeep.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}