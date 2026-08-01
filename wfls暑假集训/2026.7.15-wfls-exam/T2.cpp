#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=4e4+5;
const ll inf=1e12; 
ll a,b,c,n,m;
vector<ll> g[N];
ll d1[N],d2[N],dn[N];
void bfs(ll s, ll *d){
    queue<ll> q;
    memset(d,0x3f,sizeof(ll)*N);
    d[s]=0;
    q.push(s);
        while(!q.empty()){
        ll u=q.front(); 
        q.pop();
        for(ll v : g[u]){
            if(d[v]>d[u]+1){
                d[v]=d[u]+1;
                q.push(v);
            }
        }
    }
}
void solve(){
    cin>>a>>b>>c>>n>>m;
    for(int i=0;i<m;i++){
        ll u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bfs(1,d1);
    bfs(2,d2);
    bfs(n,dn);
    ll ans=inf;
    for (int i=1;i<=n;++i){
        ll cur=d1[i]*a+d2[i]*b+dn[i]*c;
        ans=min(ans,cur);
    }
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