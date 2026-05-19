#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e3+5;
ll n,k;
bool color[N];
vector<ll> g[N];
ll ans;
void dfs(ll cnt,ll stp,ll x,ll fa){
    if(cnt<=k) ans=max(ans,stp);
    else return;
    for(auto i:g[x]) if(i!=fa) dfs(cnt+color[i],stp+1,i,x);
    
}
void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>color[i];
    for(int i=1,u,v;i<n;i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++) dfs(color[i],1,i,0);
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
