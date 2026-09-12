#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,m;
vector<ll> g[N];
ll dis[N];
void bfs(ll b){
    queue<ll> q;
    q.push(b);dis[b]=0;
    while(!q.empty()){
        ll x=q.front();
        q.pop();
        for(auto i:g[x]){
            if(dis[i]>dis[x]+1){
                dis[i]=dis[x]+1;
                q.push(i);
            }
        }
    }
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        ll x,y;cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    ll res=1e18,id=0;
    for(int i=1;i<=n;i++){
        memset(dis,0x3f,sizeof(dis));
        bfs(i);
        ll ans=-1e18;
        for(int j=1;j<=n;j++){
            if(j==i) continue;
            ans=max(ans,dis[j]);
        }
        if(ans<res) res=ans,id=i;
    }
    
    cout<<id;
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