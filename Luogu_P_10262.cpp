#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+5;
ll p;
string s;
ll dp[200][3];
ll ans;
void solve(){
    cin>>p;
    cin>>s;
    s=' '+s;
    // dp[0][1]=1;
    for(int i=1;i<=s.size()-1;i++){
        for(int j=0;j<p;j++){
            ll k=j*10+(s[i]-'0');
            k%=p;
            dp[k][2]+=dp[j][1];
        }
        dp[(s[i]-'0')%p][2]++;
        for(int j=0;j<p;j++){
            dp[j][1]=dp[j][2];
            dp[j][2]=0;
        }
        ans+=dp[0][1];
    }
    cout<<ans;
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