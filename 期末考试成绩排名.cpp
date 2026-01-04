#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e2+5;
ll n;
struct node{
	ll id,ma;
	string name;
};
bool cmp(node x,node y){
	if(x.ma!=y.ma) return x.ma>y.ma;
	else return x.id<y.id;
}
node a[N];
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].id>>a[i].name>>a[i].ma;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		cout<<a[i].id<<" "<<a[i].name<<" "<<a[i].ma<<el;
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
