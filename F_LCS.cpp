#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=3e3+5;
ll n,m;
string s,t;
ll dp[N][N];
void solve(){
    n=s.size(),m=t.size();
    s=' '+s,t=' '+t;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            if(s[i]==t[j]) dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
        }
    }
    ll i=n,j=m;
    string ans;
    while(i>=1&&j>=1){
        if(s[i]==t[j]) ans+=s[i],i--,j--;
        else if(dp[i-1][j]>dp[i][j-1]) i--;
        else j--;
    }
    reverse(ans.begin(),ans.end());
    cout<<ans;
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