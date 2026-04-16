#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e3+5;
ll n,l,r;
ll a[N];
void solve(){
    cin>>n>>l>>r;
    for(int i=1;i<=n;i++) cin>>a[i];
    ll mn=1e12,k=0;
    for(int i=l;i<=r;i++){
        ll sum=0;
        for(int j=1;j<=n;j++){
            sum+=(a[j]%i);
        }
        if(sum<mn){
            mn=sum;
            k=i;
        }
    }
    cout<<k;
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