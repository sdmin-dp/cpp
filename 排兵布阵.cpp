#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=12+5;
ll n,m;
ll s[N][N];
ll a[N][N];
ll ans;
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];s[i][j]=s[i][j-1]+s[i-1][j]-s[i-1][j-1]+a[i][j];}}
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=i;k<=n;k++){
                for(int l=j;l<=m;l++){
                    if((k-i+1)*(l-j+1)==s[k][l]-s[i-1][l]-s[k][j-1]+s[i-1][j-1]){
                        ans=max(ans,s[k][l]-s[i-1][l]-s[k][j-1]+s[i-1][j-1]);}
                    }
                }
            }
        }
    cout<<ans;
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