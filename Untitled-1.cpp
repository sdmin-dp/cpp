#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e2+5;
ll n,m,k;
ll a[N];
bool cmp(ll x,ll y){
	return 10-(x%m)<10-(y%m);
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	cin>>k;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
//		cout<<a[i]<<" "<<(10-a[i]%10)<<el; 
		if(k-(m-a[i]%m)>=0){
			k-=(m-a[i]%m);
			a[i]-=a[i]%m;
			a[i]+=m;
		}
		
	}
	
	if(k!=0) a[1]+=k;
	ll ans=0;
	for(int i=1;i<=n;i++) ans+=(a[i]/m);
	cout<<ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	ll T=1;
	//cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
