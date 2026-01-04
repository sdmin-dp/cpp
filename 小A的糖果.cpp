#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,m;
ll a[N];
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	ll ans=0;
	for(int i=2;i<=n;i++){
		if(a[i]+a[i-1]>m){
			ans+=(a[i]+a[i-1]-m);
			if(a[i]>=(a[i]+a[i-1]-m)){
				a[i]-=(a[i]+a[i-1]-m);
			}
			else{
				a[i-1]=(a[i]+a[i-1]-m)-a[i];
				a[i]=0;
			}
		}
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
