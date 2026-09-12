#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=4e4+5;
ll n,m;
vector<pair<ll,ll>> g[N];
ll color[N];
ll tw[100005];
bool dfs(ll u,ll c,ll x){
    color[u]=c;
    for(auto [v,w]:g[u]){
        if(w<=x) continue;
        if(!color[v]) {if(!dfs(v,3-c,x)) return 0;}
        else if(color[v]==color[u]){return 0;}
    }
    return 1;
}
bool check(ll x){
    memset(color,0,sizeof(color));
    for(int i=1;i<=n;i++){if(!color[i]){if(!dfs(i,1,x)){return 0;}}}
    return 1;
}
ll erfen(){
    ll l=0,r=m,mid=0,ans=0;
    while(l<=r){
        mid=(l+r)/2;
        if(check(tw[mid])){
            r=mid-1;
            ans=mid;
        }else{
            l=mid+1;
        }
    }
    return tw[ans];
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
        tw[i]=w;
    }
    sort(tw+1,tw+m+1);
    cout<<erfen();
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