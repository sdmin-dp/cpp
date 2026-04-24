
    cin>>s;
    n=s.size();
    s=' '+s;
    for(int len=2;len<=n;len++){
        for(int i=1;i+len-1<=n;i++){
            ll j=i+len-1;
            if(s[i]==s[j]) dp[i][j]=dp[i+1][j-1];
            else dp[i][j]=min(dp[i+1][j],dp[i][j-1])+1;
        }
    }
    cout<<dp[1][n];
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