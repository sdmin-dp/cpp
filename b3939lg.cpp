#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll l,r; 
bool isprime(ll n)
{
	for(int i=2;i*i<=n;i++)
		if(n%i==0)
			return 0;
	return 1;
}
void solve()
{
	cin>>l>>r;
	for(int i=l;i<=r;i++)
	{
		ll x=i,k=i,y=0;
		while(k>0)
		{
			y=y*10+k%10;
			k/=10;
		}
		if(isprime(x)&&isprime(y))
		{
			cout<<x<<el;
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

