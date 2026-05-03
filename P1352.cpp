#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=6e3+5;
ll n;
vector<ll> g[N];
ll happy[N];
ll dep[N];
void dfs(ll u,ll fa){
    dep[u]=dep[fa]+1;
    for(auto i:g[u]) if(i!=fa) dfs(i,u);
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>happy[i];
    }
    for(int i=1;i<n;i++){
        ll u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        memset(dep,0,sizeof(dep));
        dfs(1,0);
        ll sum1=0,sum2=0;
        for(int i=1;i<=n;i++){
            if(dep[i]%2) sum1+=happy[i];
            else sum2+=happy[i];
        }
        ans=max(max(sum1,sum2),ans);
    }
    cout<<ans;
    
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