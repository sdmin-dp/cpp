#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define el '\n'
const ll N=5e2+5;
string s;
ll ans=1e9;
string t={"cocacola"};
void dfs(ll x,ll step){
	if(s==t){
		ans=min(step,ans);
		return;
	}
	if(x==s.size()) return;
	for(int i=0;i<s.size();i++){
		if(s[x]!=s[i]){
			swap(s[x],s[i]);
			dfs(x+1,step+1);
			swap(s[x],s[i]);
		}
	}
}
void solve(){
	cin>>s;
	dfs(1,0);
	cout<<ans;
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


