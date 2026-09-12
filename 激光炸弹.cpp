#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=5e3+5;
int num[N][N];
ll q,r;
ll n,m;
void solve()
{
	cin>>q>>r;
	ll x,y,v;
	for(int i=1;i<=q;i++){
		cin>>x>>y>>v;
		x++;y++;
		num[x][y]+=v;
	}
	for(int i=1;i<=5001;i++){
		for(int j=1;j<=5001;j++){
			num[i][j]+=num[i-1][j]+num[i][j-1]-num[i-1][j-1];
		}
	}
	if(r>5000){
		cout<<num[5000][5000];
		return;
	}
	ll ans=-1e9;
	for(int i=r;i<=5000;i++){
		for(int j=r;j<=5000;j++){
			ll cnt=num[i][j]-num[i-r][j]-num[i][j-r]+num[i-r][j-r];
			ans=max(ans,cnt);
		} 
	}
	cout<<ans;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
//	freopen("uoj9.in","r",stdin);
//	freopen("xxx.out","w",stdout);
	ll T=1;
//	cin>>T;
	while(T--) solve();
	return 0;
}

