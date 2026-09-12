#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e2+5;
ll n,b,e;
ll dis[N][N];
bool vis[N];
void bfs(){
    queue<pair<ll,ll>> q;
    q.push({b,0});
    vis[b]=1;
    while(!q.empty()){
        auto x=q.front();
        q.pop();
        // cout<<x.first<<" "<<x.second<<el;
        if(x.first==e){
            cout<<x.second-1;
            return;
        }
        for(int i=1;i<=n;i++){
            if(dis[x.first][i]&&!vis[i]){
                vis[i]=1;
                q.push({i,x.second+1});
            }
        }
    }
}
void solve(){
    cin>>n>>b>>e;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin>>dis[i][j];
    bfs();
}

int main() {
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