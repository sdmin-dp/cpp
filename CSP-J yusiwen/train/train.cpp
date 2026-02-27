#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=5e2+5;
ll n,m;
vector<ll> g[N];
ll fa[N];
ll sz[N];
ll find(ll x){
    if(x==fa[x]) return x;
    return fa[x]=find(fa[x]);
}
void add(ll x,ll Y){
    x=find(x),Y=find(Y);
    if(x!=Y) fa[x]=Y;
}
void solve(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        g[i].clear();
        fa[i]=i;
        sz[i]=0;
    }
    for(int i=1;i<=m;i++){
        ll x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
        add(x,y);
    }
    ll cnt=0;
    for(int i=0;i<n;i++){
        if(g[i].size()%2!=0) cnt++;
    }
    for(int i=0;i<n;i++){
        if(!g[i].empty()){
            sz[find(i)]++;
        }
    }
    ll num_comp=0;
    for(int i=0;i<n;i++){
        if(fa[i]==i && sz[i]>0) num_comp++;
    }
    if((cnt==0 || cnt==2) && num_comp<=1) cout<<"YES"<<el;
    else cout<<"NO"<<el;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("train.in","r",stdin);
    // freopen("train.out","w",stdout);
    ll T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
