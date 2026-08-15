#include<bits/stdc++.h>
#define ll long long
using namespace std;
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
vector<pair<ll,pair<ll,ll>>> g;
void solve(){
    cin>>n>>m;
    bcj a(n);
    for(int i=1;i<=m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        g.push_back({w,{min(u,v),max(u,v)}});
    }
    sort(g.begin(),g.end());
    ll cnt=0,sum=0;
    for(auto i:g){
        ll w=i.first,u=i.second.first,v=i.second.second;
        ll fu=a.find(u),fv=a.find(v);
        if(fu!=fv){
            cnt++;sum+=w;
            a.fa[fu]=fv;
        }
        if(cnt==n-1){
            cout<<sum;
            return;
        }
    }
    cout<<"orz";
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