#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,s;
void solve(){
    cin>>n>>s;
    ll x=s/n;
    ll ans=1;
    for(int i=1;i*i<=s;i++){
        if(s%i==0){
            ll u=i,v=(s/i);
            if(u<=x) ans=max(ans,u);
            if(v<=x) ans=max(ans,v);
        }
        
    }
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}