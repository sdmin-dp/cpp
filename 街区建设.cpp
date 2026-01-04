#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=5e5+5;
ll n,m;
ll a[N];
ll d[N];
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		d[i]=a[i]-a[i-1];
	}
	ll l,r,h;
	for(int i=1;i<=m;i++){
		cin>>l>>r>>h;
		d[l]+=h;
		d[r+1]-=h;
	}
	for(int i=1;i<=n;i++){
		a[i]=a[i-1]+d[i];
		cout<<a[i]<<" "; 
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
//	freopen("xxx.in","r",stdin);
//	freopen("xxx.out","w",stdout);
	ll T=1;
//	cin>>T;
	while(T--) solve();
	return 0;
}

