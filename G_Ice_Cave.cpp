#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=5e2+10;

char mp[N][N];
bool vis[N][N];

void solve(){
    ll n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>mp[i][j];
        }
    }
    ll sx,sy,ex,ey,dx[]={0,1,0,-1},dy[]={1,0,-1,0};
    cin>>sx>>sy>>ex>>ey;
    auto dfs=[&](auto &&dfs,ll x,ll y)->void{
        for(int i=0;i<4;i++){
            ll xx=x+dx[i],yy=y+dy[i];
            if(xx<1||xx>n||yy<1||yy>m) continue;
            if(mp[xx][yy]=='X'){
                if(xx==ex&&yy==ey){
                    cout<<"YES"<<el;
                    exit(0);
                }
                continue;
            }
            mp[xx][yy]='X';
            dfs(dfs,xx,yy);
        }
    };
    dfs(dfs,sx,sy);
    cout<<"NO"<<el;
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
