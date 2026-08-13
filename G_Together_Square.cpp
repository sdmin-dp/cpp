#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e5+5;
ll n;
vector<pair<ll,ll>> prime(ll n){
    vector<pair<ll,ll>> ans;
    for(ll i=2;i*i<=n;i++){
        if(n%i==0){
            ll cnt=0;
            while(n%i==0){
                cnt++;
                n/=i;
            }
            ans.push_back({i,cnt});
        }
        
    }
    if(n!=1) ans.push_back({n,1});
    return ans;
}
void solve(){
    cin>>n;
    ll res=0;
    for(int i=1;i<=n;i++){
        auto ans=prime(i);ll k=1;
        for(auto j:ans) if(j.second%2==1) k*=j.first;
        if(k>n) continue;
        ll t=sqrt(n/k);
        res+=t;
    }
    cout<<res;
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