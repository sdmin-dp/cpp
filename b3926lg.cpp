#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
void solve()
{
	ll n;
	string x,s1,s2,y;
	cin>>n;
	cin>>x;
	cin>>s1;
	cin>>s2;
	cin>>y;
	if(x[x.size()-1]=='m')
	{
		if(x=="km")
		{
			if(y=="m") cout<<n<<" "<<x<<" = "<<n*1000<<" "<<y;
			else cout<<n<<" "<<x<<" = "<<n*1000*1000<<" "<<y;
		}
		else cout<<n<<" "<<x<<" = "<<n*1000<<" "<<y;
	}
	else
	{
		if(x=="kg")
		{
			if(y=="g") cout<<n<<" "<<x<<" = "<<n*1000<<" "<<y;
			else cout<<n<<" "<<x<<" = "<<n*1000*1000<<" "<<y;
		}
		else
		{
			cout<<n<<" "<<x<<" = "<<n*1000<<" "<<y;
		}
	}
	cout<<el;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	ll T=1;
	cin>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}

