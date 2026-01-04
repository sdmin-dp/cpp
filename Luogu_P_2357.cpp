#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e5+5;
ll n,q;
ll a[N];
ll t[N],f[N];
ll lowbit(ll x){
    return x&(-x);
}
void add(ll x,ll d){
    while(x<=n){
        t[x]+=d;
        x+=lowbit(x);
    }
}
ll getsum(ll x){
    ll res=0,y=x;
    while(x>0){
        res+=y*t[x]-f[x];
        x-=lowbit(x);
    }
    return res;
}
void add2(ll x,ll d){
    while(x<=n){
        f[x]+=d;
        x+=lowbit(x);
    }
}
void solve(){
    ll op,l,r,k;
    cin>>op;
    if(op==1){
        cin>>l>>r>>k;
        add(l,k);
        add(r+1,-k);
        add2(l,k*(l-1));
        add2(r+1,-k*r);
    }
    else if(op==2){
        l=1,r=1;
        cin>>k;
        add(l,k);
        add(r+1,-k);
        add2(l,k*(l-1));
        add2(r+1,-k*r);
    }
    else if(op==3){
        l=1,r=1;
        cin>>k;
        k=-k;
        add(l,k);
        add(r+1,-k);
        add2(l,k*(l-1));
        add2(r+1,-k*r);
    }
    else if(op==4){
        cin>>l>>r;
        cout<<getsum(r)-getsum(l-1)<<"\n";
    }
    else{
        l=1,r=1;
        cout<<getsum(r)-getsum(l-1)<<"\n";
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("xxx.in","r",stdin);
    // freopen("xxx.out","w",stdout);
    int T=1;
    //cin>>T;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        add(i,a[i]-a[i-1]);
        add2(i,(a[i]-a[i-1])*(i-1));
    }
    while(q--){
        solve();
    }
    return 0;
}