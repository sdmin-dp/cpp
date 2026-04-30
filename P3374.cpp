#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+5;
ll n,m;
ll a[N],c[N];
ll lowbit(ll x){
     return (x&-x);
}
ll getsum(ll x){
    ll t=0;
    while(x>0){
        t+=c[x];
        x-=lowbit(x);
    }
    return t;
}
void add(ll x,ll d){
    while(x<=n){
        c[x]+=d;
        x+=lowbit(x);
    }
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        add(i,a[i]);
    }
    for(int i=1;i<=m;i++){
        ll k,x,y;
        cin>>k>>x>>y;
        if(k==1){
            add(x,y);
        }
        else{
            cout<<getsum(y)-getsum(x-1);
            cout<<'\n';
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}