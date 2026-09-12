#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
char a;
void solve()
{
	cin>>a;
	if(a>='0'&&a<='9') cout<<"digit";
	else if(a>='A'&&a<='Z') cout<<"upper";
	else if(a>='a'&&a<='z') cout<<"lower";
	else cout<<"other";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
//	freopen("xxx.in","r",stdin);
//	freopen("xxx.out","w",stdout);
	ll T=1;
//	cin>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}

