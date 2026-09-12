#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e1+5;
ll n,m;
char a[N][N];
bool check(ll xl,ll xr,ll yl,ll yr)
{
	ll book[N]={0,0};
	for(int i=xl;i<=xr;i++){
		for(int j=yl;j<=yr;j++)
		{
			book[int(a[i][j]-48)]++;
		}
	}
	return book[0]==book[1];
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
	ll ans=0;
	for(ll lx=1;lx<=n;lx++){
		for(ll ly=1;ly<=m;ly++){
			for(ll rx=lx;rx<=n;rx++){
				for(ll ry=ly;ry<=m;ry++){
					if(check(lx,rx,ly,ry)){
						ans=max(ans,(rx-lx+1)*(ry-ly+1));
					}
				}
			}
		}
	}
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

