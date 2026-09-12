#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=25;
bool vis1[N],vis2[N],vis3[N],vis4[N];
int n,t,cnt=1,res[100][10];
void dfs(int i)
{
	for(int j=1;j<=8;j++)
	{
		if(vis1[10+i-j]==0&&vis2[i+j]==0&&vis3[i]==0&&vis4[j]==0)
		{
			vis1[10+i-j]=1;
			vis2[i+j]=1;
			vis3[i]=1;
			vis4[j]=1;
			res[cnt][i]=j;
			if(i<8) dfs(i+1);
			else cnt++;
			vis1[10+i-j]=0;
			vis2[i+j]=0;
			vis3[i]=0;
			vis4[j]=0;
		}
	}
}
void solve()
{
	dfs(1);
	for(int i=1;i<cnt;i++)
	{
		for(int j=1;j<=8;j++)
		{
			if(res[i][j]==0) res[i][j]=res[i-1][j];
		 } 
	}
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		for(int j=1;j<=8;j++) cout<<res[t][j];
		cout<<el;
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

