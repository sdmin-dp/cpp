#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e5+5;
ll n,k;
ll a[N];
ll sum;
bool check(ll x){
    ll num=0,cnt=1;
    for(int i=1;i<=n;i++){
        if(a[i]>x) return 0;
        if(num+a[i]>x) cnt++,num=0;
        num+=a[i];
    }
    // if(num!=0) cnt++;
    return cnt<=k;
}
void erfen(){
    ll l=0,r=sum+5,mid=0,ans=0;
    while(l<=r){
        mid=(l+r)/2;
        if(check(mid)){
            r=mid-1;
            ans=mid;
        }else{
            l=mid+1;
        }
    }
    cout<<ans;
}
void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    erfen();
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("partition.in","r",stdin);
    freopen("partition.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}