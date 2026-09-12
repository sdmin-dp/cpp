#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,m;
ll a[N];
ll num[N]; 
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		num[i]=num[i-1]+a[i];
	}
	ll mx=-1e9;
	for(int i=m;i<=n;i++){
		ll k=num[i]-num[i-m];
		mx=max(mx,k);
	}
	cout<<mx;
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

