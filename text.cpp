#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e6+5;
ll n;
ll dp[N];
void solve(){
    cin>>n;
    cout<<dp[n]%p;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    cin>>T;
    for(int i=1;i<=N;i++){
        if(i<=4){
            dp[i]=i;
            continue;
        }
        if(i%3==0) dp[i]=dp[i-3]*3;
        else if(i%3==1) dp[i]=dp[i-4]*4;
        else if(i%3==2) dp[i]=dp[i-2]*2;
    }
    cout<<dp[6];
    while(T--){
        solve();
    }
    return 0;
}