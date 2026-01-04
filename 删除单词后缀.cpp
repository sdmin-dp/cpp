#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
string s;
void solve(){
	cin>>s;
	if(s[s.size()-1]=='r'||s[s.size()-2]=='e'){
		s.erase(s.size()-2,2);
	}
	else if(s[s.size()-1]=='y'||s[s.size()-2]=='l'){
		s.erase(s.size()-2,2);
	}
	else if(s[s.size()-1]=='g'||s[s.size()-2]=='n'||s[s.size()-3]=='i'){
		s.erase(s.size()-3,3);
	}
	cout<<s;
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
