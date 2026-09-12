#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+5;
ll n,m,op,x,y,k;
ll a[N];
ll t[N];
ll lowbit(ll x){
    return (x&-x);
}
ll getsum(ll x){
    ll res=0;
    while(x>=1){
        res+=t[x];
        x-=lowbit(x);
    }
    return res;
}
void add(ll x,ll d){
    while(x<=n){
        t[x]+=d;
        x+=lowbit(x);
    }
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        add(i,a[i]-a[i-1]);
    }
    for(int i=1;i<=m;i++){
        cin>>op;
        if(op==1){
            cin>>x>>y>>k;
            add(x,k);add(y+1,-k);
        }
        else{
            cin>>x;
            cout<<getsum(x)<<'\n';
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
}