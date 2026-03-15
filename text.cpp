#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e6+5;
const ll p=1e9;
ll n;
ll dp[N];
void solve(){
    cin>>n;
    cout<<dp[n];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    cin>>T;
    for(int i=1;i<=N;i++){
        if(i<=4){dp[i]=i;continue;}
        if(i%3==0) dp[i]=max(dp[i-3]*3,dp[i-4]*4,dp[i-2]*2);
    }
    while(T--){
        solve();
    }
    return 0;
}   