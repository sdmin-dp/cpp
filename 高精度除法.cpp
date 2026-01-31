#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
string divideString(string dividend,ll divisor){
	ll remainder=0;
	string quotient;
	for(char c:dividend){
		remainder=remainder*10+(c-'0');
		quotient+=char(remainder/divisor+'0');
		remainder%=divisor;
	}
	ll pos=0;
	while(pos<quotient.size()&&quotient[pos]=='0')pos++;
	if(pos==quotient.size())return"0";
	return quotient.substr(pos);
}
void solve(){
	string s;
	ll n;
	cin>>s>>n;
	cout<<divideString(s,n);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	ll T=1;
	while(T--){
		solve();
	}
}