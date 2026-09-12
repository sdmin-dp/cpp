#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e3+5;
struct node{
	string name;
	ll ch,ma,en;
	ll zf;
	bool operator<(const node b)const{
		name<b.name;
	}
};
node a[N];
ll n;
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].name;
		cin>>a[i].ch>>a[i].ma>>a[i].en;
		a[i].zf=a[i].ch+a[i].ma+a[i].en;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(abs(a[i].ch-a[j].ch)<=5&&abs(a[i].ma-a[j].ma)<=5&&abs(a[i].en-a[j].en)<=5&&abs(a[i].zf-a[j].zf)<=10){
				cout<<a[i].name<<" "<<a[j].name<<el;
			}
		}
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
