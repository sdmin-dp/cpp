#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,k,mx=-1e9,mn=1e9;
ll a[N];
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mx=max(a[i],mx);
		mn=min(a[i],mn);
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]<k) a[i]=mn;
		else if(a[i]>k) a[i]=mx;
	}
	for(int i=1;i<=n;i++)
	{
		cout<<a[i]<<" ";
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	ll T=1;
	while(T--)
	{
		solve();
	}
	return 0;
}

