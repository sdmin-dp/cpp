#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,m;
void solve(){
    cin>>n>>m;
    if(m<=n){
        cout<<n-m;
        return;
    }
    ll cnt=0;
    while(m>n){
        if(m%2==0) m/=2,cnt++;
        else m++,cnt++;
    }
    cnt+=n-m;
    cout<<cnt;
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