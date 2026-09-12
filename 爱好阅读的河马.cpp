#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e5+5;
ll n,m,t,x;
ll a[N],b[N];
ll sa[N],sb[N];
void solve(){
    cin>>n>>m>>t;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sa[i]=sa[i-1]+a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>b[i];
        sb[i]=sb[i-1]+b[i];
    }
    ll ans=0;
    for(int i=0;i<=n&&sa[i]<=t;i++){
        ll pos=upper_bound(sb+1,sb+m+1,t-sa[i])-sb-1;
        ans=max(ans,pos+i);
    }
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("xxx.in","r",stdin);
    // freopen("xxx.out","w",stdout);
    ll T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}