#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n1,n2,m;
vector<ll> g[N];
ll match[N];
ll vis[N];
bool dfs(ll x){
	for(auto i:g[x]){
		if(!vis[i]){
			vis[i]=1;
			if(!match[i]||dfs(match[i])){
				match[i]=x;
				return 1;
			}
		}
	}
	return 0;
}
void solve(){
    cin>>n1>>n2>>m;
    for(int i=1;i<=m;i++){
        ll x,y;
        y+=n1;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs();
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