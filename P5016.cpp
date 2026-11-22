#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n;
ll a[N];
ll m,p1,s1,s2;
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cin>>m>>p1>>s1>>s2;
    a[p1]+=s1;
    ll l=0,h=0;
    for(int i=1;i<m;i++) l+=(m-i)*a[i];
    for(int i=m+1;i<=n;i++) h+=(i-m)*a[i];
    ll mn=abs(l-h),id=m;
    for(int i=1;i<=n;i++){
        if(i<m){
            ll k=(m-i)*s2;
            if(abs(l+k-h)<mn)
                id=i,mn=abs(l+k-h);
        }else if(i>m){
            ll k=(i-m)*s2;
            if(abs(l-h-k)<mn)
                id=i,mn=abs(l-h-k);
        }
    }
    cout<<id;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}