#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=20+5;
ll n;
bool vis[N];
bool isprime(ll x){
    if(x<2) return 0;
    for(ll i=2;i*i<=x;i++) if(x%i==0) return 0;
    return 1;
}
void dfs(ll x,string s){
    if(x==n+1){
        
    }
    if(x==1){
        vis[1]=1;
        dfs(x+1,s+'1');
        vis[1]=0;
    }
    for(ll i=1;i<=n;i++){
        if(!vis[i]){
            
        }
    }
}
void solve(){
    cin>>n;
    dfs(1,"");
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