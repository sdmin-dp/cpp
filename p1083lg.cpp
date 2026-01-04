#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e6+5;
ll n,m;
ll a[N],b[N];
ll s,e,num;
void solve()
{
	//cin
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i]-a[i-1];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>num>>s>>e;
		b[s]-=num;
		b[e+1]+=num;
		for(int j=1;j<=n;j++)
		{
			a[j]=a[j-1]+b[j];
			if(a[j]<0)
			{
				cout<<-1<<el<<i;
				return;
			}
		}
	}
	//Ö÷Òª´úÂë
	
	//cout
	cout<<0;
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

