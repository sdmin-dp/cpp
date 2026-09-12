#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
ll n,m,g[50],half,w,ans,a[(1<<24)+1];
void dfs1(ll i,ll sum){
    if(i==half){
        a[++m]=sum;
        return;
    }
    dfs1(i+1,sum);
    if(sum+g[i]<=w) dfs1(i+1,sum+g[i]);
}
void calc(ll val){
    ll rest=w-val;
    ll l=1,r=m;
    while(l<r){
        ll mid=(l+r+1)/2;
        if(a[mid]<=rest) l=mid;
        else r=mid-1;
    }
    ans=max(ans,a[l]+val);
}
void dfs2(ll i,ll sum){
    if(i==n+1){
        calc(sum);
        return;
    }
    dfs2(i+1,sum);
    if(sum+g[i]<=w) dfs2(i+1,sum+g[i]);
}
void solve(){
    cin>>w>>n;
    for(int i=1;i<=n;i++) cin>>g[i];
    sort(g+1,g+1+n,greater<ll>());
    half=n/2+3;
    dfs1(1,0);
    sort(a+1,a+1+m);
    m=unique(a+1,a+1+m)-(a+1);
    dfs2(half,0);
    cout<<ans<<el;
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
