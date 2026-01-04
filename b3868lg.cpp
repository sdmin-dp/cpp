#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
string s;
int ans[10]={0,1,1,1,1};
void solve()
{
	cin>>s;
	ans[1]=1;
	ans[2]=1;
	ans[3]=1;
	ans[4]=1;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>'1')
		{
			ans[1]=0;
		}
		if(s[i]>'7')
		{
			ans[2]=0;
		}
		if(s[i]>'9')
		{
			ans[3]=0;
		}
		if(s[i]>'F')
		{
			ans[4]=0;
		}
	}
	cout<<ans[1]<<" "<<ans[2]<<" "<<ans[3]<<" "<<ans[4]<<el;
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

