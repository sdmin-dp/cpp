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
bcj a(n);
void solve(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        ll x,y,z;
        cin>>x>>y>>z;
        g[x].push_back({z,y});
        g[y].push_back({z,x});
    }
    for(int i=1;i<=n;i++) sort(g[i].begin(),g[i].end());
    ll cnt=0;
    ll ans=0;
    for(int i=1;i<=n;i++){
        for(auto j:g[i]){
            if(cnt==n-1){
                cout<<ans;
                return;
            }
            
            if(a.find(i)!=a.find(j.second)){
                ans+=j.first;
                cnt++;
                ll x=a.find(i),y=a.find(j.second);
                a.fa[x]=y;
            }
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