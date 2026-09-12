#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n;
vector<ll> g[N];
ll len[N],ans[N],res=1e12;
void dfs(ll x,ll fa){
    for(auto i:g[x]){
        if(i==fa) continue;
        dfs(i,x);
        len[x]+=len[i];
    }
}
void dfs2(ll x,ll fa){
    ans[x]=max(ans[x],len[fa]);
    for(auto i:g[x]){
        if(i==fa) continue;
        ans[x]=max(ans[x],len[i]);
        ll lenx=len[x],leni=len[i];
        len[x]-=len[i];
        len[i]+=len[x];
        dfs2(i,x);
        len[x]=lenx;
        len[i]=leni;
    }
    res=min(res,ans[x]);
}
void solve(){
    cin>>n;
    for(int i=1;i<n;i++){
        ll x,y;cin>>x>>y;
        len[i]=1;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    len[n]=1;
    dfs(1,0);
    dfs2(1,0);
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