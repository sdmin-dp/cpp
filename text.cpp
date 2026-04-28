#include<bits/stdc++.h>
using namespace std;
int n,m,a[8],s=0;
void dfs(int k)
{
	if(n==0) return ;
	if(k==m)
	{
		if(n>=a[k-1]) s++;
		return ;
	}
	for(int i=a[k-1];i<=n/(m-k+1);i++)
	{
		a[k]=i;
		n-=i;
		dfs(k+1);
		n+=i;
	}
}
int main()
{
	cin>>n>>m;
	a[0]=1;
	dfs(1);
	cout<<s<<endl;
	return 0;
}
