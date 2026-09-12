#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
map<char,ll> mp;
string s;
void solve(){
	mp.insert({'a',0});
	mp.insert({'b',0});
	mp.insert({'c',0});
	mp.insert({'d',0});
	mp.insert({'e',0});
	mp.insert({'f',0});
	mp.insert({'g',0});
	mp.insert({'h',0});
	mp.insert({'i',0});
	mp.insert({'j',0});
	mp.insert({'k',0});
	mp.insert({'l',0});
	mp.insert({'m',0});
	mp.insert({'n',0});
	mp.insert({'o',0});
	mp.insert({'p',0});
	mp.insert({'q',0});
	mp.insert({'r',0});
	mp.insert({'s',0});
	mp.insert({'t',0});
	mp.insert({'u',0});
	mp.insert({'v',0});
	mp.insert({'w',0});
	mp.insert({'x',0});
	mp.insert({'y',0});
	mp.insert({'z',0});
	while(cin>>s){
		for(int i=0;i<s.size();i++){
			mp[s[i]]++;
		}
	}
	for(char i='a';i<='z';i++){
		cout<<i<<':'<<mp[i]<<el;
	}
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
