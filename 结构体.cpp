#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e2+5;
struct cjd{
	ll ch,ma,en,zf;
	string name;
	void out(){
		cout<<name<<" "<<zf<<" "<<ch<<" "<<ma<<" "<<en<<el;
	}
	void in(){
		cin>>name>>ch>>ma>>en;zf=ch+ma+en;
	}
	bool operator< (const cjd y) const{
		if(zf!=y.zf) return zf>y.zf;
		else if(ch!=y.ch) return ch>y.ch;
		else if(ma!=y.ma) return ma>y.ma;
		else return name<y.name;
	}
};
cjd a[N];
ll n;
bool cmp(cjd x,cjd y){
	if(x.zf!=y.zf) return x.zf>y.zf;
	else if(x.ch!=y.ch) return x.ch>y.ch;
	else if(x.ma!=y.ma) return x.ma>y.ma;
	else return x.name<y.name;
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++) a[i].in();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) a[i].out();
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
