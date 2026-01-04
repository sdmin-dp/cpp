#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e2+5;
const ll M=5e4+5;
ll n,m,t;
pair<ll,ll> a[N];
ll dp[M];
void solve(){
    cin>>n>>t>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].first>>a[i].second;
    }
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++){
        for(int j=m;j>=a[i].second;j--){
            dp[j]=max(dp[j],dp[j-a[i].second]+a[i].first);
        }
    }
    for(int i=1;i<=m;i++){
        if(dp[i]>=t){
            cout<<i<<el;
            return;
        }
        // cerr<<i<<" ";
    }
    cout<<-1<<el;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("xxx.in","r",stdin);
    // freopen("xxx.out","w",stdout);
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}