#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
string a,b; 
void solve()
{
	cin>>a>>b;
	if(a.size()<b.size()) swap(a,b);
	if(a.size()==b.size()){
		ll cnt=0;
		for(int i=0;i<a.size();i++){
			if(a[i]!=b[i]){
				a[i]=b[i];
				cnt++;
			}
		}
		if(cnt>1) cout<<"not similar"<<el;
		else cout<<"similar"<<el;
		return;
	}
	else if(a.size()-b.size()==1){
	
		ll cnt=0;
		for(int i=0;i<a.size();i++){
			if(a[i]!=b[i]){
				if(a[i+1]==b[i]){
					a.erase(i,1);
					cnt++;
				}
				else if(a[i+1]==b[i+1]){
					a[i]=b[i];
					cnt++;
				}
				else{
					cout<<"not similar"<<el;
					return;
				}
			} 
		}
		if(cnt>1) cout<<"not similar"<<el;
		else cout<<"similar"<<el;
	}
	else{
		cout<<"not similar"<<el;
		return;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
//	freopen("xxx.in","r",stdin);
//	freopen("xxx.out","w",stdout);
	ll T=1;
	cin>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}

