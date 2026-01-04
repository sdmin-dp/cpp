#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e6+5; 
ll n,m;
ll a[N];
unordered_map<ll,ll> mp;
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mp[a[i]]=i;
	}
	cin>>m;
	for(int i=1;i<=n;i++){
		ll k=m-a[i];
		if(mp[k]!=0&&mp[k]!=i){
			cout<<"["<<i-1<<","<<mp[k]-1<<"]";
			return;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
//  freopen("xxx.in","r",stdin);
//  freopen("xxx.out","w",stdout);
	ll T=1;
//  cin>>T;
	while(T--){
		solve();
	}
}
