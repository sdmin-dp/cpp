#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=5e4+5;
ll n,m,h;
ll a[N];
ll check(ll x){
	ll p=0,cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i]-a[p]<x){
			cnt++;
		}
		else{
			p=i;
		}
	}
	if(a[n+1]-a[p]<x){
		cnt++;
	}
	return cnt; 
}
ll rf(){
	ll l=1,r=1e9,mid=0,ans=0;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	return ans;
}
void solve()
{
	cin>>h>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	a[n+1]=h;
	ll l=1,r=1e9,mid=0,ans=0;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)<=m){
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	if(check(l)<=m) cout<<l;
	else cout<<r;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
//	freopen("xxx.in","r",stdin);
//	freopen("xxx.out","w",stdout);
	ll T=1;
//	cin>>T;
	while(T--) solve();
	return 0;
}

