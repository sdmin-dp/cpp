#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n;
ll cnt=0;
void dfs(ll x,ll len){
    if(x==n+1){
        cnt++;
        return;
    }
    dfs(x+1,len+1);
    if(len>0){
        dfs(x,len-1);
    }
}
void solve(){
    cin>>n;
    dfs(1);
    cout<<cnt-1;
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