#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e1+5;
ll n;
ll a[N][N];
ll ans=1e9;
bool vis[N];
void dfs(ll x,ll step){
	if(step>=ans) return;
	if(x==n+1){
		ans=min(ans,step);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(x+1,step+a[x][i]);
			vis[i]=0;
		}
		
	}
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin>>a[i][j];
	dfs(1,0);
	cout<<ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
//  freopen("xxx.in","r".stdin);
//  freopen("xxx.out","w".stdout);
    ll T=1;
//  cin>>T;
    while(T--){
        solve();
    }
    return 0;
}

