#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e4+5;
ll n;
pair<ll,ll> a[N];
bool cmp(pair<ll,ll> x,pair<ll,ll> y){
	return (x.second-x.first)<(y.second-y.first);
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].first;
	ll x=0,y=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].second;
		if(a[i].second>a[i].first){
			y++;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i].second<a[i].first){
			x++;
		}
	}
	sort(a+1,a+n+1,cmp);
	ll ans=0;
	ll i=1;
	while(x<=y){
		if(a[i].first>a[i].second){
			i++;
			continue;
		}
		if(a[i].first==a[i].second){
			ans++;
			x++;
		}
		else if(a[i].first<a[i].second){
			if(x==y){
				ans+=a[i].second-a[i].first;
				y--;
			}
			else{
				ans+=a[i].second-a[i].first+1;
				x++;
				y--;
			}
		}
		i++;
	}
	cout<<ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("exam.in","r",stdin);
	freopen("exam.out","w",stdout);
	ll T=1;
//	cin>>T;
	while(T--){
		solve();
	}
}
