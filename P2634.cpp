#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=2e4+5;
ll n;
vector<pair<ll,ll>> g[N];
ll sum[N][3];
ll ans;
void dfs(ll x,ll fa){
    for(auto i:g[x]){
        if(i.first==fa) continue;
        for(int j=0;j<=2;j++){
            sum[x][(j+i.second)%3]+=sum[i.first][j];
        }
    }
}
void dfs2(ll u,ll fa){
    ans+=sum[u][0];
    for(auto i:g[u]){
        ll v=i.first,w=i.second;
        if(v==fa) continue;
        ll sumu[3],sumv[3];
        for(int j=0;j<=2;j++){
            sumu[(j+w)%3]=sum[u][(j+w)%3];
            sum[u][(j+w)%3]-=sum[v][j];
        }
        for(int j=0;j<=2;j++){
            sumv[(j+w)%3]=sum[v][(j+w)%3];
            sum[v][(j+w)%3]+=sum[v][j];
        }
        dfs2(v,u);
        for(int j=0;j<=2;j++){
            
        }
    }
}
void solve(){
    cin>>n; 
    for(int i=1;i<n;i++){
        ll x,y,z;
        cin>>x>>y>>z;
        g[x].push_back({y,z});
        g[y].push_back({x,z});
    }
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