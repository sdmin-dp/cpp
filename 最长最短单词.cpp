#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
string s,t;
stringstream ss;
ll smn=1e9,smx=0;
string mn,mx;
void solve(){
	getline(cin,t);
	for(int i=0;i<t.size();i++){
		if(t[i]=='.'||t[i]==','){
			t.erase(i,1);
			t.insert(i," ");
			i--;
		}
	}
	ss<<t;
	while(ss>>s){
		if(s.size()>smx){
			smx=s.size();
			mx=s;
		}
		if(s.size()<smn){
			smn=s.size();
			mn=s;
		}
	}
	cout<<mx;
	cout<<el;
	cout<<mn;
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
