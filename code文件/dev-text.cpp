#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
struct bcj{
    vector<ll> fa;
    bcj(ll len){
        fa.reserve(len+1);
        fa.resize(len+1);
        for(int i=1;i<=len;i++) fa[i]=i;
    }
    ll find(ll x){
        if(x==fa[x]) return x;
        return fa[x]=find(fa[x]);
    }
};
ll n,m;
pair<ll,ll> a[N];
pair<ll,ll> c[N];
vector<pair<ll,ll>> g[N];
vector<array<ll,3>> e; 
ll mn=1e18,mx=-mn;
void init(){
    for(int i=1;i<=n;i++) c[i]=a[i];
}
bool check(ll x){
    bcj b(n);
    init();
    for(int i=1;i<=m;i++){
        ll u=e[i][1],v=e[i][2],w=e[i][0];
        ll fu=b.find(u),fv=b.find(v);
        if(w>x) break;
        if(fu!=fv){
            if(c[fu].first>=c[fu].second||c[fv].first>=c[fu].second){
                b.fa[fu]=fv;
                c[fu].first+=c[fv].first;
                c[fu].second+=c[fv].second;
            }
        }
    }
    bool f=1;
    for(ll i=1;i<=n;i++){
        ll fx=b.find(i);
        if(c[fx].first<c[fx].second){
            f=0;
            break;
        }
    }
    return f;
}
ll erfen(){
    ll l=mn,r=mx,mid=0,ans=-1;
    while(l<=r){
        mid=(l+r)/2;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    return ans;
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i].first;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i].second;
    }
    cin>>m;
    for(int i=1;i<=m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
        e.push_back({w,u,v});
        mn=min(mn,w);mx=min(mx,w);
    }
    sort(e.begin(),e.end());
    cout<<erfen();

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}

