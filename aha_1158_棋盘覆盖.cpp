#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e2+5;
ll n,m;
bool mp[N][N];
vector<ll> g[N*N];
ll dx[]={0,1,0,-1},dy[]={1,0,-1,0};
ll id[N][N];
bool vis[N*N];
ll res[N*N];
bool dfs(ll x){
//	cerr<<"you are a dog";
	for(auto i:g[x]){
		if(!vis[i]){
			vis[i]=1;
			if(!res[i]||dfs(res[i])){
				res[i]=x;
				return 1;
			}
		}
	}
	return 0;
}
void solve(){
    cin>>n>>m;
    memset(mp,1,sizeof(mp));
    for(int i=1;i<=m;i++){
        ll x,y;
        cin>>x>>y;
        mp[x][y]=0;
    }
    ll idx=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            id[i][j]=++idx;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=0;k<4;k++){
                ll xx=i+dx[k],yy=j+dy[k];
                if(xx>=1&&yy>=1&&xx<=n&&yy<=n&&mp[xx][yy]!=0){
                    g[id[i][j]].push_back(id[xx][yy]);
                }
            }
        }
    }
    ll cnt=0;
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof(vis));
        if(dfs(i)) cnt++;
    }
    cout<<cnt;
}  
int main(){
    ll T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
