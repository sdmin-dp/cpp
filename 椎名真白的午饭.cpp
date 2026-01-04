#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=4e1+5;
ll n,l,r;
ll a[N];
ll cnt=0;
void _cnt(ll x,ll step){
	
	for(int i=x;i<=n;i++){
		if(step+a[i]>r) return;
		if(step+a[i]>=l&&step+a[i]<=r){
			cnt++;
			_cnt(i+1,step+a[i]);
		}
	}
}
void dfs(ll x,ll step){
	if(x==n+1&&(step<l||step>r)) return;
	if(step>=l&&step<=r){
		cnt++;
		if(step+a[x]<=r) _cnt(x,step);
		return;
	}
	dfs(x+1,step);
	dfs(x+1,step+a[x]);
}
void solve(){
	cin>>n>>l>>r;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	dfs(1,0);
	cout<<cnt;
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
