#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=2e3+5;
string s,t;
ll dp[N][N];
void solve(){
    cin>>s>>t;
    s=' '+s;
    t=' '+t;
    for(int i=1;i<s.size();i++) dp[0][i]=i;
    for(int i=1;i<t.size();i++) dp[i][0]=i;
    for(int i=1;i<s.size();i++){
        for(int j=1;j<=t.size();j++){
            if(s[i]==t[j]) dp[i][j]=dp[i-1][j-1];
            else dp[i][j]=min({dp[i-1][j-1],dp[i][j-1],dp[i-1][j]})+1;
        }
    }
    cout<<dp[s.size()-1][t.size()-1];
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