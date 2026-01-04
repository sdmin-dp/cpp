#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=20+5;
ll n,m;
ll a[N];
bool isprime(ll x){
    if(x<2) return 0;
    for(int i=2;i*i<=x;i++) if(x%i==0) return 0;
    return 1;
}
ll cnt=0;
void dfs(ll x,ll step,ll res){
    if(step==m){
        if(isprime(res)){
            cnt++;
            return;
        }
    }
    if(x==n+1) return;
    dfs(x+1,step+1,res+a[x]);
    dfs(x+1,step,res);
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    dfs(1,0,0);
    cout<<cnt;
}
int main() {
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