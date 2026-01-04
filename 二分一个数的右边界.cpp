#include<bits/stdc++.h>
using namespace std;
int x,n=10;
int l=0,r=n-1,mid;
int a[15]={1,2,3,3,3,3,3,6,9,11}; 
int main()
{
	cin>>x;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(a[mid]<=x)
			l=mid+1;
		else
			r=mid-1;
	}
	if(l>0&&a[l-1]==x) cout<<l-1;
	else cout<<"no";
	return 0;
 } 
