#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=2e5+5;
ll n;
ll a[N];
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    ll ans=0;
    for(int i=n;i>=1;i--){
        if(a[i]>=0){
            ans++;            
        }else{
            ll j=i;
            ll sum=a[i];
            while(sum<0){
                if(j<=0){
                    cout<<-1;
                    return;
                }
                // cerr<<sum<<" ";
                sum+=a[--j];
            }
            ans++;
            i=j-1;
        }
        cerr<<i<<" "<<ans<<" ";
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