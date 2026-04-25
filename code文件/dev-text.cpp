#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
string s;
map<char,ll> mp;
void solve(){
	cin>>s;
	for(auto &i:s) mp[i]++;
	//MATIJI  matiji
	ll M=mp['M'];
	ll A=mp['A'];
	ll T=mp['T'];
	ll I=mp['I']/2;
	ll J=mp['J'];
	ll m=mp['m'];
	ll a=mp['a'];
	ll t=mp['t'];
	ll i=mp['i']/2;
	ll j=mp['j'];
	ll ans1=min({M,A,T,I,J});
	ll ans2=min({m,a,t,i,j});
	cout<<ans1<<" "<<ans2;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}

