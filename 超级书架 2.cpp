#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e1+5;
ll n,m;
ll a[N];
ll ans=1e9; 
void dfs(ll sum,ll x){
	if(sum-m>=ans) return;
	if(x>n+1) return; 
	if(sum>=m){
		ans=min(ans,sum-m);
		return; 
	}
	dfs(sum,x+1);
	dfs(sum+a[x],x+1); 
} 
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(0,1); 
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

