#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
string s,a,b;
void solve(){
	cin>>s>>a>>b;
	ll pos=0;
	while(int(s.find(a,pos))!=-1){
		pos=int(s.find(a,pos));
		s.replace(pos,a.size(),b);
		pos+=b.size();
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
