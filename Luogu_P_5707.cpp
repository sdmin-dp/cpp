#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;

void solve(){
    double s,v;
	cin>>s>>v;
	int t1=ceil(s/v)+10;
	int t2=8*60-t1;
	if(t2<0){
	t2=t2+24*60;
	}
	int HH=t2/60;
	int MM=t2%60;
	if(HH<10){
	cout<<"0";
	}
	cout<<HH<<":";
	if(MM<10){
	cout<<"0";
	}
	cout<<MM;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("xxx.in","r",stdin);
    // freopen("xxx.out","w",stdout);
    ll T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}