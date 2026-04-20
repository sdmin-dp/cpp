#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n;
vector<pair<ll,ll>> ans;
void pf(ll x){
    for(int i=1;i*i<=x;i++){
        if(x%i==0){
            ll cnt=0;
            while(x%i==0) cnt++;
            ans.push_back({i,cnt});
        }
    }
}
void solve(){
    cin>>n;
    ans.clear();
    pf(n);
    if(ans.size()==1){
        if(ans[0].second<6){
            cout<<
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}