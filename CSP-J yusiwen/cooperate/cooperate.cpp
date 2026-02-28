#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n;
pair<ll,ll> a[N];
ll ans=1e18;
void dfs(ll x,ll sum1,ll sum2){
    if(x==n+1){
        ans=min(ans,max(sum1,sum2));
        return;
    }
    dfs(x+1,sum1+a[x].first,sum2);
    dfs(x+1,sum1,sum2+a[x].second);
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].first>>a[i].second;
    }
    dfs(1,0,0);
    cout<<ans;
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