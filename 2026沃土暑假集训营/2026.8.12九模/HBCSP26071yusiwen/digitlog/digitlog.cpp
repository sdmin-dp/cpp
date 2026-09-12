#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e5+5;
ll n,q;
ll tree[N];
ll a[N],d[N];
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
void archive(ll i){
    ll sum=0;
    ll x=a[i];
    while(x){
        sum+=x%10;
        x/=10;
    }
    a[i]=sum;
}
void solve(){
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=q;i++){
        ll op;
        cin>>op;
        if(op==1){
            ll l,r;
            cin>>l>>r;
            add(l,1);add(r+1,-1);
        }
        else if(op==2){
            ll x;cin>>x;
            ll t=getsum(x);
            ll k=min(3ll,t);
            while(k--) archive(x);
            cout<<a[x]<<el;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("digitlog.in","r",stdin);
    freopen("digitlog.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
/*
999999999
81
9
*/