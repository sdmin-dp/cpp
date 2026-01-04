#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e6+5;
ll n;
ll num[N];
void solve()
{
	//cin
	cin>>n;
	//жївЊДњТы
	for(int i=1;i<n;i++)
	{
		num[i]=num[i-1]+i;
		for(int j=1;j<=i;j++)
		{
			if(num[i]-num[j-1]==n)
			{
				cout<<j<<" "<<i<<el;
			}
		}
	} 
	//cout
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

