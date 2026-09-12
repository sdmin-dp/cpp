#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
//1e5<2^16
const ll mxlog=17;
ll n,m;
ll a[N];
//st表，从i开始2^j个数的最大值
ll st[N][20];
//预处理log2[i]
ll lg2[N];
void init(){
    //从i开始一个数，不就是a[i]吗？
    for(int i=1;i<=n;i++) st[i][0]=a[i];
    //从i开始2^j个数，就是从i开始2^(j-1)个数和从i+2^(j-1)个数中的最大值取个max
    for(int j=1;j<=mxlog;j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]); 
        }
    }
    //i/2的幂次+1,i/2*2=i 
    for(int i=2;i<=n;i++) lg2[i]=lg2[i/2]+1;
}
ll query(ll l,ll r){
    //两块长2^k的板子，可以覆盖l~r
    ll k=lg2[r-l+1];
    //这两块板子的最大值取个max
    return max(st[l][k],st[r-(1<<k)+1][k]);
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    init();
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