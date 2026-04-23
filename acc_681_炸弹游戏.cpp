#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=3e3+5;
ll n,m;
char a[55][55];
pair<ll,ll> color[55][55];
vector<ll> g[N];
ll id;
ll match[N];
bool vis[N];
bool dfs(ll u){
    for(auto i:g[u]){
        if(!vis[i-id]){
            vis[i-id]=1;
            if(!match[i-id]||dfs(match[i-id])){
                match[i-id]=u;
                return 1;
            }
        }
    }
    return 0;
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
    ll idx=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]!='#'){
                color[i][j].first=idx;
            }else{
                if(j>1){
                    if(a[i][j]=='#'&&a[i][j-1]!=a[i][j]){
                        idx++;
                    }
                }
            }
        }
        if(a[i][m]!='#') idx++;
    }
    id=idx-1;
    for(int j=1;j<=m;j++){
        for(int i=1;i<=n;i++){
            if(a[i][j]!='#'){
                color[i][j].second=idx;
            }else{
                if(i>1){
                    if(a[i][j]=='#'&&a[i-1][j]!=a[i][j]){
                        idx++;
                    }
                }
            }
        }
        if(a[n][j]!='#') idx++;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]=='*'){
                g[color[i][j].first].push_back(color[i][j].second);
                g[color[i][j].second].push_back(color[i][j].first);
            }
        }
    }
    ll cnt=0;
    for(int i=1;i<=id;i++){
        memset(vis,0,sizeof(vis));
        if(dfs(i)) cnt++;
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