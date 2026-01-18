#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=500+5;
string s,t;
ll a[N],b[N];
string ans;
void jia(){
    reverse(s.begin(),s.end());
    reverse(t.begin(),t.end());
    for(int i=0;i<s.size();i++) a[i+1]=int(s[i]-48);
    for(int i=0;i<t.size();i++) b[i+1]=int(t[i]-48);
    ll in=0;
    for(int i=1;i<=max(s.size(),t.size());i++){
        ll k=a[i]+b[i]+in;
        in=0;
        if(k>=10){
            ll x=k%10;
            k/=10;
            in=k;
            k=x;
        }
        ans=ans+char(k+48);
    }
    if(in!=0) ans+=char(in+48);
    reverse(ans.begin(),ans.end());
    cout<<ans;
}
void solve(){
    cin>>s>>t;
    jia();
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("xxx.in","r",stdin);
    // freopen("xxx.out","w",stdout);
    ll T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}