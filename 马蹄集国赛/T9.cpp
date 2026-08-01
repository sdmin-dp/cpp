#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e2+5;
ll n,m,k;
ll a[N][N];
pair<ll,ll> dp[N][N];
void solve(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    ll cnt=0;
    // for(int i=1;i<=n;i++) dp[i][0]={a[i][1],a[i][1]};
    // for(int i=1;i<=m;i++) dp[0][i]={a[1][i],a[1][i]};
    for(int lx=1;lx<=n;lx++){
        for(int ly=1;ly<=m;ly++){
            memset(dp,0,sizeof(dp));
            dp[lx][ly]={a[lx][ly],a[lx][ly]};
            cerr<<lx<<" "<<ly<<el;
            for(int rx=lx;rx<=n;rx++){
                for(int ry=ly;ry<=m;ry++){
                    dp[rx][ry].first=max({dp[rx-1][ry].first,dp[rx][ry-1].first,a[rx][ry]});
                    if(rx==lx&&ry==ly) dp[rx][ry].second=a[1][1];
                    else if(rx==lx&&ry!=ly) dp[rx][ry].second=min(dp[rx][ry-1].second,a[rx][ry]);
                    else if(rx!=lx&&ry==ly) dp[rx][ry].second=min(dp[rx-1][ry].second,a[rx][ry]);
                    else dp[rx][ry].second=min({dp[rx-1][ry].second,dp[rx][ry-1].second,a[rx][ry]});
                    if(dp[rx][ry].first-dp[rx][ry].second<=k){
                        cnt++;
                        cerr<<rx<<" "<<ry<<" "<<dp[rx][ry].first<<" "<<dp[rx][ry].second<<el;
                    }
                    // cerr<<rx<<" "<<ry<<" "<<dp[rx][ry].first<<" "<<dp[rx][ry].second<<el;
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