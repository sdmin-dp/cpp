#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=5000+5;
ll n;
string s;
ll dp[N][N];
bool ispal[N][N];
void solve(){
    cin>>s;
    n=s.size();
    s=' '+s;
    for(int i=1;i<=n;i++){
        ispal[i][i]=1;
        dp[i][i]=1;
    }
    ispal[0][0]=1;
    for(ll len=2;len<=n;len++){
        for(ll l=1;l+len-1<=n;l++){
            ll r=l+len-1;
            if(s[l]==s[r]&&ispal[l+1][r-1]||s[l]==s[r]&&r-l+1==2) ispal[l][r]=1;
        }
    }
    for(ll len=2;len<=n;len++){
        for(int l=1;l+len-1<=n;l++){
            ll r=l+len-1;
            dp[l][r]=dp[l+1][r]+dp[l][r-1]-dp[l+1][r-1]+ispal[l][r];
        }
    }
    ll q;
    cin>>q;
    while(q--){
        ll l,r;cin>>l>>r;
        cout<<dp[l][r]<<el;
    }
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