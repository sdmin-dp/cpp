#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
string s;
string ans;
void solve(){
	cin>>s;
	for(int i=0;i<s.size()-1;i++){
		char c=s[i]+s[i+1];
		ans=ans+c;
	}
	ans=ans+char(s[s.size()-1]+s[0]);
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
