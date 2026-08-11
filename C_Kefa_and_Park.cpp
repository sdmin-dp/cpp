#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,m;
bool cat[N];
vector<ll> g[N];
ll ans=0;
void dfs(ll x,ll fa,ll cnt){
    if(cat[x]) cnt++;
    else cnt=0;
    if(cnt>m) return;
    if(g[x].size()==1&&x!=1) ans++;
    for(auto i:g[x]){
        if(i==fa) continue;
        dfs(i,x,cnt);
    }
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>cat[i];
    for(int i=1;i<n;i++){
        ll u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
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