#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+5;
ll n,ans;
ll a[N],r[N];
ll mxl[N],mxr[N];
void solve(){
    cin>>n>>r[1];
    for(int i=2;i<=n;i++) r[i]=(r[i-1]*6807+2831)%201701;
    for(int i=1;i<=n;i++) a[i]=r[i]%10;
    for(int i=1;i<=n;i++) mxl[i]=max(mxl[i-1],a[i-1]);
    for(int i=n;i>=1;i--) mxr[i]=max(mxr[i+1],a[i+1]);
    for(int i=1;i<=n;i++){
        if(mxl[i]<=a[i]||mxr[i]<=a[i]) continue;
        else ans+=min(mxl[i]-a[i],mxr[i]-a[i]);
    }
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("xxx.in","r",stdin);
    // freopen("xxx.out","w",stdout);
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}