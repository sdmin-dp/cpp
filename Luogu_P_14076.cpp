#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+5;
ll n;
vector<pair<ll,ll>> g[N];
ll x,y,z;
bool vis[N];
ll ans=0;
void dfs(ll x,ll step){
    if(vis[x]) return;
    vis[x]=1;
    for(auto i:g[x])
            dfs(i.first,step+i.second);
    ans=max(ans,step);
}
void solve(){
    cin>>n;
    ll sum=0;
    for(int i=1;i<=n - 1;i++){
        cin>>x>>y>>z;
        g[x].push_back({y,z});
        g[y].push_back({x,z});
        sum+=z;
    }
    sum*=2;
    // vis[1]=1;
    dfs(1,0);
    cout<<sum-ans;
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