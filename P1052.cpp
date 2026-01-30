#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e4+5;
ll l,s,t,m;
ll dp[N];
ll st[105];
bool book[N];
ll res=100;
void solve(){
    memset(dp,0x3f,sizeof(dp));
    cin>>l>>s>>t>>m;
    for(int i=1;i<=m;i++) cin>>st[i];
    sort(st+1,st+m+1);
    if(s==t){
        ll ans=0;
        for(int i=1;i<=m;i++){
            if(st[i]%s==0){
                ans++;
            }
        }
        cout<<ans;
        return;
    }
    ll len=0;
    for(int i=1;i<=m;i++){
        int x=st[i]-st[i-1];
        if(x>90) x=90;
        len+=x;
        book[len]=1;
    }
    dp[0]=0;
    for(int i=s;i<=len+t-1;i++){
        for(int j=i-t;j<=i-s;j++){
            if(j<0) continue;
            dp[i]=min(dp[i],dp[j]);
        }
        dp[i]+=book[i];
    }
    for(int i=len;i<=len+t-1;i++) res=min(res,dp[i]);
    cout<<res;
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
