#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+5;
ll n;
ll a[N],b[N],c[N],pa[N],pb[N];
unordered_map<ll,ll> mpa,mpb;
set<ll> sa,sb;
ll cnt=0;
void Sort(ll l,ll r){
    if(l<r){
        ll mid=(l+r)/2;
        Sort(l,mid);
        Sort(mid+1,r);
        ll i=l,j=mid+1,t=l;
        while(i<=mid&&j<=r){
            if(c[i]<=c[j]) b[t++]=c[i++];
            else b[t++]=c[j++],cnt+=mid-i+1;
        }
        while(i<=mid) b[t++]=c[i++];
        while(j<=r) b[t++]=c[j++];
        for(int k=l;k<=r;k++) c[k]=b[k];
    }
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sa.insert(a[i]);
        // sb.insert(b[i]);
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
        sb.insert(b[i]);
    }
    ll k=0;
    for(auto x:sa) mpa[x]=++k;
    k=0;
    for(auto x:sb) mpb[x]=++k;
    for(int i=1;i<=n;i++){
        a[i]=mpa[a[i]];
        b[i]=mpb[b[i]];
        pa[a[i]]=i;
        pb[b[i]]=i;
    }
    for(int i=1;i<=n;i++){
        c[pb[i]]=pa[i];
    }
    
    
    for(int i=1;i<=n;i++){
        cout<<c[i]<<' ';
    }
    Sort(1,n);
    cout<<'\n'<<cnt%int(1e8-3);
    
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