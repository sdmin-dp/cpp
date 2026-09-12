#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e3+5;
ll n;
string a[105],b[105];
string x;
string s[N]; 
string ans;
ll m=1;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
	cin>>x;
	for(int i=0;i<x.size();i++){
		if(x[i]>='a'&&x[i]<='z'){
			s[m]=s[m]+x[i];
		}
		else{
			++m;
			s[m]=s[m]+x[i];
			++m;
		}
	}
	for(int i=1;i<=m;i++){
		if(s[i][0]>='a'&&s[i][0]<='z'){
			bool flag=0;
			for(int j=1;j<=n;j++){
				if(s[i]==a[j]){
					s[i]=b[j];
					flag=1;
					break;
				}
			}
			if(!flag) s[i]="UNK";
		}
		ans=ans+s[i];
	}
	cout<<ans;
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

