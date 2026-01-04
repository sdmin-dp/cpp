#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n;
ll a[N];
ll mx=1;
void solve(){
   cin>>n;
   for(int i=1;i<=n;i++) cin>>a[i];
   sort(a+1,a+n+1);
   n=unique(a+1,a+n+1)-a;
   for(int i=1,j=1;i<=n;i++){
        j=max(j,i+1);
        ll sum=1;
        while(j<=n&&a[j-1]+1==a[j]){
            j++;
            sum++;
        }
        mx=max(sum,mx);
   }
   cout<<mx;
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