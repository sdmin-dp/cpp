#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,m;
vector<pair<ll,ll>> g[N];
ll dis[N];
bool inq[N];
ll b,res;
void SPFA(){
    queue<ll> q;
    q.push(b);
    dis[b]=0;
    inq[b]=1;
    while(!q.empty()){
        ll x=q.front();
        inq[x]=0;
        q.pop();
        for(auto v:g[x]){
            if(dis[v.first]>dis[x]+v.second){
	            
                dis[v.first]=dis[x]+v.second;
                if(!inq[v.first]) q.push(v.first);
                inq[v.first]=1;
            }
        }
    }
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        ll x,y;cin>>x>>y;
        g[x].push_back({y,1});
        g[y].push_back({x,1});
    }
    ll res=1e18,id=0;
    for(int i=1;i<=n;i++){
        b=i;
        memset(dis,0x3f,sizeof(dis));
        SPFA();
        ll ans=-1e18;
        for(int j=1;j<=n;j++){
            if(j==i) continue;
            ans=max(ans,dis[j]);
        }
        if(ans<res) res=ans,id=i;
        for(int i=1;i<=n;i++) cerr<<dis[i]<<" ";
        cerr<<el;
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