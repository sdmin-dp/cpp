#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n;
ll a[N];
inline __int128 read(){
    char c=getchar();
    ll ret=0;
    while(!isdigit(c)) c=getchar();
    do{ret=ret*10+c-'0';}while(isdigit(c=getchar()));
    return ret;
}
void print(__int128 x){
    string s;
    while(x){
        s.push_back('0'+x%10);
        x/=10;
    }
    reverse(s.begin(),s.end());
    cout<<s;
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    ll cnt=0;
    for(int l=1;l<=n;l++){
        for(int r=l;r<=n;r++){
            ll sum=1;
            for(int i=l;i<=r;i++) sum*=a[i];
            ll k=sqrt(sum);
            if(k*k==sum) cnt++;
        }
    }
    cout<<cnt;
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