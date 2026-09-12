#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
string s,t;
void solve(){
	cin>>s>>t;
	if(s=="Rock"){
		if(t=="Rock") cout<<"Tie";
		else if(t=="Scissors") cout<<"Player1";
		else cout<<"Player2";
	}
	else if(s=="Scissors"){
		if(t=="Rock") cout<<"Player2";
		else if(t=="Scissors") cout<<"Tie";
		else cout<<"Player1";
	}
	else{
		if(t=="Rock") cout<<"Player1";
		else if(t=="Scissors") cout<<"Player2";
		else cout<<"Tie";
	}
	cout<<el;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
//	freopen("xxx.in","r",stdin);
//	freopen("xxx.out","w",stdout);
	ll T=1;
	cin>>T;
	while(T--){
		solve();
	}
}
