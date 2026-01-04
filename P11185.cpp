#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e5+5;
ll n;
ll a[N],b[N],c[N];
ll A[N],B[N],C[N];
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
		A[i]=a[i];B[i]=b[i];C[i]=c[i];
	}
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	sort(c+1,c+n+1);
	for(int i=1;i<=n;i++){
		ll mx=0;
		ll x=upper_bound(a+1,a+n+1,A[i])-a-1;
		ll y=upper_bound(b+1,b+n+1,B[i])-b-1;
		ll z=upper_bound(c+1,c+n+1,C[i])-c-1;
		mx=min({n-x+1,n-y+1,n-z+1});
		cout<<mx<<el;
//		cout<<x<<" "<<y<<" "<<z<<el;
	}
}   
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
//	freopen("xxx.in","r",stdin);
//	freopen("xxx.out","w",stdout);
	ll T=1;
//	cin>>T;
	while(T--){
	    solve();
	}
	return 0;
}   
