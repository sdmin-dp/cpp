#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+10;
ll n,x,flag;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		x=i;
		flag=0;
		if(x%3==0)
		{
			while(x!=0)
			{
				if(x%10==5)
				{
					flag=1;
					break;
				}
				x/=10;
			}
			if(flag)
			{
				cout<<i<<el;
			}
		}
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

