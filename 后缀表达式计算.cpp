#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll a[N],top;
void solve()
{
	stringstream ss;
	string s,t;
	getline(cin,s);
	ss<<s;
	while(ss>>t){
		if(t=="+"||t=="-"||t=="*"||t=="/"){
			ll y=a[top];top--;
			ll x=a[top];top--;
			if(t=="+") a[++top]=x+y;
			else if(t=="-") a[++top]=x-y;
			else if(t=="*") a[++top]=x*y;
			else a[++top]=x/y;
		}
		else{
			a[++top]=stoll(t);
		}
	}
	cout<<a[top]<<el;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
//	freopen("xxx.in","r",stdin);
//	freopen("xxx.out","w",stdout);
	ll T=1;
//	cin>>T;
	while(T--) solve();
	return 0;
}

