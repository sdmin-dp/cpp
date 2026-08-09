#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,k;
ll a[N];
vector<ll> g[N];
ll ans=0;
void dfs(ll x,ll fa,ll cnt){
    if(cnt==k){
        cout<<ans;
        exit(0);
    }
    for(auto i:g[x]){
        if(i!=fa){
            ans+=a[x];
            dfs(i,x,cnt+1);
        }
    }
}
void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
        ll u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0,0);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("retain.in","r",stdin);
    freopen("retain.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}