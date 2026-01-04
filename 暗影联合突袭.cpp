#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
struct node{
	ll x,y;
};
ll cross(node a,node b){
	return a.x*b.y-b.x*a.y;
}
void solve(){
	ll n;
	cin>>n;
	vector<node> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				node d,e;
				d.x=a[k].x-a[i].x;
				d.y=a[k].y-a[i].y;
				e.x=a[j].x-a[i].x;
				e.y=a[j].y-a[i].y;
				if(cross(d,e)==0){
					cout<<"YES"<<el;
					return;
				}
			}
		}
	}
	cout<<"NO"<<el;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
//	freopen("line.in","r",stdin);
//	freopen("line.out","w",stdout);
	ll T=1;
	cin>>T;
	while(T--){
		solve();
	}
}
