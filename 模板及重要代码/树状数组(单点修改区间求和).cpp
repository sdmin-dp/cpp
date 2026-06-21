#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=5e5+5;
ll n,m;
ll tree[N];
ll lowbit(ll x){
    return (x&-x);
}
void add(ll x,ll k){
    for(int i=x;i<=n;i+=lowbit(i)) tree[i]+=k;
}
ll getsum(ll x){
    ll res=0;
    for(int i=x;i>=1;i-=lowbit(i)) res+=tree[i];
    return res;
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        ll x;
        cin>>x;
        add(i,x);
    }
    for(int i=1;i<=m;i++){
        ll op,x,y;
        cin>>op>>x>>y;
        if(op==1) add(x,y);
        else cout<<getsum(y)-getsum(x-1)<<el;
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