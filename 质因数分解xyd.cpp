#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=pow(2,31);
ll n;
ll a[N];
bool isprime(ll x)
{
	if(x==1) return 0;
	for(int i=2;i*i<=x;i++) if(x%i==0) return 0;
	return 1;
}
void solve()
{
	cin>>n;
	if(isprime(n))
	{
		cout<<n;
		return;
	}
	ll mx=0;
	for(ll i=2;i<=n;i++)
	{
		if(n%i==0&&isprime(i))
		{
			mx=max(mx,i);
			i=2;
			a[i]++;
		}
		if(isprime(n)){
			mx=max(mx,n);
			a[n]++;
		}
	}
	bool flag=0;
	for(int i=1;i<=mx;i++)
	{
		if(a[i]!=0)
		{
			if(flag) cout<<"+";
			cout<<i<<"^"<<a[i];
			flag=1;
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

