#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n;
ll a[N];
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        for(int j=n;j>=1;j--){
            if(a[i]!=a[j]){
                ans=max(ans,llabs(j-i));
            }
        }
    }
    cout<<ans;
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