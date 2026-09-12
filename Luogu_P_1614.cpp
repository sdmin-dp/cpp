#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=3e3+5;
ll n,m;
ll a[N],sum[N];
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    ll mn=1e18;
    for(int i=m;i<=n;i++){
        mn=min(mn,sum[i]-sum[i-m]);
    }
    cout<<mn;
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