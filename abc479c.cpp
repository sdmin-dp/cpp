//暴力枚举选不选
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=20+5;
ll n,m;
ll w[N],v[N];
ll ans=0;
void dfs(ll x,ll sum_w,ll sum_v){
    if(sum_w>m) return;
    if(x==n+1){
        ans=max(ans,sum_v);
        return;
    }
    dfs(x+1,sum_w,sum_v);
    dfs(x+1,sum_w+w[x],sum_v+v[x]);
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>v[i]>>w[i];
    }
    dfs(1,0,0);
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}