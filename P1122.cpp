#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n;
ll a[N];
vector<ll> g[N];
ll ans=0;
ll sum[N];
void dfs(ll x,ll fa){
    for(auto i:g[x]){
        if(i!=fa){
            dfs(i,x);
            sum[x]+=max(0ll,sum[i]);
            ans=max(sum[x],ans);
        }https://file+.vscode-resource.vscode-cdn.net/c%3A/Users/Administrator/.vscode/extensions/langningchen.cph-ng-0.7.6/res/party.gif
    }
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<n;i++){
        ll x,y;cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
        sum[i]=a[i];
    }
    sum[n]=a[n];
    ans=sum[1];
    dfs(1,0);
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