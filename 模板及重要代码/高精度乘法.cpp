#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e3+5;
string s,t;
ll a[N],b[N];
ll c[N*N];
string cheng(){
    reverse(s.begin(),s.end());
    reverse(t.begin(),t.end());
    for(int i=0;i<s.size();i++) a[i+1]=int(s[i]-48);
    for(int i=0;i<t.size();i++) b[i+1]=int(t[i]-48);
    a[0]=s.size();b[0]=t.size();
    ll mx=a[0]+b[0];
    for(int i=1;i<=a[0];i++) for(int j=1;j<=b[0];j++) c[i+j-1]+=a[i]*b[j];
    for(int i=1;i<=mx;i++){
        c[i+1]+=c[i]/10;
        c[i]%=10;
    }
    c[0]=mx;
    while(c[c[0]]==0&&c[0]>1) c[0]--;
    string res;
    for(int i=c[0];i>=1;i--) res=res+char(c[i]+'0');
    return res;
}
void solve(){
    cin>>s>>t;
    cout<<cheng();
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