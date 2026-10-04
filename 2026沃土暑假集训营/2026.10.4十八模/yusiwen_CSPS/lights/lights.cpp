#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e5+5;
ll n,k;
string a,b;
ll d[N];
ll ans[N];
void solve(){
    cin>>n>>k;
    cin>>a>>b;
    a=' '+a,b=' '+b;
    ll cnt=0;
    for(int i=1;i<=n-k+1;i++){
        d[i]+=d[i-1];
        ll c=(ll)(a[i]-48);
        c=(c+d[i])%3;
        ll D=b[i]-48;
        ans[i]=(D-c+3)%3;
        cnt+=ans[i];
        d[i]+=ans[i];
        d[i+k]-=ans[i];
    }
    for(int i=n-k+2;i<=n;i++){
        d[i]+=d[i-1];
        ll c=(ll)(a[i]-48);
        c=(c+d[i])%3;
        ll d=b[i]-48;
        if(c!=d){
            cout<<-1;
            return;
        }
    }
    cout<<cnt<<el;
    for(int i=1;i<=n-k+1;i++){
        cout<<ans[i]<<" ";
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("lights.in","r",stdin);
    freopen("lights.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}