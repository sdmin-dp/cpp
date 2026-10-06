#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,m;
ll a[N],b[N];
bool check(ll x){
	ll cnt=0;
	for(int i=1,j=1;i<=n&&j<=m;){
		if(abs(a[i]-b[j])<=x){
			i++,j++;
			cnt++;
		}else{
			if(a[i]>b[j]) j++;
			else i++;
		}
//		cerr<<i<<" "<<j<<el;
	}
//	cout<<el;
	return (cnt==min(n,m));
}
void erfen(){
	ll l=0,r=1e9,ans=0,mid=0;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	cout<<ans;
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>b[i];
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	erfen();
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("gloves.in","r",stdin);
	freopen("gloves.out","w",stdout);
	ll T=1;
//	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}


