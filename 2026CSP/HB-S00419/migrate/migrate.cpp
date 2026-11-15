#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e6+5;
ll op;
ll n,d;
ll a[N];
void solve(){
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(op==11||op==12){
        ll x=a[2]-a[1];
        if(!(2*x<=d&&d<3*x)){
            cout<<0<<el;
            return;            
        }else{
            cout<<n-((2*x)*3/2)<<el;
        }
    }else if(op==13||op==14){
        cout<<0<<el;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>op;
    ll T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}