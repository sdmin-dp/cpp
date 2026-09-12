#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+5;
ll n;
ll a[N],b[N],t[N],l[N],r[N];
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
    ll res=0;
    while(x>0){
        res+=t[x];
        x-=lowbit(x);
    }
    return res;
}
void solve(){
    cin>>n;
    set<ll> s;
    map<ll,ll> mp;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s.insert(a[i]);
    }
    ll k=0;
    for(auto x:s){
        mp[x]=++k;
    }
    for(int i=1;i<=n;i++){
        b[i]=mp[a[i]];
        // cout<<b[i]<<" ";
    }
    for(int i=1;i<=n;i++){
        add(b[i],1);
        l[i]=getsum(b[i]-1);
    }
    memset(t,0,sizeof(t));
    for(int i=n;i>=1;i--){
        add(b[i],1);
        r[i]=n-i-(getsum(b[i])-1);
    }
    ll ans=0;
    for(int i=2;i<n;i++){
        ans+=l[i]*r[i];
    }
    cout<<ans;
    // for(int i=1;i<=n;i++){
    //     cout<<l[i]<<" ";
    // }
    // cout<<"\n";
    // for(int i=1;i<=n;i++){
    //     cout<<r[i]<<" ";
    // }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("xxx.in","r",stdin);
    // freopen("xxx.out","w",stdout);
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}