#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e2+5;
ll n,k;
ll a[N];
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,greater<ll>());
	sort(a+1,a+k+1);
	double ans=0;
	for(int i=1;i<=k;i++){
		ans=(ans+a[i]*1.0)/2.0;
	}
	printf("%.5f",ans);
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
