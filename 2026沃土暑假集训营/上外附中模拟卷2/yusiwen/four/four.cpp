#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2000+5;
ll n;
ll a[N];
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[j]<a[i]) continue;
            for(int k=j+1;k<=n;k++){
                if(a[k]>=a[j]||a[k]<=a[i]) continue;
                for(int l=k+1;l<=n;l++){
                    if(a[l]<=a[j]) continue;
                    ans++;
                    // cerr<<i<<" "<<j<<" "<<k<<" "<<l<<el;
                }
            }
        }
    }
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("four.in","r",stdin);
    freopen("four.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}