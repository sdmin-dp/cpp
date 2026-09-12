#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e2+5;
ll n;
ll x[N],y[N];
bool vis[N];
void dfs(ll u){
    vis[u]=1;
    for(int v=1;v<=n;v++){
        if(!vis[v] && (x[u]==x[v] || y[u]==y[v])){
            dfs(v);
        }
    }
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>x[i]>>y[i];
    ll cnt=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            cnt++;
            dfs(i);
        }
    }
    cout<<cnt-1<<el;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
