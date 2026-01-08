#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=400+5;
ll n,m,k;
vector<ll> g[N];
bool vis[N];
ll res[N];
ll cnt=0;
bool dfs(ll x){
    vis[x]=1;
	for(auto i:g[x]){
        if(!vis[i]&&(!res[i]||dfs(res[i]))){
            res[i]=x;
            return 1;
        }
	}
	return 0;
}
void solve(){
	cin>>n>>m>>k;
    for(int i=1;i<=k;i++){
        ll x,y;
        cin>>x>>y;
        g[x].push_back(y);
    }
    ll cnt=0;
    for(int i=1;i<=n+m;i++){
        memset(vis,0,sizeof(vis));
        if(dfs(i)) cnt++;
    }
    cout<<cnt;
}
int main(){
	ll T=1;
	//cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
