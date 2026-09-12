#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
string n;
void solve(){
	cin>>n;
	for(int i=0;i<5;i++){
		for(int j=0;j<n.size();j++){
			if((n[j]=='0'&&(i==0||i==4))||(n[j]=='2'&&(i==0||i==4||i==2))||(n[j]=='3'&&(i==0||i==2||i==4))) cout<<".....";
			else if(n[j]=='0'&&(i==1||i==2||i==3)) cout<<".***.";
			else if(n[j]=='1') cout<<"****.";
			else if((n[j]=='2'&&i==1)||(n[j]=='3'&&(i==1||i==3))) cout<<"****.";
			else if(n[j]=='2'&&i==3) cout<<".****";
		}
		cout<<'\n';
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
