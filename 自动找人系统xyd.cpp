#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll a1,b1,c1,a2,b2,c2,a3,b3,c3;
void solve()
{
	cin>>a1>>a2>>a3;
	cin>>b1>>b2>>b3;
	cin>>c1>>c2>>c3;
	if(a1>b1) {swap(a1,b1);swap(a2,b2);swap(a3,b3);}
	else if(a2>b2){swap(a1,b1);swap(a2,b2);swap(a3,b3);}
	else if(a3>b3){swap(a1,b1);swap(a2,b2);swap(a3,b3);}
	if(c1>=a1&&c1<=b1)
	{
		if(c1>a1||(a2<=c2&&c2<=b2))
		{
			if(c2>a2||c1>a1||(a3<=c3&&c3<=b3))
			{
				cout<<"Yes";
				return;
			}
		}
	}
	cout<<"No";
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

