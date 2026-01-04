#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=3e5+5;
ll n,cnt;
ll a[N],b[N];
void Sort(ll l,ll r){
    if(l<r){
        ll mid=(l+r)/2;
        Sort(l,mid);
        Sort(mid+1,r);
        ll i=l,j=mid+1,t=l;
        while(i<=mid&&j<=r){
            if(a[i]<=a[j]) cnt+=r-j+1,b[t++]=a[i++];
            else b[t++]=a[j++];
        }
        while(i<=mid) b[t++]=a[i++];
        while(j<=r) b[t++]=a[j++];
        for(i=l;i<=r;i++) a[i]=b[i];
    }
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    Sort(1,n);
    cout<<cnt;
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