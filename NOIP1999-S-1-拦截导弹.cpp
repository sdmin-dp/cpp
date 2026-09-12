#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll x;
vector<ll> v1,v2;
void solve(){
	while(cin>>x){
		cin>>x;
		ll pos1=upper_bound(v1.begin(),v1.end(),x)-v1.begin();
		ll pos2=lower_bound(v2.begin(),v2.end(),x)-v2.begin();
		if(pos1==v1.size()) v1.push_back(x);
		else v1[pos1]=x;
		if(pos2==v2.size()) v2.push_back(x);
		else v2[pos2]=x;
	}
	cout<<v1.size()<<el<<v2.size();
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
