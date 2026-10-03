#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=5000+5;
ll n,k;
ll a[N];
ll dp[N][N];
ll mx=-1e9,mn=1e9;
bool check(ll x){
    // len-1
    vector<int> pre1(n+1,1);
    // len-2
    vector<int> pre2(n+1,0);
    // len
    vector<int> now(n+1,0);
    for(ll len=2;len<=n;len++){
        for(ll l=1;l+len-1<=n;l++){
            ll r=l+len-1;
            ll c1=pre1[l]+1;
            ll c2=pre1[l+1]+1;
            ll c3=1e18;
            if(llabs(a[r]-a[l])<=x){
                c3=pre2[l+1];
            }
            now[l]=min({c1,c2,c3});
        }
        pre2.swap(pre1);
        pre1.swap(now);
        

    }
    return pre1[1]<=k;
}   
void erfen(){
    ll l=0,r=mx-mn+5,mid=0,ans=0;
    for(int i=1;i<=n;i++) dp[i][i]=1;
    while(l<=r){
        mid=(l+r)/2;
        if(check(mid)){
            ans=mid;
            r=mid-1;
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
        mx=max(mx,a[i]);mn=min(mn,a[i]);
    }
    erfen();
}   
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("moonmirror.in","r",stdin);
    freopen("moonmirror.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}