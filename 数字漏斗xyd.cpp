#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,m;
void solve()
{
	//cin
	cin>>m;
	n=2*m-1;
	//жївЊДњТы
	ll x=n;
	for(int i=1;i<=n/2+1;i++)
	{
		for(int j=1;j<=i-1;j++) cout<<" ";
		for(int j=1;j<=x;j++) cout<<m;
		m--;x-=2;
		for(int j=1;j<=i-1;j++) cout<<" ";
		cout<<el;
	}
	m=2,x=3;
	for(int i=n/2;i>=1;i--)
	{
		for(int j=1;j<=i-1;j++) cout<<" ";
		for(int j=1;j<=x;j++) cout<<m;
		m++,x+=2;
		for(int j=1;j<=i-1;j++) cout<<" ";
		cout<<el;
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

