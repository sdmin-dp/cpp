#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e6+5;
struct Segment{
    ll l,r;
    ll sum;
}t[N<<2];
ll n,m;
ll a[N];
void pushup(ll idx){
    t[idx].sum=t[idx*2].sum+t[idx*2+1].sum;
}
void build(ll l=1,ll r=n,ll idx=1){
    t[idx].l=l;
    t[idx].r=r;
    if(l==r){
        t[idx].sum=a[l];
        return;
    }
    ll mid=(l+r)>>1;
    build(l,mid,idx*2);
    build(mid+1,r,idx*2+1);
    pushup(idx);
}
void update(ll x,ll y,ll idx=1){
    if(t[idx].l==t[idx].r&&t[idx].l==x){
        t[idx].sum+=y;
        return;
    }
    ll mid=(t[idx].l+t[idx].r)/2;
    if(x<=mid) update(x,y,idx*2);
    else update(x,y,idx*2+1);
    pushup(idx);
}
ll query(ll b,ll e,ll idx=1){
    ll l=t[idx].l;
    ll r=t[idx].r;
    if(b<=l&&r<=e) return t[idx].sum;
    ll mid=(l+r)/2;
    ll sum=0;
    if(b<=mid) sum+=query(b,e,idx*2);
    if(mid<e) sum+=query(b,e,idx*2+1);
    return sum;
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    build();
    // ll b,e;
    // cin>>b>>e;
    // cout<<query(b,e);
    for(int i=1;i<=m;i++){
        ll op,x,y;
        cin>>op>>x>>y;
        if(op==1) update(x,y);
        else cout<<query(x,y)<<el;
    }
}
int main(){
    //ios::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}