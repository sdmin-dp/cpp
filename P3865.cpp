#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
const ll mxlog=17;
ll n,m;
ll a[N];
ll st[N][20];
void init(){
    for(int i=1;i<=n;i++) st[i][0]=a[i];
    for(int j=1;j<=mxlog;j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            st[i][j]=max(st[i][j-1]+st[i+(1<<(j-1))][j-1]); 
        }
    }
}
ll query(ll l,ll r){

}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    init();
    for(int i=1;i<=m;i++){
        ll x,y;
        cin>>x>>y;
        cout<<query(x,y);
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