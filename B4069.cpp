#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e2+5;
ll n;
string s[N],t;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>s[i];
	sort(s+1,s+n+1);
	t={""};
	for(int i=1;i<=n;i++){
		t=t+s[i];
	}
	for(int i=1;i<t.size();i++){
		if(t[i]<t[i-1]){
			cout<<0<<el;
			return;
		}
	}
	cout<<1<<el;
//	cout<<t<<el;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	//freopen("xxx.in","r",stdin);
	//freopen("xxx.out","w",stdout);
	ll T=1;
	cin>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}

