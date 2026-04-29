#include<bits/stdc++.h>
#define ll int
using namespace std;
#define el '\n'
const ll N=3e5+5;
const ll mod=998244353;
ll n;
ll dep[N],up[22][N];
ll num[N][52];
ll sum[N][52];
vector<ll> g[N];
void dfs(ll x,ll f){
    dep[x]=dep[f]+1;up[0][x]=f;
    for(int i=1;i<20;i++) up[i][x]=up[i-1][up[i-1][x]];
    for(auto i:g[x]) if(i!=f) dfs(i,x);
}
ll LCA(ll u,ll v){
    if(dep[u]<dep[v]) swap(v,u);
    for(int i=20;i>=0;i--){
        if(dep[up[i][u]]>=dep[v]){
            u=up[i][u];
        }
    }
    if(u==v) return u;
    for(int k=20;k>=0;k--){
        if(up[k][u]!=up[k][v]){
            u=up[k][u];
            v=up[k][v];
        }
    }
    return up[0][u];
}
ll dis(ll x,ll y,ll k){
    if(dep[x]>dep[y]) return (sum[x][k]-sum[y][k]+mod)%mod;
    else return (sum[y][k]-sum[x][k]+mod)%mod;
}
void dfs2(ll x,ll f){
    for(auto i:g[x]){
        if(i!=f){
            for(int k=1;k<=50;k++){
                sum[i][k]=(sum[x][k]+num[i][k])%mod;
            }
            dfs2(i,x);
        }
    }
}
void solve(){
    cin>>n;
    for(int i=1;i<n;i++){
        ll x,y;cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dep[0]=-1;
    dfs(1,0);

    for(int i=1;i<=n;i++){
        // cerr<<dep[i]<<" ";
        ll res=dep[i];
        for(int j=1;j<=50;j++){
            num[i][j]=res;
            res=res*dep[i]%mod;
            // cerr<<num[i][j]<<" ";
        }
        
        // cerr<<el;
    }
    dfs2(1,0);
    ll q;
    cin>>q;
    while(q--){
        ll l,r,k;
        cin>>l>>r>>k;
        ll lca=LCA(l,r);
        ll ans=(dis(l,lca,k)+dis(r,lca,k)+num[lca][k])%mod;
        cout<<ans<<el;
        // cerr<<lca<<el;
        // cerr<<sum[l][5]<<" "<<sum[r][5]<<el;
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
}
