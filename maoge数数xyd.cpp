#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll l,r;
ll ans0,ans1;
string to_two(ll x)
{
	string res;
	do
	{
		res=char(x%2+48)+res;
		x/=2;
	}while(x);
	return res;
}                              
void solve()
{
	//cin
	cin>>l>>r;
	//жївЊДњТы
	for(int i=l;i<=r;i++)
	{
		string s=to_two(i);
		for(int j=0;j<s.size();j++)
		{
			if(s[j]=='0') ans0++;
			else ans1++;
		}
	}
	//cout
	cout<<ans1<<" "<<ans0;
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

