#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
//const ll N=1e5+5;
struct bcj{
    vector<ll> fa;
    bcj(ll len){
        fa.reserve(len+5);
        fa.resize(len+5);
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
    if(n==1){
        cout<<0;
        return;
    }
    bcj a(n);
    for(int i=1;i<=m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        g.push_back({w,{u,v}});
    }
    sort(g.begin(),g.end());
    ll ans=0,cnt=0;
    ll sum=n;
    for(auto i:g){
        ll u=i.second.first,v=i.second.second,w=i.first;
        ll fu=a.find(u),fv=a.find(v);
        if(fu!=fv){
            ans=max(ans,w);
            a.fa[fu]=fv;
            cnt++;
            sum--;
        }
        if(cnt==n-1){
            if(sum!=1){
                cout<<-1;
                return;
            }
            cout<<ans;
            return;
        }
    }
    cout<<-1;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("level.in","r",stdin);
    freopen("level.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}