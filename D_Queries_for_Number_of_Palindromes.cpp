#include<bits/stdc++.h>
using namespace std;
#define el '\n'
const int N=5000+5;
int n;
string s;
int dp[N][N];
bool ispal[N][N];
void solve(){
    cin>>s;
    n=s.size();
    s=' '+s;
    for(int i=1;i<=n;i++){
        ispal[i][i]=1;
        dp[i][i]=1;
    }
    for(int len=2;len<=n;len++){
        for(int l=1;l+len-1<=n;l++){
            int r=l+len-1;
            if(s[l]==s[r]&&(len==2||ispal[l+1][r-1])) ispal[l][r]=1;
        }
    }
    for(int len=2;len<=n;len++){
        for(int l=1;l+len-1<=n;l++){
            int r=l+len-1;
            dp[l][r]=dp[l+1][r]+dp[l][r-1]-dp[l+1][r-1]+ispal[l][r];
        }
    }
    int q;
    cin>>q;
    while(q--){
        int l,r;cin>>l>>r;
        cout<<dp[l][r]<<el;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
