#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e3+5;
ll dx[]={0,1,0,-1},dy[]={1,0,-1,0};
ll n,m;
char c[N][N];
ll vis[N][N];
ll idx=0;
map<ll,ll> cnt;
map<ll,vector<pair<ll,ll>>> mp;
map<pair<ll,ll>,ll> air;
void bfs(ll bx,ll by){
    queue<pair<ll,ll>> q;
    q.push({bx,by});
    vis[bx][by]=idx;
    cnt[idx]++;
    while(!q.empty()){
        ll x=q.front().first,y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            ll xx=x+dx[i],yy=y+dy[i];
            if(xx>=1&&xx<=n&&yy>=1&&yy<=m){
                if(c[xx][yy]=='O'&&!vis[xx][yy]){
                    vis[xx][yy]=idx;
                    cnt[idx]++;
                    q.push({xx,yy});
                }else if(c[xx][yy]=='.'){
                    //cerr<<xx<<" "<<yy<<" "<<x<<" "<<y<<" "<<i<<el;
                    mp[vis[x][y]].push_back({xx,yy});
                }
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
    //cerr<<n<<" "<<m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(c[i][j]=='O'&&!vis[i][j]){
                idx++;
                //cerr<<idx<<el;
                bfs(i,j);
            }
        }
    }

    //cerr<<mp.size();
    for(auto &i:mp){
        sort(i.second.begin(),i.second.end());
        i.second.erase(unique(i.second.begin(),i.second.end()),i.second.end());
        if(i.second.size()!=1) continue;
        air[i.second[0]]+=cnt[i.first];
//        cerr<<"dog";
//        cnt[vis[i][i.second[0].second]]
    }
    ll mx=0,mx_x=0,mx_y=0;
//    cerr<<air.size();
    for(auto i:air){
        if(i.second>mx){
            mx=i.second;
            mx_x=i.first.first;
            mx_y=i.first.second;
        }
    }
    cout<<mx<<" "<<mx_x<<" "<<mx_y;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("liberty.in","r",stdin);
    freopen("liberty.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
