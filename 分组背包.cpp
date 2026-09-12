#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e2+5;
const ll M=1e3+5;
ll n,m;
vector<pair<ll,ll>> a[N];
ll dp[M];
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        ll t;
        cin>>t;
        for(int j=1;j<=t;j++){
            ll x,y;
            cin>>x>>y;
            a[i].push_back({x,y});
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=m;j>=0;j--){
            for(auto k:a[i]){
                dp[j]=max(dp[j],dp[j-k.first]+k.second);
            }
        }
    }
    cout<<dp[m];
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