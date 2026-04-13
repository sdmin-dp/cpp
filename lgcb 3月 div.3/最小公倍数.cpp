#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n;
pair<ll,ll> ans={1e18,1e18};
void solve(){
    cin>>n;
    // cout<<n;
    for(ll i=sqrt(n);i>=1;i--){
        if(n%i) continue;
        if(__gcd(i,n/i)!=1) continue;
        // if(max(ans.first,ans.second)>max(i,n/i))ans={i,n/i};
        // cout<<"dog";
        cout<<min(i,n/i)<<" "<<max(i,n/i);
        break;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("lcm.in","r",stdin);
    freopen("lcm.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}//6469693230