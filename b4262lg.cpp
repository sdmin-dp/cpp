#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e2+5;
ll n,mx;
string s[N],ans;
map<string,ll> mp;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		for(int j=0;j<s[i].size();j++)
		{
			if(s[i][j]>='A'&&s[i][j]<='Z')
			{
				s[i][j]=char(s[i][j]+32);
			}
		}
		mp.insert({s[i],0});
		mp[s[i]]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(mx<=mp[s[i]])
		{
			ans=s[i];
			mx=mp[s[i]];
		}
	}
	cout<<ans;
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

