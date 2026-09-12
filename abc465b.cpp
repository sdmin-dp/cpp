#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll x,y,l,r,a,b;
void solve(){
    cin>>x>>y>>l>>r>>a>>b;
    ll ans=0;
    for(int i=a+1;i<=b;i++){
        if(i>l&&i<=r) ans+=x;
        else ans+=y;
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