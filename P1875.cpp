#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e3+5;
ll n;
ll a[N];
vector<ll> g[N];
ll dp[N];
ll cnt[N];
ll dfs(ll x){
    if(dp[x]!=0) return dp[x];
    if(g[x].empty()) return dp[x];
    ll sum=0,tcnt=1;
    for(auto i:g[x]){
        sum+=dfs(i);
        tcnt*=cnt[i];
    }
    if(dp[x]>=sum){
        if(dp[x]>sum) cnt[x]=tcnt;
        else cnt[x]+=tcnt;
        dp[x]=sum;
    }
    return dp[x];
}
void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        dp[i]=a[i];
        cnt[i]=1;
    }
    ll x,y,z;
    while(cin>>x>>y>>z){
        cin>>x>>y>>z;
        g[z].push_back(x);
        g[z].push_back(y);
    }
    dfs(0);
    cout<<dp[0]<<" "<<cnt[0];
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