#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+5;
ll n;
ll ans[N],t[N],a[N];
vector<ll> g[N];
ll lowbit(ll x){
    return x&(-x);
}

ll getsum(ll x){
    ll res=0;
    for(int i=x;i>0;i-=lowbit(i)){
        res+=t[i];
    }
    return res;
}
void add(ll x,ll d){
    for(int i=x;i<=n;i+=lowbit(i)){
        t[i]+=d;
    }
}
void dfs(ll x,ll fa){
    ans[a[x]]=getsum(a[x]);
    add(a[x],1);
    for(auto i:g[x]){
        if(i!=fa) dfs(i,x);
    }
    add(a[x],-1);
}
void solve(){
    cin>>n;
    for(int i=1;i<=n-1;i++){
        ll u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        ll x;cin>>x;
        a[x]=i;
    }
    dfs(1,0);
    for(int i=1;i<=n;i++) cout<<ans[i]<<'\n';
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