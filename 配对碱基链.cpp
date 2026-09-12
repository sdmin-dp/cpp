#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
string s;
map<char,char> mp;
void solve(){
	cin>>s;
	mp.insert({'A','T'});
	mp.insert({'T','A'});
	mp.insert({'G','C'});
	mp.insert({'C','G'});
	for(int i=0;i<s.size();i++){
		s[i]=mp[s[i]];
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
