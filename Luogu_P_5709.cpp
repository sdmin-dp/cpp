#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll t,m,s;
void solve(){
    cin>>m>>t>>s;
    if(t==0){cout<<0<<endl;return;}
	if(s%t==0) cout<<max(m-s/t,0ll)<<endl;
	else cout<<max(m-s/t-1,0ll)<<endl;
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