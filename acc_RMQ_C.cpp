#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=2e5+5;
const ll mxlog=19;
ll n,m;
ll a[N];
ll st[N][20];
ll lg2[N];
void init(){
    for(int i=1;i<=n;i++) st[i][0]=a[i];
    for(int j=1;j<=mxlog;j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]); 
        }
    }
    for(int i=2;i<=n;i++) lg2[i]=lg2[i/2]+1;
}
ll query(ll l,ll r){
    ll k=lg2[r-l+1];
    return max(st[l][k],st[r-(1<<k)+1][k]);
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    init();
    cin>>m;
    for(int i=1;i<=m;i++){
        ll x,y;
        cin>>x>>y;
        cout<<query(x,y)<<el;
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