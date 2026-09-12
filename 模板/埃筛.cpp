#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n;
bool vis[N];
void prime_ai(){
    vis[0]=vis[1]=1;
    for(ll i=2;i<=n;i++){
        if(vis[i]) continue;
        for(ll j=i*i;j<=n;j+=i) vis[j]=1;
    }
}
void solve(){
    cin>>n;
    prime_ai();
    for(int i=1;i<=n;i++){
        if(vis[i]) cout<<i<<" ";
    }    
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