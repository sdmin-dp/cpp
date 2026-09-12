#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e2+5;
ll n,m,k,mn=1e18;
ll a[N][N],s[N][N];
void solve(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char c;
            cin>>c;
            a[i][j]=c-48;
            s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
        }
    }
    ll ans=1e18;
    for(int lx=1;lx<=n;lx++){
        for(int ly=1;ly<=m;ly++){
            for(int rx=lx;rx<=n;rx++){
                for(int ry=ly;ry<=m;ry++){
                    ll x=s[rx][ry]-s[lx-1][ry]-s[rx][ly-1]+s[lx-1][ly-1];
                    if(x>=k&&(rx-lx+1)*(ry-ly+1)<ans) ans=(rx-lx+1)*(ry-ly+1);
                }
            }
        }
    }
    cout<<(ans==1e18?0:ans);
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