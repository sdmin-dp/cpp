#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const int N=1e5+5;
ll n,c,m;
ll a[N];
bool check(int x)
{
	ll k=1,cnt=0;
	for(int i=2;i<=n;i++){
		if(a[i]-a[k]<x) cnt++;
		else k=i; 
	}
	return (cnt>m);
}
ll rf()
{
	ll mx=0;
	for(int i=1;i<=n;i++) mx=max(mx,a[i]);
	ll l=0,r=mx,mid,ans=0;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)){
			r=mid-1;
		}
		else{
			l=mid+1;
			ans=mid;
		}	
	}
	return ans;
}
void solve()
{
	cin>>n>>c;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	m=n-c;
	cout<<rf();
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
