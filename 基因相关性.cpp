#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
string s;
void solve(){
	cin>>s;
	ll cnt=1;
	for(int i=1;i<s.size();i++){
		if(s[i]!=s[i-1]){
			cout<<cnt<<s[i-1];
			cnt=1;
		}
		else{
			cnt++;
		}
	}
	cout<<cnt<<s[s.size()-1];
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
//  freopen("xxx.in","r",stdin);
//  freopen("xxx.out","w",stdout);
	ll T=1;
//  cin>>T;
	while(T--){
		solve();
	}
}

