#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,m;
pair<ll,ll> a[N];
ll r[N];
ll lef=1e18,righ=-1e18;
bool check(ll x){
    ll last=lef,j=1;
    for(int i=2;i<=n;i++){
        if(last+x>a[j].second){
            j=lower_bound(r+1,r+m+1,last+x)-r;
            if(j>m) return 0;
        }
        last=max(last+x,a[j].first);
    }
    return 1;
}
void erfen(){
    ll l=1,r=righ-lef,mid=0,ans=0;
    while(l<=r){
        mid=(l+r)/2;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<ans;
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a[i].first>>a[i].second;
        r[i]=a[i].second;
        lef=min(a[i].first,lef),righ=max(a[i].second,righ);
    }
    sort(a+1,a+m+1);
    sort(r+1,r+m+1);
    erfen();
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("distance.in","r",stdin);
    // freopen("distance.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}