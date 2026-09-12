#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll a,b,ans=1;
void solve()
{
	cin>>a>>b;
	while(1)
	{
		bool flag=0;
		for(int i=2;i<=min(a,b);i++)
		{
			if(a%i==0&&b%i==0)
			{
				flag=1;
				break;
			}
		}
		if(!flag){
			cout<<ans*a*b;
			return;
		}
		for(int i=2;i<=min(a,b);i++)
		{
			if(a%i==0&&b%i==0)
			{
				ans*=i;
				break;
			}
		}
	}
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

