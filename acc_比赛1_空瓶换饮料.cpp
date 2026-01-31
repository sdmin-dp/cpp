#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
string n;
ll m;
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
    cin>>n>>m;
    cout<<divideString(n,m-1);
}

int main() {
    //ios::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}