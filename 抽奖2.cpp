#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n;
bool vis[10]; 
void dfs(string s,ll x){
	if(x==n+1){
		cout<<s<<el;
		return; 
	}
	for(int i=1;i<=9;i++){
		if(!vis[i]){
			vis[i]=1;
			char c=char(i+48);
			string xs=s+c+" "; 
			dfs(xs,x+1); 
			vis[i]=0; 
		} 
	} 
} 
void solve(){
	cin>>n;
	dfs("",1); 
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

