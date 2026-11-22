#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n;
ll a[N];
ll ans=0;
void dfs(ll l,ll r,ll tag){
    ll mn=1e9,id=0;
    for(int i=l;i<=r;i++){
        if(a[i]<mn){
            id=i;
            mn=a[i];
        }
    }
    ans+=(mn-tag);
    dfs(l,id-1,mn);
    dfs(id+1,r,mn);
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1,n,0);
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