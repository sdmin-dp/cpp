#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e3+5;
ll dx[]={1,0,-1,0},dy[]={0,1,0,-1};
map<ll,ll> mp;
ll n,m,q;
char c[N][N];
ll vis[N][N];
ll idx;
ll bfs(ll bx,ll by){
    ll ans=0;
    queue<pair<ll,ll>> q;
    q.push({bx,by});
    vis[bx][by]=++idx;
    while(!q.empty()){
        ll x=q.front().first,y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            ll xx=x+dx[i],yy=y+dy[i];
            if(xx>=1&&xx<=n&&yy>=1&&yy<=m){
                if(c[xx][yy]=='*') ans++;
                else if(c[xx][yy]=='.'&&!vis[xx][yy]){
                    vis[xx][yy]=idx;
                    q.push({xx,yy});
                }
            }
        }
    }
    return ans;
}
void solve(){
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>c[i][j];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(c[i][j]=='.'&&!vis[i][j]){
                ll x=bfs(i,j);
                mp[idx]=x;
            }
        }
    }
    for(int i=1;i<=q;i++){
        ll x,y;cin>>x>>y;
        cout<<mp[vis[x][y]]<<el;
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