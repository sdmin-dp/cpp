#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
struct segment{
    ll l,r;
    ll sum;
    ll add_tag;
    ll mul_tag;
}t[N*4];
ll a[N];
ll n,q,mod,op,x,y,k;
void pushup(ll idx){
    t[idx].sum=(t[idx*2].sum+t[idx*2+1].sum)%mod;
}
void build(ll l=1,ll r=n,ll idx=1){
    t[idx].l=l;t[idx].r=r;t[idx].sum=0;t[idx].add_tag=0;t[idx].mul_tag=1;
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
    if(l==r) return;
    ll mid=(l+r)/2;
    t[idx*2].sum=(t[idx*2].sum*t[idx].mul_tag)%mod;
    t[idx*2].sum=(t[idx*2].sum+((t[idx*2].r-t[idx*2].l+1)*t[idx].add_tag)%mod)%mod;
    t[idx*2].mul_tag=(t[idx*2].mul_tag*t[idx].mul_tag)%mod;
    t[idx*2].add_tag=(t[idx*2].add_tag*t[idx].mul_tag+t[idx].add_tag)%mod;

    t[idx*2+1].sum=(t[idx*2+1].sum*t[idx].mul_tag)%mod;
    t[idx*2+1].sum=(t[idx*2+1].sum+((t[idx*2+1].r-t[idx*2+1].l+1)*t[idx].add_tag)%mod)%mod;
    t[idx*2+1].mul_tag=(t[idx*2+1].mul_tag*t[idx].mul_tag)%mod;
    t[idx*2+1].add_tag=(t[idx*2+1].add_tag*t[idx*2+1].mul_tag+t[idx].add_tag)%mod;

    t[idx].add_tag=0;
    t[idx].mul_tag=1;
}
void update_mul(ll s,ll e,ll k,ll idx=1){
    ll l=t[idx].l;ll r=t[idx].r;
    if(s<=l&&r<=e){
        t[idx].sum=(t[idx].sum*k)%mod;
        t[idx].add_tag=(t[idx].add_tag*k)%mod;
        t[idx].mul_tag=(t[idx].mul_tag*k)%mod;
        return;
    }
    pushdown(idx);
    ll mid=(l+r)/2;
    if(s<=mid) update_mul(s,e,k,idx*2);
    if(mid<e) update_mul(s,e,k,idx*2+1);
    pushup(idx);
}
void update_add(ll s,ll e,ll k,ll idx=1){
    ll l=t[idx].l;
    ll r=t[idx].r;
    if(s<=l&&r<=e){
        ll len=r-l+1;
        t[idx].sum=(t[idx].sum+len*k%mod)%mod;
        t[idx].add_tag+=k;
        t[idx].add_tag%=mod;
        return;
    }
    pushdown(idx);
    ll mid=(l+r)/2;
    if(s<=mid) update_add(s,e,k,idx*2);
    if(e>mid) update_add(s,e,k,idx*2+1);
    pushup(idx);
}
ll query(ll s,ll e,ll idx=1){
    ll l=t[idx].l,r=t[idx].r;
    if(s<=l&&r<=e) return t[idx].sum%mod;
    if(s>r||e<l) return 0;
    pushdown(idx);
    return (query(s,e,idx*2)+query(s,e,idx*2+1))%mod;
}
void solve(){
    cin>>n>>q>>mod;
    for(int i=1;i<=n;i++) cin>>a[i];
    build();
    while(q--){
        cin>>op;
        if(op==1){
            cin>>x>>y>>k;
            update_mul(x,y,k);
        }else{
            cin>>x>>y;
            cout<<query(x,y)<<el;
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