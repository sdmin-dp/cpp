#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e2+5;
ll n,m;
ll a[N][N];
bool vis[N][N];
ll dx[]={0,1,0,-1},dy[]={1,0,-1,0};
ll sum=0,ans=0;
void dfs(ll x,ll y){
    for(int i=0;i<4;i++){
        ll xx=x+dx[i],yy=y+dy[i];
        if(xx>=1&&yy>=1&&xx<=n&&yy<=m&&a[xx][yy]!=0&&!vis[xx][yy]){
            sum++;
            vis[xx][yy]=1;
            dfs(xx,yy);
        }
    }
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]!=0&&!vis[i][j]){
                sum=1;
                vis[i][j]=1;
                dfs(i,j);
                ans=max(ans,sum);
            }
        }
    }
    cout<<ans;
}

int main() {
    // ios::sync_with_stdio(0);
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