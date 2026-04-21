#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e4+5;
ll n,m;
vector<ll> g[N];
ll color[N];
bool vis[N];
ll match[N];
ll cnt[3];
bool dfs(ll u,ll c){
    color[u]=c;
    cnt[c]++;
    for(auto v:g[u]){
        if(!color[v]) {if(!dfs(v,3-c)) return 0;}
        else if(color[v]==color[u]){return 0;}
    }
    return 1;
}
// bool dfs(ll u){
//     for(auto i:g[u]){
//         if(!vis[i]){
//             vis[i]=1;
//             if(!match[i]||dfs(match[i])){
//                 match[i]=u;
//                 return 1;
//             }
//         }
//     }
//     return 0;
// }
void solve(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        ll u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        cnt[1]=cnt[2]=0;
        if(!color[i]&&!dfs(i,1)){
            cout<<"Impossible";
            return;
        }
        ans+=min(cnt[1],cnt[2]);
    }
    // ll cnt=0;
    // for(int i=1;i<=n;i++){
    //     memset(vis,0,sizeof(vis));
    //     if(dfs(i)) cnt++;
    // }
    // cout<<n-cnt;
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