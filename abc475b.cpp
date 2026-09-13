#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n;
void solve(){
    cin>>n;
    ll cnt[3]={0,0,0};
    for(int i=1;i<=n;i++){
        ll x;cin>>x;
        ll k=x/1000;
        ll ans=0;
        if(k*1000==x) ans+=k;
        else ans+=k+1;
        ans*=1000;
        ll change=ans-x;
        // cerr<<change<<" ";
        ll one=change%10,ten=change/10%10,hua=change/100;
        // cerr<<one<<" "<<ten<<" "<<hua<<el;
       cnt[0]+=one,cnt[1]+=ten,cnt[2]+=hua; 
    }
    cout<<cnt[0]<<" "<<cnt[1]<<" "<<cnt[2];
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