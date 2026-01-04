#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n;
ll a[N];
ll mn[N],s[N];
double ans[N];
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    s[n]=a[n];for(int i=n-1;i>=1;i--) s[i]=s[i+1]+a[i];
    mn[n]=a[n];for(int i=n-1;i>=1;i--) mn[i]=min(mn[i+1],a[i]);
    double mx=0.0;
    for(int i=1;i<n;i++){
        ans[i]=(s[i]-mn[i])*1.0/(n-i);
        mx=max(ans[i],mx);
    }
    for(int i=1;i<n-1;i++){
        if(ans[i+1]==mx){
            cout<<i<<el;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("xxx.in","r",stdin);
    // freopen("xxx.out","w",stdout);
    ll T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}