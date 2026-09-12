#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll a[N],b[N],c[N];
ll n,m;
ll p[N];
ll d[N],cnt[N];
ll ans;
ll add(ll l ,ll r)
{
	if(l>r) swap(l,r);
	r--;
	d[r+1]--;
	d[l]++;
}
void solve()
{
	//cin
	cin>>n>>m;
	for(int i=1;i<=m;i++) cin>>p[i];
	for(int i=1;i<n;i++) cin>>a[i]>>b[i]>>c[i];
	//жївЊДњТы
	for(int i=2;i<=m;i++) add(p[i-1],p[i]);
	for(int i=1;i<n;i++){
		cnt[i]=cnt[i-1]+d[i];
		ans+=min(a[i]*cnt[i],c[i]+b[i]*cnt[i]);
	}
	//cout
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

