#include<bits/stdc++.h>
using namespace std;
int x,n=10,a[15]={1,2,3,3,3,3,3,6,9,11};
bool rf()
{
	int l=0,r=n,mid;
	while(l<r)
	{
		mid=(l+r)/2;
		if(a[mid]==x)
			return 1;
		else if(a[mid]>x)
			r=mid;
		else
			l=mid+1;
	}
	if(l>=r) return 0;
}
int main()
{
	cin>>x;
	if(rf())
		cout<<"yes";
	else
		cout<<"no";
	return 0;
}
