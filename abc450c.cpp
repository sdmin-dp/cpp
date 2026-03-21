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
void dfs(ll x,ll y){
    for(int i=0;i<4;i++){
        ll xx=x+dx[i],yy=y+dy[i];
        if(xx>n||xx<1||yy>m||yy<1||a[xx][yy]=='#'||vis[xx][yy]) continue;
        vis[xx][yy]=1;
        dfs(xx,yy);
    }
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin>>a[i][j];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
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