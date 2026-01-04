#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+5;
ll n,q;
char s;
ll b[N],c[N];
vector<ll> g[N];
void dfs(ll x,ll v){
    if(v) b[x]^=1;
    for(auto i:g[x]){
        dfs(i,v^c[i]);
    }
}
void solve(){
    cin>>n;
    for(int i=2;i<=n;i++){
        ll x;cin>>x;
        g[x].push_back(i);
    }
    for(int i=1;i<=n;i++){
        cin>>s;
        b[i]=s-48;
    }
    cin>>q;
    while(q--){
        ll x;
        cin>>x;
        c[x]^=1;
    }
    dfs(1,c[1]);
    for(int i=1;i<=n;i++) cout<<b[i];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("xxx.in","r",stdin);
    // freopen("xxx.out","w",stdout);
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}