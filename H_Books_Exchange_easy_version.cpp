#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=200+5;
ll n;
ll a[N];
void dfs(ll b){
    ll cur=a[b],step=1;
    while(cur!=b){
        cur=a[cur];
        step++;
    }
    cout<<step<<" ";
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) dfs(i); 
    cout<<el;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}