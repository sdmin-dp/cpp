#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,x;
priority_queue<ll,vector<ll>,greater<ll>> q;
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x;
		q.push(x);
	}
	ll cnt=0;
	while(q.size()>1){
		ll a=q.top();q.pop();
		ll b=q.top();q.pop();
		cnt+=a+b;
		q.push(a+b);
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
	return 0;
}
