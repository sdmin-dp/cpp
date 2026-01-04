#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
bool ishw(string t){
	for(int i=0,j=t.size()-1;i<j;i++,j--){
		if(t[i]!=t[j]) return 0;
	}
	return 1;
}
string s;
void sb(){
	if(s.size()%2==0&&ishw(s)){
		s.erase(s.size()/2);
		sb();
	}
}
void solve(){
	cin>>s;
	sb();
	cout<<s.size();
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
