#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=4e4+5;
ll n,ans;
vector<pair<ll,ll>> g[N];
ll dfs(ll x,ll fa){
    ll dist=0,d1=0,d2=0;
    for(auto i:g[x]){
        if(i.first==fa) continue;
        ll d=dfs(i.first,x)+i.second;
        dist=max(dist,d);
        if(d>d1) d2=d1,d1=d;
        else if(d>d2) d2=d;
    }
    ans=max(ans,d1+d2);
    return dist;
}
void solve(){
    cin>>n;
    for(int i=1;i<n;i++){
        ll x,y,z;
        cin>>x>>y>>z;
        g[x].push_back({y,z});
        g[y].push_back({x,z});
    }
    dfs(1,-1);
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