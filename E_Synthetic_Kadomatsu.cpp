#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,t1,t2,t3;
ll arr[N];
ll ans=1e12;
void dfs(ll x,ll a,ll b,ll c,ll sa,ll sb,ll sc){
    if(x==n+1){
        if(sa==0||sb==0||sc==0) return;
        ans=min(ans,sa*10-10+sb*10-10+sc*10-10+abs(t1-a)+abs(t2-b)+abs(t3-c));
        return;
    }
    dfs(x+1,a+arr[x],b,c,sa+1,sb,sc);
    dfs(x+1,a,b,c+arr[x],sa,sb,sc+1);
    dfs(x+1,a,b+arr[x],c,sa,sb+1,sc);
    dfs(x+1,a,b,c,sa,sb,sc);
}
void solve(){
    cin>>n>>t1>>t2>>t3;
    for(int i=1;i<=n;i++) cin>>arr[i];
    dfs(1,0,0,0,0,0,0);
    cout<<ans;
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