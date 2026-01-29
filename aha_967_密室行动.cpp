#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e2+5;
ll dx[]={0,1,0,-1},dy[]={1,0,-1,0};
ll n,m,idx;
map<pair<ll,ll>,ll> mp;
map<ll,pair<ll,ll>> mp2;
vector<ll> g[N];
bool a[N][N];
bool vis[N][N];
void bfs(){
    queue<pair<ll,ll>> q;
    vis[1][1]=1;
    pair<ll,ll> p={1,1};
    q.push(p);
    a[1][1]=1;
    while(!q.empty()){
        ll x=q.front().first,y=q.front().second;
        q.pop();
        pair<ll,ll> p={x,y};
        vector<pair<int, int>> nvim;
        for(auto i:g[mp[p]]){
            ll tx=mp2[i].first,ty=mp2[i].second;
            a[tx][ty]=1;
            nvim.push_back({tx,ty});
        }
        for(auto i:nvim){
            for(int j=0;j<4;j++){
                ll xxx=i.first+dx[j],yyy=i.second+dy[j];
                if(xxx>=1&&yyy>=1&&xxx<=n&&yyy<=n&&vis[xxx][yyy]&&!vis[i.first][i.second]){
                    pair<ll,ll> p={xxx,yyy};
                    q.push(p);
                }
            }
        }
        for(int i=0;i<4;i++){
            ll xx=x+dx[i],yy=y+dy[i];
            if(xx>=1&&yy>=1&&xx<=n&&yy<=n&&a[xx][yy]&&!vis[xx][yy]){
                pair<ll,ll> p={xx,yy};
                q.push(p);
                vis[xx][yy]=1;
            }
        }
    }
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            idx++;
          mp2[idx]={i,j};
          pair<ll,ll> p={i,j};
          mp[p]=idx; 
        }
    }
    for(int i=1;i<=m;i++){
        ll x,y,a,b;
        cin>>x>>y>>a>>b;
        pair<ll,ll> p={x,y},p2={a,b};
        g[mp[p]].push_back(mp[p2]);
    }
    bfs();
    ll ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ans+=a[i][j];
        }
    }
    cout<<ans;
}
int main(){
    ll T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
