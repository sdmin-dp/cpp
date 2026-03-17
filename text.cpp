#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=105;
ll n,m,t,match[N*N];
bool bad[N][N],vis[N*N];
vector<ll> g[N*N];
ll dx[]={1,1,2,2,-1,-1,-2,-2},dy[]={2,-2,1,-1,2,-2,1,-1};
bool dfs(ll u){
    for(auto v:g[u]){
        if(!vis[v]){
            vis[v]=1;
            if(!match[v]||dfs(match[v])){
                match[v]=u;
                return 1;
            }
        }
    }
    return 0;
}
void solve(){
    cin>>n>>m>>t;
    for(int i=1;i<=t;i++){
        ll x,y;cin>>x>>y;
        bad[x][y]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(bad[i][j]||(i+j)%2)continue;
            for(int k=0;k<8;k++){
                int nx=i+dx[k],ny=j+dy[k];
                if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&!bad[nx][ny]){
                    g[(i-1)*m+j].push_back((nx-1)*m+ny);
                }
            }
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(!bad[i][j]&&(i+j)%2==0){
                memset(vis,0,sizeof(vis));
                if(dfs((i-1)*m+j))ans++;
            }
    cout<<n*m-t-ans<<el;
}
int main(){
    // iios::sync_with_stdio(0);
    // cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
