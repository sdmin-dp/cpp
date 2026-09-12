#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
ll n;
string a="ABCDEFGHIJKLMNOPQRSTUVWXYZ",c;
char b;
void solve(){
	cin>>n;
	for(int i=0;i<26;i++){
		b=a[i];
		if(n%26==0){
			cout<<"ABCDEFGHIJKLMNOPQRSTUVWXYZ";
			return;
		}
		else{
			b+=n;
			if(n>26&&n%26!=0){
				b-=n;
				b+=n%26;
				if(b>'Z'){
					int d=b-'z';
					b='`'+d;
					c+=b;
				}
				else c+=b;
			}
			else if(b>'Z'){
				int d=b-'z';
				b='`'+d;
				c+=b;
			}
			else c+=b;
		}
	}
	cout<<c;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1;
	while(T--){
		solve();
	}
	return 0;
}
