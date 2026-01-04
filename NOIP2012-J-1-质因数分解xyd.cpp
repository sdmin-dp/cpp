#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n;
bool isprime(ll x)
{
	for(int i=2;i*i<=x;i++)
	{
		if(x%i==0)
		{
			return 0;
		}
	}
	return 1;
}
void solve()
{
	cin>>n;
	for(ll i=2;i<n;i++)
	{
		if(isprime(i)&&isprime(n/i)&&n%i==0)
		{
			cout<<max(i,n/i);
			return;
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

