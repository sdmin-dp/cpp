#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e2+5;
ll n,m,k;
ll a[N][N];

void solve(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    ll cnt=0;
    for(int lx=1;lx<=n;lx++){
        for(int ly=1;ly<=n;ly++){
            pair<ll,ll> dp={a[lx][ly],a[lx][ly]};
            for(int rx=lx;rx<=n;rx++){
                for(int ry=ly;ry<=n;ry++){
                    dp.first=max(dp.first,a[rx][ry]);
                    dp.second=min(dp.second,a[rx][ry]);
                    // cerr<<lx<<" "<<ly<<" "<<rx<<" "<<ry<<el;
                    if(dp.first-dp.second<=k){
                        cnt++;
                        
                        cerr<<dp.first<<" "<<dp.second<<" "<<lx<<" "<<ly<<" "<<rx<<" "<<ry<<el;
                    }
                }
            }
        }
    }
    cout<<cnt;
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