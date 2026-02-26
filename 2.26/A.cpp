#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=10+5;
string s;
ll n;
ll a[N];
ll b[N];
ll cnt=0;
void Sort(ll l,ll r){
    if(l<r){
        ll mid=(l+r)/2;
        Sort(l,mid);
        Sort(mid+1,r);
        ll i=1,j=mid+1,t=1;
        while(i<=mid&&j<=r){
            if(a[i]<=a[j]) b[t++]=a[i++];
            else b[t++]=a[j++],cnt+=mid-i+1;
        }
        while(i<=mid) b[t++]=a[i++];
        while(j<=r) b[t++]=a[j++];
        for(i=l;i<=r;i++) a[i]=b[i];
    }
}
void solve(){
    cin>>s;
    n=s.size();
    for(int i=0;i<s.size();i++) a[i+1]=s[i]-'A'+1;
    Sort(1,n);
    cout<<cnt;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("ab.in","r",stdin);
    freopen("ab.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}