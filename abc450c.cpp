#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e3+5;
ll dx[]={0,1,0,-1},dy[]={1,0,-1,0};
ll n,m;
char a[N][N];
bool vis[N][N];
ll cnt;
bool flag;
void dfs(ll x,ll y){
    if(flag) return;
    if(x==1||y==1||x==n||y==m){
        cnt--;
        flag=1;
        return;
    }
    for(int i=0;i<4;i++){
        ll xx=x+dx[i],yy=y+dy[i];
        if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&a[xx][yy]=='.'&&!vis[xx][yy]){
            vis[xx][yy]=1;
            dfs(xx,yy);
        }
    }
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin>>a[i][j];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            flag=0;
            if(a[i][j]=='.'&&!vis[i][j]){
                cnt++;
                vis[i][j]=1;
                dfs(i,j);
            }
        }
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