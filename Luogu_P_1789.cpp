#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e2+5;
ll n,m,k;
bool vis[N][N];
void huoba(ll x,ll y){
    if(x>=1&&y>=1&&x<=n&&y<=n) vis[x][y]=1;
    if(x-1>=1&&y>=1&&x-1<=n&&y<=n) vis[x-1][y]=1;
    if(x-2>=1&&y>=1&&x-2<=n&&y<=n) vis[x-2][y]=1;
    if(x+1>=1&&y>=1&&x+1<=n&&y<=n) vis[x+1][y]=1;
    if(x+2>=1&&y>=1&&x+2<=n&&y<=n) vis[x+2][y]=1;
    if(x>=1&&y+1>=1&&x<=n&&y+1<=n) vis[x][y+1]=1;
    if(x>=1&&y+2>=1&&x<=n&&y+2<=n) vis[x][y+2]=1;
    if(x>=1&&y-1>=1&&x<=n&&y-1<=n) vis[x][y-1]=1;
    if(x>=1&&y-2>=1&&x<=n&&y-2<=n) vis[x][y-2]=1;
    if(x+1>=1&&y+1>=1&&x+1<=n&&y+1<=n) vis[x+1][y+1]=1;
    if(x-1>=1&&y+1>=1&&x-1<=n&&y+1<=n) vis[x-1][y+1]=1;
    if(x-1>=1&&y-1>=1&&x-1<=n&&y-1<=n) vis[x-1][y-1]=1;
    if(x+1>=1&&y-1>=1&&x+1<=n&&y-1<=n) vis[x+1][y-1]=1;
}
void yingshi(ll x,ll y){
    for(int i=-2;i<=2;i++){
        for(int j=-2;j<=2;j++){
            if(x+i<=n&&x-i>=1&&y+j<=n&&y-i>=1){
                vis[x+i][y+j]=1;
            }
        }
    }
}
void solve(){
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        ll x,y;
        cin>>x>>y;
        huoba(x,y);
    }
    for(int i=1;i<=k;i++){
        ll x,y;
        cin>>x>>y;
        yingshi(x,y);
    }
    ll cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(vis[i][j]==0){
                cnt++;
            }
        }
    }
    cout<<cnt;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    // freopen("xxx.in","r",stdin);
    // freopen("xxx.out","w",stdout);
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}