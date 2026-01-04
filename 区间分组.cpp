#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
pair<ll,ll> a[N];
ll n;
priority_queue<ll,vector<ll>,greater<ll>> q;
bool cmp(pair<ll,ll> x,pair<ll,ll> y){
	return x.first<y.first;
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].first>>a[i].second;
	sort(a+1,a+n+1,cmp);
	q.push(a[1].second);
	for(int i=2;i<=n;i++){
		if(q.top()<a[i].first){
			q.pop();
			q.push(a[i].second);
		}
		else{
			q.push(a[i].second);
		}
	}
	cout<<q.size();
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
