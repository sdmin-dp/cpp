#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=20+5;
ll dx[]={0,1,0,-1},dy[]={1,0,-1,0};
ll n,m;
char c[N][N];
bool vis[N][N];
ll bfs(ll bx,ll by,ll ex,ll ey){
    queue<pair<pair<ll,ll>,ll>> q;
    memset(vis,0,sizeof(vis));
    q.push({{bx,by},0});
    vis[bx][by]=1;
    while(!q.empty()){
        auto t=q.front();q.pop();
        ll x=t.first.first,y=t.first.second,step=t.second;
        if(x==ex&&y==ey){
            // cout<<step<<el;
            return step;
        }
        for(int i=0;i<4;i++){
            ll xx=x+dx[i],yy=y+dy[i];
            if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&c[xx][yy]=='.'&&!vis[xx][yy]){
                vis[xx][yy]=1;
                q.push({{xx,yy},step+1});
            }
        }
    }
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>c[i][j];
        }
    }
    ll mx=-1e9;
    for(int lx=1;lx<=n;lx++){
        for(int ly=1;ly<=m;ly++){
            if(c[lx][ly]!='.') continue;
            for(int rx=1;rx<=n;rx++){
                for(int ry=1;ry<=m;ry++){
                    if(c[rx][ry]!='.') continue;
                    mx=max(mx,bfs(lx,ly,rx,ry));
                }
            }
        }
    }
    cout<<mx;
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