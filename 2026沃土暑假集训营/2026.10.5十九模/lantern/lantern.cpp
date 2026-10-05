#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1500+5;
ll n,m,q,mn;
ll a[N][N];
void solve(){
    cin>>n>>m>>q>>mn;
    for(int k=1;k<=q;k++){
        ll x,y,r;cin>>x>>y>>r;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(llabs(i-x)+llabs(j-y)<=r){
                    a[i][j]++;
                }
            }
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]>=mn){
                ans++;
            }
        }
    }
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("lantern.in","r",stdin);
    freopen("lantern.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}