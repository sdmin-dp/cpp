#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll a,b,p;
ll safe(ll x,ll y){
	x%=p;y%=p;
	ll res=0;
	while(y>0){
		if(y%2==1) res=(res+x)%p;
		x=x*2%p;
		y/=2;
	}
	return res;
}
ll qpow(){
	ll res=1;
	if(a==0&&b==0&&p%2==1) return 0;
	while(b){
		if(b%2==1) res=safe(res,a);
		b/=2;
		a=safe(a,a);
	}
	return res;
}
void solve(){
	cin>>a>>b>>p;
	cout<<qpow()<<el;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
//	freopen("xxx.in","r",stdin);
//	freopen("xxx.out","w",stdout);
	ll T=1;
	cin>>T;
	while(T--){
		solve();
	}
}
