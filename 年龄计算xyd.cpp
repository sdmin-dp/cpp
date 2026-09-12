#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll y,m1,d1,y2,m2,d2,ans;
void solve()
{
	cin>>y>>m1>>d1;
	cin>>y2>>m2>>d2;
	if(y2<y||(y2==y&&m2<m1)||(y2==y&&m2==m1&&d2<d1))
	{
		cout<<-1;
		return;
	}
	ans=y2-y;
	if(m2<m1) ans-=1;
	else if(m2==m1&&d2<d1) ans-=1;
	cout<<ans;
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

