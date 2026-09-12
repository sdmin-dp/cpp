#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e9+5;
ll n;
ll cnt=0;
void dfs(string s){
	string q=s;
	ll tt=0;
	for(int i=0;i<q.size();i++) tt=tt*10+q[i]-48;
	if(tt>=1&&tt<=n) cnt++;
	if(tt>n) return;
	for(int i=0;i<=1;i++){
		dfs(s+char(i+48));
	}
}
void solve(){
	cin>>n;
	dfs("1");
	cout<<cnt;
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

