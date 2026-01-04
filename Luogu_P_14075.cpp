#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+5;
ll n;
string s;
ll a[N],dp[N];
void solve(){
    cin>>n;
    cin>>s;
    s=' '+s;
    for(int i=1;i<=n;i++) cin>>a[i];
    ll ans=0;
    dp[1]=a[1];
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+a[1];
        set<char> st;st.insert(s[i]);
        for(int j=i-1;j>=1;j--){
            if(st.count(s[j])) break;
            st.insert(s[j]);
            dp[i]=max(dp[i],dp[j-1]+a[i-j+1]);
        }
    }
    cout<<dp[n];
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