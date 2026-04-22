#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e2+5;
ll n,m;
pair<ll,ll> a[N],b[N];
vector<ll> g[N];
double dis(pair<ll,ll> a,pair<ll,ll> b){
    double dx=a.first-b.first,dy=a.second-b.second;
    return sqrt(dx*dx+dy*dy);
}
ll match[N],vis[N],rematch[N];
bool dfs(ll u){
    for(auto i:g[u]){
        if(!vis[i]){
            vis[i]=1;
            if(!match[i]||dfs(match[i])){
                match[i]=u;
                return 1;
            }
        }
    }
    return 0;
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i].first>>a[i].second;
    for(int i=1;i<=m;i++) cin>>b[i].first>>b[i].second;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(dis(a[i-1],a[i])*2>=dis(a[i-1],b[j])+dis(b[j],a[i])){
                g[i].push_back(j);
            }
        }
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
}    k;d