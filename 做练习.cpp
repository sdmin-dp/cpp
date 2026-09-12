#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll a,n;
vector<ll> v;
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		ll pos=upper_bound(v.begin(),v.end(),a,greater<ll>())-v.begin();
		if(pos==v.size()) v.push_back(a);
		else v[pos]=a;
	}
	cout<<v.size();
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
