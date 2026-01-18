#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=200+5;
bool g[N][N];
ll n,m;
ll res[N];
bool vis[N];
bool dfs(ll x){
	for(int i=1;i<=m;i++){
		if(g[x][i]&&!vis[i]){
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
    memset(g,1,sizeof(g));
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        ll x;cin>>x;
        for(int j=1;j<=x;j++){
            ll y;cin>>y;
            g[i][y]=0;
        }
    }
    ll cnt=0;
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof(vis));
        if(dfs(i)) cnt++;
    }
    cout<<n+m-cnt;	
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("xxx.in","r",stdin);
    // freopen("xxx.out","w",stdout);
    ll T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}