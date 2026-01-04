#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e3+5;
string s,a,b;
ll dp[N][N];
void solve(){
    cin>>s;
    a=s;
    reverse(s.begin(),s.end());
    b=s;
    a=' '+a;
    b=' '+b;
    for(int i=1;i<a.size();i++){
        for(int j=1;j<b.size();j++){
            if(a[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout<<s.size()-dp[a.size()-1][b.size()-1];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("xxx.in","r",stdin);
    // freopen("xxx.out","w",stdout);
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}