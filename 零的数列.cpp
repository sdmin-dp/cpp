#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=9+5;
ll n;
void dfs(ll x,string s){
	if(x==n){
		ll m=0;
		vector<ll> a(N,0);
		a[++m]=1;
		for(ll i=1;i<s.size();i+=2){
			if(s[i]!=' ') a[++m]=s[i+1]-48;
			else a[m]=a[m]*10+s[i+1]-48;
		}
		string q="";
		for(int i=1;i<s.size();i+=2){
			if(s[i]=='-'||s[i]=='+') q=q+s[i];
		}
		ll w=0;
		ll res=a[++w];
		for(int i=0;i<q.size();i++){
			if(q[i]=='-') res-=a[++w];
			else if(q[i]=='+') res+=a[++w];
		}
		if(res==0) cout<<s<<el;
		return;
	}
	string xs=s+char(x+1+48);
	dfs(x+1,s+' '+char(x+1+48));
	dfs(x+1,s+'+'+char(x+1+48));
	dfs(x+1,s+'-'+char(x+1+48));
}
void solve(){
	cin>>n;
	dfs(1,"1");
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
//  freopen("xxx.in","r".stdin);
//  freopen("xxx.out","w".stdout);
    ll T=1;
//  cin>>T;
    while(T--){
        solve();
    }
    return 0;
}

