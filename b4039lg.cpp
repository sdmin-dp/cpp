#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
ll n,k,b,m;
string s;
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		m=s.length();
		b=0;
		for(int j=2;j<=m-2;j++){
			string s1=s.substr(0,j);
			string s2=s.substr(j,m-j);
			string t1="",t2="";
			for(int k=(int)s1.size()-1;k>=0;k--)t1+=s1[k];
			for(int k=(int)s2.size()-1;k>=0;k--)t2+=s2[k];
			if(t1==s1&&t2==s2){
				b=1;
				break;
			}
		}
		if(b)cout<<"Yes\n";
		else cout<<"No\n";
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1;
	while(T--){
		solve();
	}
	return 0;
}
