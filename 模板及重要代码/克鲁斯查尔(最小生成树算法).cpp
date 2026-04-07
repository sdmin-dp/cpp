#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
struct bcj{
    vector<ll> fa;
    bcj(ll len){
        fa.reserve(len+5);
        fa.resize(len+5);
        for(int i=1;i<=len;i++){
            fa[i]=i;
        }
    }
    ll find(ll x){
        if(fa[x]==x) return x;
        return fa[x]=find(fa[x]);
    }
};
ll n,m;
vector<pair<ll,ll>> g[N];
vector<pair<ll,pair<ll,ll>>> edge;
void solve(){
    cin>>n>>m;
    bcj a(n);
    for(int i=1;i<=m;i++){
        ll x,y,z;
        cin>>x>>y>>z;
        g[x].push_back({z,y});
        g[y].push_back({z,x});
        edge.push_back({z,{min(x,y),max(x,y)}});
    }
    sort(edge.begin(),edge.end());
    ll cnt=0;
    ll ans=0;
    for(auto i:edge){
        if(cnt==n-1){
            cout<<ans;
            return;
        }
        ll u=i.second.first,v=i.second.second,w=i.first;
        if(a.find(u)!=a.find(v)){
            cnt++;
            ans+=w;
            a.fa[a.find(u)]=a.fa[a.find(v)];
        }
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