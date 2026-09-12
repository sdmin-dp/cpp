#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e3+5;
ll dp[N][N];
string s,t;
void solve(){
    cin>>s>>t;
    for(int i=0;i<s.size();i++){
        for(int j=0;j<t.size();j++){
            if(s[i]==t[j]){
                dp[i+1][j+1]=dp[i][j]+1;
            }else{
                dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
            }
        }
    }
    ll i=s.size(),j=t.size();
    string ans;
    while(i>0&&j>0){
        if(s[i-1]==t[j-1]){
            i--,j--;
            ans=s[i-1]+ans;
        }
        else if(dp[i][j-1]<=dp[i-1][j]) j--;
        else i--;
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