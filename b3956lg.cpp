#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,ans;
string s; 
void solve()
{
	cin>>n;
	cin>>s;
	for(int i=0;i<n;i++)
	{
		if(s[i]>='a'&&s[i]<='z') ans+=int(s[i]-'a'+1);
		else ans+=(int(s[i])-int(s[i])-int(s[i]));
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

