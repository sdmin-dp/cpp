#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=500+5;
ll n,m;
ll a[N][N];
map<vector<pair<ll,ll>>,ll> mp;
bool vis[N][N];
vector<pair<ll,ll>> v;
ll dx[]={0,1,0,-1},dy[]={1,0,-1,0};
ll bx,by;
void dfs(ll x,ll y){
    for(int i=0;i<4;i++){
        ll xx=x+dx[i],yy=y+dy[i];
        if(xx>=1&&yy>=1&&xx<=n&&yy<=m&&a[xx][yy]==a[x][y]&&!vis[xx][yy]){
            vis[xx][yy]=1;
            v.push_back({xx-bx,yy-by});
            dfs(xx,yy);
        }
    }
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!vis[i][j]){
                bx=i,by=j;
                v.clear();
                vis[i][j]=1;
                dfs(i,j);
                mp[v]++;
            }
        }
    }
    cout<<mp.size(); 
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