#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e5+5;
ll n;
ll a[N],t[N],lmin[N],rmin[N],lmax[N],rmax[N];
set<ll> s;
unordered_map<ll,ll> mp;
ll lowbit(ll x){
    return x&(-x);
}
void add(ll x){
    while(x<=n){
        t[x]++;
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
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s.insert(a[i]);
    }
    ll k=0;
    for(auto x:s) mp[x]=++k;
    for(int i=1;i<=n;i++) a[i]=mp[a[i]];
    for(int i=1;i<=n;i++){
        lmin[i]=getsum(a[i]-1);
        lmax[i]=i-1-(getsum(a[i]));
        add(a[i]);
    }
    memset(t,0,sizeof(t));
    for(int i=n;i>=1;i--){
        rmin[i]=getsum(a[i]-1);
        rmax[i]=n-i-(getsum(a[i]));
        add(a[i]);
    }
    ll ans1=0,ans2=0;
    for(int i=1;i<=n;i++){
        ans1+=lmin[i]*rmin[i];
        ans2+=lmax[i]*rmax[i];
    }
    cout<<ans2<<" "<<ans1;
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