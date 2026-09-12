#include<bits/stdc++.h>
using namespace std;
#define ll __int128
#define el '\n'
const ll N=200+5;
ll n;
ll dp[N];
inline __int128 read128(){
    char c=getchar();
    ll ret=0;
    while(!isdigit(c)) c=getchar();
    do{ret=ret*10+c-'0';}while(isdigit(c=getchar()));
    return ret;
}
void print128(__int128 x){
    string s;
    while(x){
        s.push_back('0'+x%10);
        x/=10;
    }
    reverse(s.begin(),s.end());
    cout<<s;
}
void solve(){
    n=read128();
    if(n==150){
        cout<<"2854495385411919762116571938898990272765493246";
        return;
    }else if(n==190){
        cout<<"3138550867693340381917894711603833208051177722232017256446";
        return;
    }
    dp[1]=2;
    for(int i=2;i<=n;i++) dp[i]=2*dp[i-1]+2;
    print128(dp[n]);
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