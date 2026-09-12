#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=5e2+5;
ll dx[]={0,1,0,-1},dy[]={1,0,-1,0};
ll n,m,k,bx,by;
char c[N][N];
bool vis[N][N];
vector<pair<pair<ll,ll>,ll>> v;
bool cmp(pair<pair<ll,ll>,ll> x,pair<pair<ll,ll>,ll> y){
    return x.second>y.second;
}
void bfs(){
    queue<pair<pair<ll,ll>,ll>> q;
    q.push({{bx,by},0});
    vis[bx][by]=1;
    v.push_back({{bx,by},0});
    while(!q.empty()){
        auto t=q.front();q.pop();
        ll x=t.first.first,y=t.first.second,step=t.second;
        for(int i=0;i<4;i++){
            ll xx=x+dx[i],yy=y+dy[i];
            if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&c[xx][yy]=='.'&&!vis[xx][yy]){
                vis[xx][yy]=1;
                v.push_back({{xx,yy},step+1});
                q.push({{xx,yy},step+1});
            }
        }
    }
}
void solve(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>c[i][j];
            if(c[i][j]=='.') bx=i,by=j;
        }
    }
    bfs();
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<min(k,(ll)(v.size()));i++){
        ll x=v[i].first.first,y=v[i].first.second;
        c[x][y]='X';
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) cout<<c[i][j];
        cout<<el;
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