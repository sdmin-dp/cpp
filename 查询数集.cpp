#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;

void solve()
{
	ll a,n;
	while(cin>>a>>n){
		queue<ll> q1;
		queue<ll> q2;
		if(n==1) cout<<a<<" ";
		else{
			n--;
			q1.push(2*a+1);
			q2.push(3*a+1);
			while(n--){
				if(q1.front()<q2.front()){
					a=q1.front();
					q1.pop();
				}
				else if(q2.front()<q1.front()){
					a=q2.front();
					q2.pop();
				}
				else if(q2.front()==q1.front()){
					a=q1.front();
					q1.pop();
					q2.pop();
				}
				q1.push(2*a+1);
				q2.push(3*a+1);
			}
			cout<<a<<" ";
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
//	freopen("xxx.in","r",stdin);
//	freopen("xxx.out","w",stdout);
	ll T=1;
//	cin>>T;
	while(T--) solve();
	return 0;
}

