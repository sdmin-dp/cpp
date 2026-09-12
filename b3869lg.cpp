#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
void solve()
{
	ll c,cnt=0;
	string s1,s={""};
	cin>>c;
	cin>>s1;
	stack<char> q;
	for(int i=0;i<s1.size();i++) q.push(s1[i]);
	while(!q.empty()){
		s=s+q.top();
		q.pop();
	}
//	cout<<s<<el;
	for(int i=0;i<s.size();i++){
		ll a;
		if(s[i]>='0'&&s[i]<='9') a=int(s[i]-48);
		else a=int(s[i]-'A'+10);
		a*=pow(c,i);
		cnt+=a; 
	}
	cout<<cnt<<el;
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

