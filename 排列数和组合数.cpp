#include<bits/stdc++.h>
using namespace std;
char c;
int n,m;
int main()
{
	cin>>c;
	cin>>n>>m;
	if((c!='a'&&c!='A'&&c!='P'&&c!='p'&&c!='C'&&c!='c')||(n<m))
	{
		cout<<"输入错误,已结束程序!!!";
		return 0;
	}
	if(c=='A'||c=='a'||c=='P'||c=='p')
	{
		int k=1;
		for(int i=m;i<=n;i++)
		{
			k*=i;
		}
		cout<<k<<endl;
		
	}
	else if(c=='C'||c=='c')
	{
		int k=1,j=1;
		for(int i=1;i<=m;i++)
		{
			j*=i;
		}
		for(int i=m;i<=n;i++)
		{
			k*=i;
		}
		cout<<k/j;
	}
	return 0;
}
