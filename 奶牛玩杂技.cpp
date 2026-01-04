#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=5e4+5;
pair<ll,ll> a[N];
ll n;
bool cmp(pair<ll,ll> x,pair<ll,ll> y){
	return (x.first+x.second)<(y.first+y.second);
}
void solve(){
	cin>>n;
	ll num=0;
	ll ans=-1e9;
	for(int i=1;i<=n;i++) cin>>a[i].first>>a[i].second;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		ans=max(num-a[i].second,ans);
		num+=a[i].first;
	}
	cout<<ans;
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
}
