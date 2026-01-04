#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
int n;
bool vis[N];

void dfs(string s)
{
	if(s.size()==2*n){
		cout<<s<<'\n';
	}
	else{
		char c='1';
		for(int i=0;i<n;i++){
			if(vis[c+i]==0){
				vis[c+i]=1;
				dfs(s+char(c+i)+' ');
				vis[c+i]=0;
			}	
		}
	}
}
void solve()
{
	string s="";
	cin>>n;
	dfs(s);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	ll T=1;
	while(T--)
	{
		solve();
	}
	return 0;
}
