#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=4e1+5;
ll n,m;
ll a[N];
vector<ll> res1,res2;
void dfs1(ll x,ll step){
	if(x==n/2+1){
		res1.push_back(step);
		return;
	}
	dfs1(x+1,step+a[x]);
	dfs1(x+1,step);
}
void dfs2(ll x,ll step){
	//if(step>m) return;
	if(x==n+1){
		res2.push_back(step);
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
	sort(res2.begin(),res2.end());
	ll ans=0;
	for(int i=0;i<res1.size();i++){
		ll pos=upper_bound(res2.begin(),res2.end(),m-res1[i])-res2.begin();
		ans+=pos;
	}
	cout<<ans;
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
