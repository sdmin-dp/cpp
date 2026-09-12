#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e3+5;
pair<ll,ll> a[N];
ll n;
bool cmp(pair<ll,ll> x,pair<ll,ll> y){
	if(x.first!=y.first) return x.first<y.first;
	else return x.second>y.second;
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].first>>a[i].second;
	sort(a+1,a+n+1,cmp);
	ll l=a[1].first,r=a[1].second;
	ll ans=0;
	for(int i=2;i<=n;i++){
		if(l<=a[i].first&&a[i].second<=r){
			ans++;
		}
		else{
			l=a[i].first;
			r=a[i].second;
		}
	}
	cout<<n-ans;
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
