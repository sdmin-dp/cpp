#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
struct bcj{
    vector<ll> fa;
    bcj(ll len){
        fa.reserve(len+5);
        fa.resize(len+5);
        for(int i=1;i<=len;i++) fa[i]=i;
    }
    ll find(ll x){
        if(fa[x]==x) return x;
        else return fa[x]=find(fa[x]);
    }
};
ll n,m;
vector<pair<ll,pair<ll,ll>>> g;
ll kruskal(pair<ll,pair<ll,ll>> x){
    bcj a(n);
    ll res=0,cnt=0;
    for(auto i:g){
        ll u=i.second.first,v=i.second.second,w=i.first;
        if(u==i.second.first&&v==x.second.second&&w==x.first) continue;
        ll fu=a.find(u),fv=a.find(v);
        if(fu!=fv){
            a.fa[fv]=fu;
            res+=w;
            cnt++;
        }
        if(cnt==n-1){
            break;
        }
    }
    return res;
}
void solve(){
    cin>>n>>m;
    bcj a(n);
    for(int i=1;i<=m;i++){
        ll u,v,w;cin>>u>>v>>w;
        g.push_back({w,{u,v}});
    }
    sort(g.begin(),g.end());
    ll res=0,cnt=0;
    for(auto i:g){
        ll u=i.second.first,v=i.second.second,w=i.first;
        ll fu=a.find(u),fv=a.find(v);
        if(fu!=fv){
            a.fa[fv]=fu;
            res+=w;
            cnt++;
        }
        if(cnt==n-1){
            break;
        }
    }
    ll ans=1e18;
    cout<<res<<" ";
    for(auto i:g){
        ll x=kruskal(i);
        if(x<=res) continue;
        else ans=min(ans,x);
    }
    cout<<(ans==1e18?-1:ans);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("backup.in","r",stdin);
    freopen("backup.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}