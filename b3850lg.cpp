#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=3e1+5;
string s;
ll n;
ll a[N];
void solve()
{
	cin>>s;
	n=0;
	for(int i=0;i<s.size();i++){
		n++;
		a[i+1]=int(s[i]-48);
	}
//	for(int i=1;i<=n;i++){
//		cout<<a[i];
//	}
//	cout<<n;
//	cout<<el;
	for(int i=n;i>=1;i-=2){
		ll k=a[i];
		k*=7;
		while(k>=10){
			ll cnt=0;
			while(k>=1){
				cnt+=k%10;
				k/=10;
			}
			k=cnt;
		}
		a[i]=k;
	}
	ll sum=0;
	for(int i=1;i<=n;i++){
		sum+=a[i];
	}
//	cout<<sum;
	if(sum%8==0) cout<<"T"<<el;
	else cout<<"F"<<el;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
//	freopen("xxx.in","r",stdin);
//	freopen("xxx.out","w",stdout);
	ll T=1;
	cin>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}

