#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e5+5;
struct bcj{
    vector<ll> fa;
    bcj(ll len){
        fa.reserve(len+5);
        fa.resize(len+5);
        for(int i=1;i<=len;i++) fa[i]=i;
    }
    ll find(ll x){
        if(x==fa[x]) return x;
        else return fa[x]=find(fa[x]);
    }
};
ll n,m;
ll child[N];
void solve(){
    cin>>n>>m;
    bcj a(n);
    for(int i=1;i<=m;i++){
        ll u,v;
        cin>>u>>v;
        ll fu=a.find(u),fv=a.find(v);
        if(fu!=fv) a.fa[fu]=fv;
    }
    for(int i=1;i<=n;i++){
        child[a.find(i)]++;
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,child[i]);
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