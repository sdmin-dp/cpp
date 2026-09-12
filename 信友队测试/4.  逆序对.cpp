#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,m;
ll a[N],b[N],c[N];
ll cnt;
void Sort(ll l,ll r){
    if(l<r){
        ll mid=(l+r)/2;
        Sort(l,mid);
        Sort(mid+1,r);
        ll i=l,j=mid+1,t=l;
        while(i<=mid&&j<=r){
            if(a[i]>a[j]) b[t++]=a[j++],cnt+=mid-i+1;
            else b[t++]=a[i++];
        }
        while(i<=mid) b[t++]=a[i++];
        while(j<=r) b[t++]=a[j++];
        for(i=l;i<=r;i++) a[i]=b[i];
    }
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++) a[j]=c[j];
        ll x,y;
        cin>>x>>y;
        cnt=0;
        swap(a[x],a[y]);
        Sort(1,n);
        cout<<cnt<<el;
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