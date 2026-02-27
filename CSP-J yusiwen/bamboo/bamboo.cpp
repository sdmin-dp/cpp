#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=55;
ll n,c,res;
ll l[N],w[N];
ll dp[N][N][N];
void solve(){
    if(!(cin>>n>>c))return;
    for(int i=1;i<=n;i++)cin>>l[i];
    for(int i=1;i<=n;i++)cin>>w[i];
    memset(dp,-1,sizeof dp);
    for(int i=1;i<=n;i++){
        // 初始化前两根竹子组合的长度和成本
        for(int j=1;j<=n;j++){
            if(l[i]==l[j])continue;
            if(w[i]+w[j]>c)continue;
            dp[w[i]+w[j]][i][j]=max(dp[w[i]+w[j]][i][j],l[i]+l[j]);
        }
    }
    for(int cost=0;cost<=c;cost++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dp[cost][i][j]==-1)continue;
                // 前两根竹子组合的成本为cost时，长度为l[i]和l[j]的竹子组合不存在
                for(int k=1;k<=n;k++){
                    if(l[k]==l[i])continue;
                    if(l[k]==l[j])continue;//不能相等的
                    if(l[j]>l[i]&&l[k]>l[j])continue;//不能是递增的
                    if(l[j]<l[i]&&l[k]<l[j])continue;//不能是递减的
                    if(cost+w[k]>c)continue; // 加上新竹子的成本不能超过总成本
                    if(dp[cost+w[k]][j][k]<dp[cost][i][j]+l[k]){
                        dp[cost+w[k]][j][k]=dp[cost][i][j]+l[k];
                        res=max(res,dp[cost+w[k]][j][k]);//保证至少有三根竹子
                    }
                }
            }
        }
    }
    cout<<res<<el;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("bamboo.in","r",stdin);
    freopen("bamboo.out","w",stdout);
    ll T=1;
    while(T--){
        solve();
    }
    return 0;
}
