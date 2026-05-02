#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n;
bool isprime(ll x){
    if(x<2) return 0;
    for(ll i=2;i*i<=x;i++) if(x%i==0) return 0;
    return 1;
}
void dfs(ll x,ll prime){
    if(x==n+1){
        cout<<prime<<el;
        return;
    }
    for(int i=1;i<=9;i++){
        if(isprime(prime*10+i)){
            dfs(x+1,prime*10+i);
        }
    }
}
void solve(){
    cin>>n;
    dfs(1,0);
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