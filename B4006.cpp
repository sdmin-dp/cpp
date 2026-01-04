#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e3+5;
ll n,m;
ll a[N];
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	ll ans=0; 
	for(int i=1;i<=n;i++)
	{
		ll cnt=0;
		for(int j=i;j>=1;j--)
		{
			if(a[i]-a[j]<=m)
			{
				cnt+=a[j];
			}
		}
		ans=max(cnt,ans);
	}
	cout<<ans;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	//freopen("xxx.in","r",stdin);
	//freopen("xxx.out","w",stdout);
	ll T=1;
	while(T--)
	{
		solve();
	}
	return 0;
}

