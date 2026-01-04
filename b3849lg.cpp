#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,m,x;
char y;
stack<char> s;
void solve()
{
	cin>>n>>m;
	while(n>m)
	{
		x=n%m;
		n/=m;
		if(x>=10)
		{
			s.push(char(x-10+'A'));
		} 
		else
		{
			s.push(char(x+48));
		}
	}
	if(n>=10)
	{
		s.push(char(n-10+'A'));
	} 
	else
	{
		s.push(char(n+48));
	}
	while(!s.empty())
	{
		y=s.top();
		s.pop();
		cout<<y;
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

