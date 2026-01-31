#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,m;
vector<ll> g[N];
bool vis[N];
ll res[N];
ll cnt=0;
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
	for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char c;
            cin>>c;
            if(c=='*') g[i].push_back(j);
        }
    }
    ll cnt=0;
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof(vis));
        cnt+=dfs(i);
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
