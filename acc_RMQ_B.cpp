#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\\\\n'
const ll N=1e5+5;
const ll mxlog=17;
ll n,m;
ll a[N];
pair<ll,ll> st[N][20];
ll lg2[N];
void init(){
    for(int i=1;i<=n;i++) st[i][0]={a[i],a[i]};
    for(int j=1;j<=mxlog;j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            st[i][j].first=max(st[i][j-1].first,st[i+(1<<(j-1))][j-1].first); 
            st[i][j].second=min(st[i][j-1].second,st[i+(1<<(j-1))][j-1].second); 
        }
    }
    for(int i=2;i<=n;i++) lg2[i]=lg2[i/2]+1;
}
pair<ll,ll> query(ll l,ll r){
    ll k=lg2[r-l+1];
    return {max(st[l][k].first,st[r-(1<<k)+1][k].first),min(st[l][k].second,st[r-(1<<k)+1][k].second)};
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    init();
    for(int i=1;i<=m;i++){
        ll x,y;
        cin>>x>>y;
        pair<ll,ll> p=query(x,y);
        cout<<p.first<<" "<<p.second<<el;
    }
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