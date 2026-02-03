#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
struct node{
    ll l,r,sum;
}t[N*4];
ll n,m;
ll a[N];
void pushup(ll idx){
    t[idx].sum=t[idx*2].sum+t[idx*2+1].sum;
}
void build(ll l=1,ll r=n,ll idx=1){
    t[idx].l=l;
    t[idx].r=r;
    t[idx].sum=0;
    if(l==r){
        t[idx].sum=a[l];
        return;
    }
    ll mid=(l+r)>>1;
    build(l,mid,idx*2);
    build(mid+1,r,idx*2+1);
    pushup(idx);
}
ll query(ll b,ll e,ll idx=1){
    ll l=t[idx].l,r=t[idx].r;
    if(b<=l&&r<=e) return t[idx].sum;
    if(b>r||e<l) return 0;
    return query(b,e,idx*2)+query(b,e,idx*2+1);
}
void update(ll b,ll e,ll k,ll idx=1){
//    cout<<idx<<" ";
    if(t[idx].l==t[idx].r){
        if(t[idx].l>=b&&t[idx].l<=e){
            t[idx].sum+=k;
        }
        return;
    }
    if(t[idx].l>e||t[idx].r<b) return;
    update(b,e,k,idx*2);
    update(b,e,k,idx*2+1);
    pushup(idx);
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    build();
    for(int i=1;i<=m;i++){
        ll op,x,y,k;
        cin>>op;
        cout<<op<<el;
        if(op==1){
            cin>>x>>y>>k;
            update(x,y,k);
        }else{
            cin>>x>>y;
            cout<<query(x,y)<<el;
        }
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