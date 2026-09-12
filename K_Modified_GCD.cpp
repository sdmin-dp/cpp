#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll a,b,q;
vector<ll> ans;
void solve(){
    cin>>a>>b>>q;
    ll gcd=__gcd(a,b);
    for(ll i=1;i*i<=gcd;i++){
        if(gcd%i==0){
            ans.push_back(i);
            ans.push_back(gcd/i);
        }
    }
    sort(ans.begin(),ans.end());
    for(int i=1;i<=q;i++){
        ll l,r;
        cin>>l>>r;
        ll pos=upper_bound(ans.begin(),ans.end(),r)-ans.begin()-1;
        if(pos>=ans.size()||pos<0){
            cout<<-1<<el;
            continue;
        }
        if(ans[pos]>=l) cout<<ans[pos]<<el;
        else cout<<-1<<el;
    }
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