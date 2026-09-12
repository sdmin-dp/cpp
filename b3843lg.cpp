#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e2+5;
string s;
ll n=1,B,b,num,ts;
string a[N];
void solve()
{
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]==',') n++;
		else a[n]=a[n]+s[i];
	}
	for(int i=1;i<=n;i++)
	{
		num=0,B=0,b=0,ts=0;
		for(int j=0;j<a[i].size();j++)
		{
			if(a[i][j]>='0'&&a[i][j]<='9') num++;
			else if(a[i][j]>='a'&&a[i][j]<='z') b++;
			else if(a[i][j]>='A'&&a[i][j]<='Z') B++;
			else if(a[i][j]=='!'||a[i][j]=='@'||a[i][j]=='#'||a[i][j]=='$') ts++;
		}
		if(b+B+num+ts==a[i].size()&&(a[i].size()>=6&&a[i].size()<=12)&&)
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

