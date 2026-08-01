#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e4+5;
const ll mxlog=20;
ll n,m;
ll a[N];
pair<ll,ll> st[20][N];
ll lg2[N];
void init(){
    for(int i=1;i<=n;i++) st[i][0].first=a[i];
    for(int i=1;i<=n;i++) st[i][0].second=a[i];
    for(int j=1;j<=mxlog;j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            st[i][j].first=max(st[i][j-1].first,st[i+(1<<(j-1))][j-1].first); 
        }
    }
    for(int j=1;j<=mxlog;j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            st[i][j].second=min(st[i][j-1].second,st[i+(1<<(j-1))][j-1].second); 
        }
    }
    for(int i=2;i<=n;i++) lg2[i]=lg2[i/2]+1;
}
pair<ll,ll> query(ll l,ll r){
    ll k=lg2[r-l+1];
    // ll t1=
    return {max(st[l][k].first,st[r-(1<<k)+1][k].first),min(st[l][k].second,st[r-(1<<k)+1][k].second)};
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    init();
    // ll mx=-1e12,mn=1e12;
    ll cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            auto t=query(i,j);
            ll t1=t.first,t2=t.second;
            if(t1-t2<=m){
                cnt++;
            }
        }
    }
    cout<<cnt;
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