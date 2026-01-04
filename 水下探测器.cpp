#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll h,j;
string s;
void solve(){
	cin>>h>>j;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='u'&&j>0){
			j--;
		}
		else if(s[i]=='d'&&j<h){
			j++;
		}
	}
	cout<<j;
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
