#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n;
ll a[N],num[N],d[N];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		num[i]=num[i-1]+a[i];
		d[i]=a[i]-a[i-1];
	}
	ll l,r;
	cin>>l>>r;
	cout<<num[r]-num[l-1]<<el;
	ll x;
	cin>>l>>r>>x; 
	d[l]+=x;
	d[r+1]-=x;
	for(int i=1;i<=n;i++) a[i]=a[i-1]+d[i];
	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	cout<<el;
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

