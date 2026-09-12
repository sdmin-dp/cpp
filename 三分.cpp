#include<bits/stdc++.h>
using namespace std;
#define ll long long 
double f(double x)
{
	double res=-x*x*x-2*x*x+3*x+6;
	return res;
}
void solve()
{
	double left=-1,right=2,midl,midr;
	while(left+0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001<=right)
	{
		cout<<left<<" "<<right<<endl;
		midl=left+(right-left)/3;
		midr=right-(right-left)/3;
		if(f(midl)>f(midr))
		{
			right=midr;
		}
		else
		{
			left=midl;
		}
	}
}
int main()
{
	solve();
	return 0;
}
