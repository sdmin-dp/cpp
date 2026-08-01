#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e4+5;
const ll mxlog=20;
ll n,m;
ll a[N];
pair<ll,ll> st[20][N];
ll lg[N];
void init(){
    for(int i=1;i<=n;i++) lg[i]=lg[i/2]+1;
    for(int i=1;i<=n;i++) st[0][i].first=st[0][i].second=a[i];
    for(int k=1;k<=mxlog;k++){
        for(int i=1;i<=n;i++){
            st[k][i].first=max(st[k-1][i].first,st[k-1][i+(1<<k-1)+1].first);
            st[k][i].second=min(st[k-1][i].second,st[k-1][i+(1<<k-1)+1].second);
        }
    }
}
pair<ll,ll> query(ll x,ll y){
    ll k=lg[y-x+1];
    if(x+(1<<k)<y) k++;
    ll mx=max(st[k-1][x].first,st[k-1][y-(1<<k-1)].first);
    ll mn=min(st[k-1][x].second,st[k-1][y-(1<<k-1)].second);
    return {mx,mn};
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    init();
    // ll mx=-1e12,mn=1e12;
    ll cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            // auto t=query(i,j);
            // if(t.first-t.second<=m) cnt++;
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