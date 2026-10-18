#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n;
char c;
ll ans;
void solve(){
    cin>>n;
    ll cnt=0;
    for(int i=1;i<=n;i++){
        cin>>c;
        if(c=='R') cnt++;
        else cnt=0;
        ans=max(ans,cnt);
    }
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}