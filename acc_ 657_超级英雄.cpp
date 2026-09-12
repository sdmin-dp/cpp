#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,m;
ll res[N];
bool vis[N];
vector<ll> g[N];
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
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        ll x,y;cin>>x>>y;
        g[i].push_back(x);
        g[i].push_back(y);
    }
    ll cnt=0;
    for(int i=1;i<=m;i++){
        memset(vis,0,sizeof(vis));
        if(dfs(i)) cnt++;
        else break;
    }
    cout<<cnt;
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