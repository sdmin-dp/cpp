#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e2+5;
ll n;
ll a[N];
string s;
void ttt(ll x){
	while(x>0){
		char c=char(x%2+48);
		x/=2;
		s=c+s;
	}
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ttt(a[i]);
	}
	ll cnt=0;
//	cout<<s;
	for(int i=0;i<s.size();i++) if(s[i]=='1') cnt++;
	cout<<cnt<<" ";
	cout<<(cnt%2==1?1:0);
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

