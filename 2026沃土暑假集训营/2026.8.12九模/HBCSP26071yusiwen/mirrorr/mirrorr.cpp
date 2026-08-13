#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=4e4+5;
const ll mod=1e9+7;
ll Q;
ll dp[N];
ll n,m;
vector<pair<ll,ll>> q[N];
vector<pair<ll,ll>> ans;
bool check(ll i){
    string s=to_string(i);
    string t=s;
    reverse(s.begin(),s.end());
    return s==t;
}
void solve(){
    cin>>Q;
    for(int i=1;i<=Q;i++){
        ll id,nn,b;
        id=i;cin>>nn>>b;
        q[b].push_back({nn,id});
        n=max(n,b);
        m=max(m,nn);
    }
    dp[0]=1;
    for(int i=1;i<=n;i++){
        if(check(i)){
            for(int j=i;j<=m;j++){
                dp[j]=(dp[j-i]+dp[j])%mod;
            }
        }
        for(auto j:q[i]){
            ans.push_back({j.second,dp[j.first]});
        }
    }
    sort(ans.begin(),ans.end());
    for(auto i:ans) cout<<i.second<<el;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("mirrorr.in","r",stdin);
    freopen("mirrorr.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}