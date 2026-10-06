#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=400+5;
string s;
ll pos[3][N];
ll cnt[3];
ll dp[N][N][3];
char lltoc(ll x){return char(x+48);}
ll ctoll(char c){return c-48;}
void solve(){
	cin>>s;
	s=' '+s;
	ll n=s.size()-1;
	for(int i=1;i<=n;i++) pos[ctoll(i)][++cnt[ctoll(s[i])]]=i;

}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ll T=1;
	//cin>>T;
	while(T--){
		solve();
	}
	return 0;
}