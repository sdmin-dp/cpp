#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=5e3+5;
ll n,m;
ll x,y;
pair<ll,ll> a[N];
bool cmp(pair<ll,ll> p,pair<ll,ll> q){
	return p.second<q.second;
}
void solve(){
	cin>>n>>m;
	cin>>x>>y;
	for(int i=1;i<=n;i++) cin>>a[i].first>>a[i].second;
	sort(a+1,a+n+1,cmp);
	ll cnt=0;
	for(int i=1;i<=n;i++){
		if(m-a[i].second>=0&&x+y>=a[i].first){
			m-=a[i].second;
			cnt++;
		}
	}
	cout<<cnt;
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
