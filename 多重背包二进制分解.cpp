#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+5;
ll n,m;
vector<pair<ll,ll>> a(1);
ll dp[N];
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        ll v,w,k;
        cin>>v>>w>>k;
        for(int i=1;i<k;i*=2){
            a.push_back({v*i,w*i});
            k-=i;
        }
        if(k!=0) a.push_back({v*k,w*k});
    }
    for(int i=1;i<a.size();i++){
        for(int j=m;j>=a[i].second;j--){
            dp[j]=max(dp[j],dp[j-a[i].second]+a[i].first);
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