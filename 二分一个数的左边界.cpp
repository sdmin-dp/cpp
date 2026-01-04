#include<bits/stdc++.h>
using namespace std;
int n=10,a[15]={1,2,3,3,3,3,3,6,9,11},ans,x;

int main()
{
	cin>>x;
	int l=0,r=n-1,mid;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(x<=a[mid]) r=mid-1;
		else l=mid+1;
	}
	if(l<n&&a[l]==x) cout<<l;
	else cout<<"no";
	return 0;
 } 
