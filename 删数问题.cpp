#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=25e1+5;
string s;
ll k;
void solve(){
	cin>>s;
	cin>>k;
	while(k--){
		bool flag=0;
		for(int i=0;i<s.size()-1;i++){
			if(s[i]>s[i+1]){
				flag=1;
				s.erase(i,1);
				break;
			}
		}
		if(!flag) s.erase(s.size()-1,1);
	}
	while(s.size()>1&&s[0]=='0') s.erase(0,1);
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
