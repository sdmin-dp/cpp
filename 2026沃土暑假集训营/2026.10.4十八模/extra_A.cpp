#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e5+5;
ll n;
string a,b;
ll d[N];
void solve(){
    cin>>n;
    cin>>a>>b;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    ll cnt=0;
    a=' '+a,b=' '+b;
    for(int i=1;i<=n;i++){
        d[i]+=d[i-1];
        ll c=(ll)(a[i]-48);
        c=(c+d[i])%3;
        ll D=b[i]-48;
        cnt+=(D-c+3)%3;
        d[n+1]-=(D-c+3)%3;
        d[i]+=(D-c+3)%3;
    }
    cout<<cnt;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("lights.in","r",stdin);
    // freopen("lights.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}