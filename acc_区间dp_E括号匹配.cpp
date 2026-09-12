#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const int N = 205; 
string s;
int dp[N][N];
bool check(int i, int j) {
    if (s[i]=='('&&s[j]==')') return 1;
    if (s[i]=='['&&s[j]==']') return 1;
    return 0;
}
void solve(){
    cin>>s;
    int n=s.size();
    s=' '+s;
    memset(dp,0x3f,sizeof(dp));
    for (int i=1;i<=n;i++) {
        dp[i][i]=1;
        dp[i+1][i]=0;
    }
    for(int len=2;len<=n;len++) {
        for (int l=1;l+len-1<=n;l++) {
            int r=l+len-1;
            if (check(l,r)) {
                dp[l][r]=min(dp[l][r],dp[l+1][r-1]);
            }
            for (int k=l;k<r;k++){
                dp[l][r]=min(dp[l][r],dp[l][k]+dp[k + 1][r]);
            }
        }
    }
    
    cout<<dp[1][n]<<el;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}