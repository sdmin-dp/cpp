#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n;
void solve(){
	cin>>n;
	if(n<8){
		if(n==3) cout<<"Y 3"<<el;
		else if(n==6) cout<<"Y 3 3"<<el;
		else if(n==5) cout<<"Y 5"<<el;
		else cout<<"N "<<n<<el;
		
	}
	else{
		if(n%3==1){
			cout<<"Y ";
			for(int i=1;i<=n/3-3;i++){
				cout<<3<<" ";
			}
			cout<<"5 5"<<el;
		}
		else if(n%3==2){
			cout<<"Y ";
			for(int i=1;i<n/3;i++){
				cout<<3<<" ";
			}
			cout<<5<<el;
		}
		else if(n%3==0){
			cout<<"Y ";
			for(int i=1;i<=n/3;i++){
				cout<<3<<" ";
			}
			cout<<el;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
//	freopen("xxx.in","r",stdin);
//	freopen("xxx.out","w",stdout);
	ll T=1;
	cin>>T;
	while(T--){
		solve();
	}
}
