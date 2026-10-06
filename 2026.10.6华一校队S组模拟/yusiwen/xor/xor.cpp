#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e3+5;
ll n;
ll a[N];
ll mx[N][N];
ll xr[N];
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		ll maxx=a[i];
		mx[i][i]=a[i];
		for(int j=i+1;j<=n;j++){
			maxx=max(a[j],maxx);
			mx[i][j]=maxx;
//			cout<<mx[i][j]<<" ";
		}
//		cout<<el;
	}
	for(int i=1;i<=n;i++) xr[i]=xr[i-1]^a[i];
	ll ans=0;
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			if((xr[r]^xr[l-1])<=mx[l][r]){
				ans++;
//				cerr<<l<<" "<<r<<" "<<xr[r]^xr[l-1]<<" "<<mx[l][r]<<el;
			}
		}
	}
	cout<<ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ll T=1;
//	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}


