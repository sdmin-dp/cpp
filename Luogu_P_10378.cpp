#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,m;
vector<ll> g[N];
ll vis[N];
ll ans=0;
ll change(ll x){
    if(x==1) return 2;
    else return 1;
}
void bfs(ll b){
    queue<ll> q;
    q.push(b);
    vis[b]=1;
    ll cnt1=1,cnt2=0;
    while(!q.empty()){
        auto x=q.front();
        q.pop();
        for(auto i:g[x]){
            if(vis[i]==0){
                vis[i]=change(vis[x]);
                if(vis[i]==1) cnt1++;
                else if(vis[i]==2) cnt2++;
                q.push(i);
            }
        }
    }
    ans+=min(cnt1,cnt2);
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        ll u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            bfs(i);
        }
    }
    cout<<ans<<" "<<n-ans;
}

int main() {
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