#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e3+5;
string s;
ll k;
ll mp[27];
bool vis[N];
void solve(){
	cin>>s;
	cin>>k;
	ll q;
	for(int i=0;i<s.size();i++) mp[s[i]-'a'+1]++;
	for(char i=1;i<=26;i++){
		while(mp[i]>k){
			for(int j=s.size()-1;j>=0;j--){
				if(s[i]==char(i+'a'-1)){
					q=j;
					break;
				}
			}
			vis[q]=1;
			mp[i]--;
		}
	}
	vis[q]=0;
	for(int i=0;i<s.size();i++){
		if(!vis[i]){
			cout<<s[i];
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll T=1;
//	cin>>T;
	while(T--){
		solve();
	}
}
