#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=2e5+5;
const ll m=100005;
const ll zero=50005;
ll n;
ll dp[N];
pair<ll,ll> a[N];
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].first>>a[i].second;
    for(int i=0;i<N;i++) dp[i]=-1e15;
    dp[zero]=0;
    ll L=zero-50090,R=zero+50090;
    for(int i=1;i<=n;i++){
        ll w=a[i].first-a[i].second;
        ll v=a[i].second+a[i].first;
        if(w>=0) for(int j=R;j>=L+w;j--) if(dp[j-w]>-1e16) dp[j]=max(dp[j],dp[j-w]+v);
        else for(int j=L;j<=R;j++) if(dp[j-w]>-1e16) dp[j]=max(dp[j],dp[j-w]+v);
    }
    if(dp[zero]==-1e15) cout<<-1;
    else cout<<dp[zero];
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