#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=5e6+5;
ll n,m;
ll a[N],d[N];
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		d[i]=a[i]-a[i-1];
	}
	for(int i=1;i<=m;i++){
		ll l,r,x;
		cin>>l>>r>>x;
		d[l]+=x;d[r+1]-=x;
	}
	ll mn=1e9;
	for(int i=1;i<=n;i++){
		a[i]=a[i-1]+d[i];
		mn=min(a[i],mn);
	}
	cout<<mn;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
//	freopen("xxx.in","r",stdin);
//	freopen("xxx.out","w",stdout);
	ll T=1;
//	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
