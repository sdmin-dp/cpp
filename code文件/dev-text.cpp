#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n;
map<ll,string> mp;
bool isnum(char c){
	return (c>='0'&&c<='9');
}
vector<pair<ll,ll>> v;
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		ll x;string t;
		cin>>x;
		cin>>t;
		mp[x]=t;
	}
	string s,t;
	cin>>s;
	getline(cin,t);
	s=s+t;
	for(int i=0;i<s.size();i++){
		if(s[i]=='#'){
			ll x=0;
			i++;
			ll len=0;
			while(i<s.size()&&isnum(s[i])){
				x=x*10+int(s[i]-48);
				i++;
			}
			i--;
			v.push_back({x,i});
		}
	}
	ll cnt=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='#'){
			cout<<mp[v[cnt].first];
			i=v[cnt].second;
			cnt++;
		}else{
			cout<<s[i];
		}
	}
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

