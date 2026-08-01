#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=80+5;
ll n,m;
ll a[N][N];
bitset<50000> dp[N][N];
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            ll x;cin>>x;
            a[i][j]=abs(a[i][j]-x);
        }
    }
    for(int i=1;i<=n;i++){
        for(int i=1;i<=m;i++){
            
        }
    }
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