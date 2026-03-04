#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll k,n,m;
ll cnt;
void dfs(ll x,ll last){
    if(x==n+1){
        cnt++;
        return;
    }
    for(int i=last;i<=m;i++){
        dfs(x,i);
    }
}
void solve(){
    cin>>k;
    if(k!=1) return;
    cin>>n>>m;
    dfs(1,0);
    cout<<cnt;
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