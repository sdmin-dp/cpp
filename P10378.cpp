#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,m;
vector<ll> g[N];
ll color[N];
ll ans;

void bfs(ll b){
    // q.emplace();
    queue<ll> q;
    q.push(b);
    color[b]=1;
    ll cnt[3]={0,1,0};
    while(!q.empty()){
        auto x=q.front();
        q.pop();q
        for(auto i:g[x]){
            if(!color[i]){
                color[i]=3-color[x];
                cnt[color[i]]++;
                q.push(i);
            }
        }
    }
    ans+=min(cnt[1],cnt[2]);
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
        if(!color[i]){
            bfs(i);
        }
    }
    cout<<ans<<" "<<n-ans;
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