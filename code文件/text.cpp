#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
struct segment{
    ll l,r;
    ll sum;
    ll tag;
}t[N*4];
ll n,m;
ll a[N];
void pushup(ll idx){
    t[idx].sum=t[idx*2].sum+t[idx*2+1].sum;
}
void build(ll l=1,ll r=n,ll idx=1){
    t[idx].l=l;t[idx].r=r;
    if(l==r){
        t[idx].sum=a[l];
        return;
    }
    ll mid=(l+r)/2;
    build(l,mid,idx*2);
    build(mid+1,r,idx*2+1);
    pushup(idx);
}
void pushdown(ll idx){
    ll l=t[idx].l;
    ll r=t[idx].r;
    ll tag=t[idx].tag;
    if(l==r||tag==0) return;
    //1.将左右儿子的更新
    //2.更新左右儿子的tag
    //3.清空自己的tag
    t[idx*2].sum+=(t[idx*2].r-t[idx*2].l+1)*tag;
    t[idx*2+1].sum+=(t[idx*2+1].r-t[idx*2+1].l+1)*tag;
    t[idx*2].tag+=tag;
    t[idx*2+1].tag+=tag;
    t[idx].tag=0;
}
void update(ll s,ll e,ll k,ll idx=1){
    ll l=t[idx].l;
    ll r=t[idx].r;
    if(s<=l&&r<=e){
        ll len=r-l+1;
        t[idx].sum+=len*k;
        t[idx].tag+=k;
        return;
    }
    pushdown(idx);
    ll mid=(l+r)/2;
    if(s<=mid) update(s,e,idx*2);
    if(e>mid) update(s,e,k,idx*2+1);
    pushup(idx);
}
ll query(ll s,ll e,ll idx=1){
    ll l=t[idx].l,r=t[idx].r;
    if(s<=l&&r<=e) return t[idx].sum;
    if(s<r||e<l) return 0;
    pushdown(idx);
    return query(s,e,idx*2)+query(s,e,idx*2+1);
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    build();
    while(m--){
        ll op,x,y,k;
        cin>>op;
        if(op==1){
            cin>>x>>y>>k;
            update(x,y,k);
        }
        else{
            cin>>x>>y;
            cout<<query(x,y)<<el;
        }
    }
}
int main() {
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
