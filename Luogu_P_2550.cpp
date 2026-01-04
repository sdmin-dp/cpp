#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+5;
ll a[8];
ll t[8];
ll ans[8];
void solve(){
    for(int i=1;i<=7;i++) cin>>a[i];
    ll cnt=0;
    for(int i=1;i<=7;i++){
        for(int j=1;j<=7;j++){
            if(a[i]==t[j]){
                cnt++;
            }
        }
    }
    ans[cnt]++;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("xxx.in","r",stdin);
    // freopen("xxx.out","w",stdout);
    int T=1;
    cin>>T;
    for(int i=1;i<=7;i++) cin>>t[i];
    while(T--){
        solve();
    }
    for(int i=7;i>=1;i--) cout<<ans[i]<<" ";
    return 0;
}