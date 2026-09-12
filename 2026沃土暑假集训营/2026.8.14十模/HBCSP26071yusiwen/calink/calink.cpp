#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e5+5;
const ll inf=0x3f3f3f3f3f3f3f3f;
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
vector<pair<ll,pair<ll,ll>>> g;
void solve(){
    g.clear();
    ll n,m,k;
    cin>>n>>m>>k;
    ll mi=inf,ma=0;
    bcj a(n);
    for(int i=1;i<=m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        g.push_back({w,{u,v}});
        mi=min(mi,abs(k-w));
    }
    sort(g.begin(),g.end());
    ll cnt=0,ans=0;
    for(auto i:g){
        ll u=i.second.first,v=i.second.second,w=i.first;
        ll fu=a.find(u),fv=a.find(v);
        if(fu!=fv){
            a.fa[fu]=fv;
            cnt++;
            ma=max(ma,w);
            if(w>k) ans+=w-k;
        }
        if(cnt==n-1){
            break;
        }
    }
    if(ma<=k) cout<<mi<<el;
    else cout<<ans<<el;

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("calink.in","r",stdin);
    freopen("calink.out","w",stdout);
    ll T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}