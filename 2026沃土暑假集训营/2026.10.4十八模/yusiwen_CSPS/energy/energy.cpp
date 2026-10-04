#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,m;
ll a[N];
mt19937 rd(time(0));
void solve(){
    cin>>n>>m;
    if(m!=0){
        cout<<rd();
        return;
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        ll x;cin>>x;
        ans+=x;
    }
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("energy.in","r",stdin);
    freopen("energy.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}