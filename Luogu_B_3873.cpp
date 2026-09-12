#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e2+5;
const ll M=4e3+5;
ll n,L,m;
ll sum;
pair<ll,ll> a[N];
ll dp[M];
void solve(){
    cin>>n>>L;
    for(int i=1;i<=n;i++){
        cin>>a[i].first>>a[i].second;
        if(a[i].second>L) a[i].second=L;
        sum+=a[i].second;
    }
    if(sum<L){
        cout<<"no solution";
        return;
    }

    for(int i=1;i<=2*L;i++) dp[i]=1e4;
    dp[0]=0;
    for(int i=1;i<=n;i++){
        for(int j=2*L;j>=a[i].second;j--){
            dp[j]=min(dp[j],dp[j-a[i].second]+a[i].first);
            // cout<<setw(11)<<dp[j]<<" ";
        }
        // for(int j=1;j<=2*L;j++) cout<<setw(6)<<dp[j];
        // cout<<'\n';
    }
    ll ans=LONG_LONG_MAX;
    for(int i=L;i<=2*L;i++){
        ans=min(ans,dp[i]);
        // cout<<
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
/*
 10000 10000 10000 10000 10000 10000 10000 10000 10000    10 10000 10000 10000 10000 10000 10000 10000 10000 10000 10000
 10000 10000 10000 10000     2 10000 10000 10000 10000    10 10000 10000 10000 10000    12 10000 10000 10000 10000 10000
 10000 10000 10000     4     2 10000 10000 10000     6    10 10000 10000 10000    14    12 10000 10000 10000    16 10000
 10000 10000     5     4     2 10000     9     7     6    10 10000    11    15    14    12 10000    19    17    16 10000
 10000     3     5     4     2     7     5     7     6    10     9    11    15    14    12    17    15    17    16    20
2*/