#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=4e1+5;
ll n,m;
ll a[N];
ll t=0;
ll res=0;
ll ans[1000005];
void dfs1(ll x,ll step){
	if(x==n/2+1){
		if(step<=m){
			ans[++t]=step;
		}
		return;
	}
	dfs1(x+1,step+a[x]);
	dfs1(x+1,step);
}
void dfs2(ll x,ll step){
	if(step>m) return;
	if(x==n+1){
		if(step<=m){
			res++;
		}
		return;
	}
	dfs2(x+1,step+a[x]);
	dfs2(x+1,step);
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs1(1,0);
	dfs2(n/2+1,0);
	cout<<t+t*res;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
//	freopen("xxx.in","r",stdin);
//	freopen("xxx.out","w",stdout);
	ll T=1;
//	cin>>T;
	while(T--){
		solve();
	}
}
