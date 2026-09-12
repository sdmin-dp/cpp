#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e2+5;
ll n,m=8e5,dp[800005],v[N],w[N];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>w[i]>>v[i];
	for(int i=1;i<=800000;i++) dp[i]=-1e9;
	dp[400000]=0;
	for(int i=1;i<=n;i++)
	{
		if(w[i]>=0)
			for(int j=m;j-w[i]>=0;j--) dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
		else
			for(int j=0;j-w[i]<=m;j++) dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
	}
	ll mx=0;
	for(int j=400000;j<=m;j++)
		if(dp[j]>=0)
			mx=max(mx,dp[j]+j-400000);
	cout<<mx;
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

