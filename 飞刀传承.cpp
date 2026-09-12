#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,m;
ll ans=0;
pair<ll,ll> a[N];
bool cmp(pair<ll,ll> x,pair<ll,ll> y){
	return x.second>y.second;
}
void solve(){
	cin>>n>>m;
	ll mx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].first>>a[i].second;
		mx=max(a[i].first,mx);
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n&&m>0;i++){
		if(a[i].second>mx){
			ans++;
			m-=a[i].second;
		}
	}
	while(m>0){
		ans++;
		m-=mx;
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
