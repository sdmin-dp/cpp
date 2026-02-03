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
void update1(ll x,ll y,ll idx=1){
    //单点修改
    if(t[idx].l==t[idx].r&&t[idx].l==x){
        t[idx].sum+=y;
        return;
    }
    ll mid=(t[idx].l+t[idx].r)/2;
    if(x<=mid) update1(x,y,idx*2);
    else update1(x,y,idx*2+1);
    pushup(idx);
}
void update2(ll b,ll e,ll k,ll idx=1){
    //区间修改
    if(t[idx].l==t[idx].r&&t[idx].l>=b&&t[idx].r<=e){
        t[idx].sum+=k;
        return;
    }
    if(t[idx].l==t[idx].r) return;
    if(t[idx].l>e||t[idx].r>b) return;
    update2(b,e,idx*2);
    update2(b,e,idx*2+1);
    pushup(idx);
}
ll query(ll b,ll e,ll idx=1){
    ll l=t[idx].l,r=t[idx].r;
    if(b<=l&&r<=e) return t[idx].sum;
    if(b>r||e<l) return 0;
    ll mid=(l+r)/2;
    return query(b,e,idx*2)+query(b,e,idx*2+1);
}

void solve(){
//---------------------------------------------------No.1建线段树----------------------------------------------------------------------
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    build();
    //测试输出
    // for(int i=1;i<=9;i++){
    //     cout<<i<<" "<<t[i].l<<" "<<t[i].r<<" "<<t[i].sum<<el;   
    // }
//---------------------------------------------------No.2单点修改----------------------------------------------------------------------
    //将原数组中的第x个数改成y
    ll x,y;
    cin>>x>>y;
    update1(x,y);
    // for(int i=1;i<=9;i++){
    //     cout<<i<<" "<<t[i].l<<" "<<t[i].r<<" "<<t[i].sum<<el;   
    // }
//---------------------------------------------------No.3区间查询----------------------------------------------------------------------
    ll b,e;
    cin>>b>>e;
    cout<<query(b,e)<<el;
    // for(int i=1;i<=9;i++){
    //     cout<<i<<" "<<t[i].l<<" "<<t[i].r<<" "<<t[i].sum<<el;   
    // }
//---------------------------------------------------No.3区间修改----------------------------------------------------------------------
    ll k;
    cin>>b>>e>>k;
    update2(b,e,k);
    for(int i=1;i<=9;i++){
        cout<<i<<" "<<t[i].l<<" "<<t[i].r<<" "<<t[i].sum<<el;   
    }
}
int main() {
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