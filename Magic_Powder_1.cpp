#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e3+5;
const ll inf=1e12;
ll n,m;
ll a[N];
ll b[N];
bool check(ll x){
    ll t=m;
    for(int i=1;i<=n;i++){
        ll ned=x*a[i];
        if(b[i]>=ned){}
        else if(b[i]+t>=ned){
            ned-=b[i];
            t-=ned;
        }else{
            return 0;
        }
    }
    return 1;
}
void erfen(){
    ll l=0,r=inf,mid,ans;
    while(l<=r){
        mid=(l+r)/2;
        if(check(mid)){
            l=mid+1;
            ans=mid;
        }else{
            r=mid-1;
        }
    }
    cout<<ans;
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    erfen();
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