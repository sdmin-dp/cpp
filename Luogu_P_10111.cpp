#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e3+5;
ll n;
ll a[N],b[N],c[N];
ll dp[N][N][3];
//dp[i][j][k] 表示第i局,换了j次牌，出k号牌的最大得分
//我是二号玩家
ll score(ll x,ll y,ll id){
    if(x==y) return a[id];
    else if((x+1)%3==y) return 2*a[id];
    else return 0;
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<n;i++) cin>>b[i];
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            for(int k=0;k<3;k++){
                ll x=-2e9;//除了本局得分的其他得分
                if(j<i-1||i==1) x=max(x,dp[i-1][j][k]);
                if(j>0) x=max(x,max(dp[i-1][j-1][(k+1)%3],dp[i-1][j-1][(k+2)%3])-b[j]);
                //dp[i-1][j-1][(k+1)%3],dp[i-1][j-1][(k+2)%3]
                //还要去掉b[j]
                dp[i][j][k]=x+score(c[i],k,i);
            }
        }
    }
    ll ans=INT_MIN;
    for(int i=0;i<n;i++){
		ans=max({ans,dp[n][i][0],dp[n][i][1],dp[n][i][2]});
	}
    cout<<ans;
}

int main() {
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