#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,m;
pair<ll,pair<ll,ll>> g[N];
struct bcj{
    vector<ll> fa;
    bcj(ll len){
        fa.reserve(len+1);
        fa.resize(len+1);
        for(int i=1;i<=len;i++) fa[i]=i;
    }
    ll find(ll x){
        if(fa[x]==x) return x;
        return fa[x]=find(fa[x]);
    }
};
void solve(){
    cin>>n>>m;
    bcj a(n);
    for(int i=1;i<=n;i++){
        ll u,v,w;cin>>u>>v>>w;
        g[i].first=w;
        g[i].second={min(u,v)}
    }
    for(int i=1;i<=m;i++){

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