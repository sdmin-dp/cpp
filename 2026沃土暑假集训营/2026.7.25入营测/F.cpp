#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e5+5;
ll n,q;
ll val[N];
vector<ll> g[N];
ll dep[N];
ll cnt=0,sum=0;
ll pre[N];
void dfs(ll x,ll fa){
    dep[x]=dep[fa]+1;
    pre[x]=fa;
    for(auto i:g[x]) if(i!=fa) dfs(i,x);
}
void dfs2(ll x,ll fa,ll b){
    for(auto i:g[x]){
        if(i==fa) continue;
        if(dep[i]%2==dep[b]%2){
            cnt++;
            sum+=val[i];
        }
        dfs2(i,x,b);
    }
}
void solve(){
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>val[i];
    }
    for(int i=1;i<n;i++){
        ll u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    for(int i=1;i<=q;i++){
        ll x;
        cin>>x;
        cnt=1,sum=val[x];
        dfs2(x,pre[x],x);
        cout<<cnt<<" "<<sum<<el;
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