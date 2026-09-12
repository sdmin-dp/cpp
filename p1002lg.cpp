#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,m,ans;
ll a[N]; 
void rf()
{
	ll l=1,r=n,mid=0;
	bool flag;
	while(l<=r)
	{
		mid=(l+r)/2;
		flag=0;
		for(int i=1;i<=mid;i++)
		{
			if(a[i]==a[mid]-m)
			{
				ans++;
				flag=1;
			}
		}
		if(!flag&&mid==n) r=mid-1;
		else l=mid+1;
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	rf();
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

