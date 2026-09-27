#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,m;
vector<ll> g[N];
ll ans[N];
ll in[N];
void topol(){
    queue<ll> q;
    for(int i=1;i<=n;i++){
        ans[i]=1;
        if(in[i]==0) q.push(i);
    }
    while(!q.empty()){
        ll u=q.front();q.pop();
        for(auto &v:g[u]){
            ans[v]=max(ans[v],ans[u]+1);
            if(--in[v]==0) q.push(v);
        }
    }
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        ll u,v;cin>>u>>v;
        g[u].push_back(v);
        in[v]++;
    }
    topol();
    for(int i=1;i<=n;i++) cout<<ans[i]<<el;
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