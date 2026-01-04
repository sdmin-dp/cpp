#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll t;
string s;
void solve(){
	cin>>s;
	cin>>t;
	for(int i=0;i<s.size();i++){
		if(s[i]>='A'&&s[i]<='Z'){
			ll k=s[i]+t-65;
			k%=26;
			k+=65;
			s[i]=char(k);
		}
		else{
			ll k=s[i]+t-97;
			k%=26;
			k+=97;
			s[i]=char(k);
		}
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
