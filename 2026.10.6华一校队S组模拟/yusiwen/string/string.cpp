#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=400+5;
const ll inf=0x3f3f3f3f3f3f3f3f;
string s;
ll pos[3][N];
ll cnt[3];
ll gt[3][N][N];
ll dp[N][N][3];
ll ctoll(char c){return c-'0';}
void solve(){
    cin>>s;
    s=' '+s;
    ll n=s.size()-1;
    for(int i=1;i<=n;i++)
        pos[ctoll(s[i])][++cnt[ctoll(s[i])]]=i;
    for(int i=0;i<3;i++){
        if(cnt[i]>(n+1)/2){
            cout<<-1;
            return;
        }
    }
    for(ll x=0;x<3;x++){
        for(ll k=1;k<=cnt[x];k++){
            for(ll p=1;p<=n;p++){
                gt[x][k][p]=gt[x][k-1][p]+(pos[x][k]>p);
            }
        }
    }
    memset(dp,0x3f,sizeof(dp));
    dp[0][0][0]=0;
    dp[0][0][1]=0;
    dp[0][0][2]=0;
    for(ll i=1;i<=n;i++){
        for(ll a=min(i,cnt[0]);a>=0;a--){
            for(ll b=min(i-a,cnt[1]);b>=0;b--){
                ll c=i-a-b;
                if(c<0||c>cnt[2]) continue;
                ll x0=inf,x1=inf,x2=inf;
                if(a>0){
                    ll p=pos[0][a];
                    x0=min(dp[a-1][b][1],dp[a-1][b][2])+gt[1][b][p]+gt[2][c][p];
                }
                if(b>0){
                    ll p=pos[1][b];
                    x1=min(dp[a][b-1][0],dp[a][b-1][2])+gt[0][a][p]+gt[2][c][p];
                }
                if(c>0){
                    ll p=pos[2][c];
                    x2=min(dp[a][b][1],dp[a][b][0])+gt[0][a][p]+gt[1][b][p];
                }
                dp[a][b][0]=x0;
                dp[a][b][1]=x1;
                dp[a][b][2]=x2;
            }
        }
    }
    ll ans=min({dp[cnt[0]][cnt[1]][0],dp[cnt[0]][cnt[1]][1],dp[cnt[0]][cnt[1]][2]});
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}