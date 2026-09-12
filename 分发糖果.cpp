#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e2+5;
ll n,ans;
ll a[N],b[N];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=1;
	}
	for(int i=1;i<=n;i++) if(a[i]>a[i-1]) b[i]=b[i-1]+1;
	ll cnt=0;
	for(int i=n;i>=1;i--){
		if(a[i]>a[i+1]) b[i]=max(b[i],b[i+1]+1);
		cnt+=b[i];
	}
	cout<<cnt;
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

