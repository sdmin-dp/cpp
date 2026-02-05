#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
struct segment{
    double sum1,sum2;
    double tag;
    ll l,r;
}t[N*4];
ll n,q,x,y,op;
double k;
double a[N];
void pushup(ll idx){
    t[idx].sum1=t[idx*2].sum1+t[idx*2+1].sum1;
    t[idx].sum2=t[idx*2].sum2+t[idx*2+1].sum2;
}
void build(ll l=1,ll r=n,ll idx=1){
    t[idx].l=l;
    t[idx].r=r;
    t[idx].sum1=t[idx].sum2=t[idx].tag=0.0;
    if(l==r){
        t[idx].sum1=a[l];
        t[idx].sum2=a[l]*a[l];
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
    if(l==r||t[idx].tag==0) return;

    ll len1=t[idx*2].r-t[idx*2].l+1;
    ll len2=t[idx*2+1].r-t[idx*2+1].l+1;

    t[idx*2].sum2+=len1*t[idx].tag*t[idx].tag+2*t[idx].tag*t[idx*2].sum1;
    t[idx*2+1].sum2+=len2*t[idx].tag*t[idx].tag+2*t[idx].tag*t[idx*2+1].sum1;

    t[idx*2].sum1+=len1*t[idx].tag;
    t[idx*2+1].sum1+=len2*t[idx].tag;

    t[idx*2].tag+=t[idx].tag;
    t[idx*2+1].tag+=t[idx].tag;

    t[idx].tag=0;

}
void update(ll s,ll e,double k,ll idx=1){
    ll l=t[idx].l;
    ll r=t[idx].r;
    if(s<=l&&r<=e){
        ll len=r-l+1;
        t[idx].sum2+=len*k*k+2*k*t[idx].sum1;
        t[idx].sum1+=len*k;
        t[idx].tag+=k;
        return;
    }
    pushdown(idx);
    ll mid=(l+r)/2;
    if(s<=mid) update(s,e,k,idx*2);
    if(mid<e) update(s,e,k,idx*2+1);
    pushup(idx);
}
double ask1(ll s,ll e,ll idx=1){
    ll l=t[idx].l,r=t[idx].r;
    if(s<=l&&r<=e) return t[idx].sum1;
    if(s>r||e<l) return 0;
    pushdown(idx);
    return (ask1(s,e,idx*2)+ask1(s,e,idx*2+1));
}
double ask2(ll s,ll e,ll idx=1){
    ll l=t[idx].l,r=t[idx].r;
    if(s<=l&&r<=e) return t[idx].sum2;
    if(s>r||e<l) return 0;
    pushdown(idx);
    return (ask2(s,e,idx*2)+ask2(s,e,idx*2+1));
}
double query1(ll l,ll r){
    ll len=r-l+1;
    return ask1(l,r)/(len*1.0);
}
double query2(ll l,ll r){
    double res1=ask1(l,r);
    double res2=ask2(l,r);
    ll len=r-l+1;
    return res2/len-(res1/len)*(res1/len);
}
void solve(){
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    build();
    while(q--){
        cin>>op;
        if(op==1){
            cin>>x>>y>>k;
            update(x,y,k);
        }else if(op==2){
            cin>>x>>y;
            printf("%.4lf\n",query1(x,y));
        }else{
            cin>>x>>y;
            printf("%.4lf\n",query2(x,y));
        }
    }
}
int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}