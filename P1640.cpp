#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=2e6+5;
ll n;
pair<ll,ll> a[N];
vector<ll> g[N];
ll vis[N];
ll match[N];
bool dfs(ll u,ll id){
    for(auto i:g[u]){
        if(vis[i]!=id){
            vis[i]=id;
            if(!match[i]||dfs(match[i],id)){
                match[i]=u;
                return 1;
            }
        }
    }
    return 0;
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].first>>a[i].second;
    for(int i=1;i<=n;i++){
        g[a[i].first].push_back(n+i);
        g[a[i].second].push_back(n+i);
    }
    ll cnt=0;
    for(int i=1;i<=n;i++){
        if(!dfs(i,i)) break;
        cnt++;
    }
    cout<<cnt;
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