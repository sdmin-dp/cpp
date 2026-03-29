#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
const ll maxlog=17;
ll n,q;
ll a[N];
ll lg2[N];
ll st[N][17];
void init(){
    for(int i=1;i<=n;i++) lg2[i]=lg2[i/2]+1;
    for(int i=1;i<=n;i++) st[i][0]=a[i];
    for(int j=1;j<=maxlog;j++) for(int i=1;i+(1<<j)-1<=n;i++) st[i][j]=max(st[i][j-1],st[i+(1<<j-1)-1][j-1]);
}
ll quary(ll l,ll r){
    
}
void solve(){
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    init();
    for(int i=1;i<=q;i++){
        cout<<
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