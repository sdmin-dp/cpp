#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=50+5;
ll n,m;
ll bx,by,ex,ey;
char c[N][N];
ll dx[]={0,1,0,-1},dy[]={1,0,-1,0};
bool vis[N][N];
ll bfs(){
    queue<pair<pair<ll,ll>,ll>> q;
    q.push({{bx,by},0});
    while(!q.empty()){
        auto t=q.front();q.pop();
        ll x=t.first.first,y=t.first.second,step=t.second;
        if(x==ex&&y==ey) return step;
        for(int i=0;i<4;i++){
            ll xx=x+dx[i],yy=y+dy[i];
            if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&c[xx][yy]=='.'&&!vis[xx][yy]){
                vis[xx][yy]=1;
                q.push({{xx,yy},step+1});
            }
        }
    }
    return -1;
}
void solve(){
    cin>>n>>m;
    bx=1,by=1;ex=n,ey=m;
    ll sum=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>c[i][j];
            if(c[i][j]=='.') sum++;
        }
    }
    ll x=bfs();
    if(x==-1) cout<<-1<<el;
    else cout<<sum-x-1;
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