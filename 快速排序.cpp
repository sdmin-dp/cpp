#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n;
ll a[N];
void qsort(ll l,ll r){
    ll i=l,j=r,x=a[l];
    while(i<=j){
        while(a[i]<x) i++;
        while(a[j]>x) j--;
        if(i<=j) swap(a[i++],a[j--]);
    }
    if(l<j) qsort(l,j);
    if(i<r) qsort(i,r);
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    qsort(1,n);
    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
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