#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,cnt;
char c;
void solve()
{
	cin>>n;
	cin>>c;
	if(n>=1000)
	{
		cnt+=8;
		n-=1000;
	}
	else
	{
		cnt+=8;
		if(c=='y') cnt+=5;
		cout<<cnt;
		return;
	}
	if(n%500!=0)
	{
		cnt+=((n/500)+1)*4;
	}
	else
	{
		cnt+=(n/500)*4;
	}
	if(c=='y') cnt+=5;
	cout<<cnt;
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

