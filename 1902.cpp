#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+5;
ll n;
ll x;
vector<ll> v;
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x;
        ll pos=lower_bound(v.begin(),v.end(),x)-v.begin();
        if(pos==v.size()) v.push_back(x);
        else v[pos]=x;
    }
    cout<<n-v.size();
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("xxx.in","r",stdin);
    // freopen("xxx.out","w",stdout);
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}