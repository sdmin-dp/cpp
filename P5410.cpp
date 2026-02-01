#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
vector<ll> z,p;
void getz(string &s){
    ll ns=s.size(),ans=0;
    ll L=1,R=1;
    z.clear();
    z.resize(ns,0);
    while(z[1]+1<ns&&s[1+z[1]]==s[1+z[1]]) z[1]++;
    for(int i=2;i<ns;i++){
        if(i<R){
            ll k=i-L+1;
            z[i]=min(z[k],R-i+1);
        }
        while(i+z[i]<=ns&&s[i+z[i]]==s[1+z[i]]){
            z[i]++;
        }
        if(i+z[i]-1>R){
            L=i,R=i+z[i]-1;
        }
    }
    for(int i=1;i<ns;i++){
        ans^=i*(z[i]+1);
    }
}
void exkmp(string &s, string &t)
{
    ll ns=s.size(),nt=t.size(),ans=0;
    ll L=1,R=1;
    p.clear();
    p.resize(ns, 0);
    while (1+p[1]<ns&&1+p[1]<nt&&s[1+p[1]]==t[1+p[1]]) p[1]++;
    for(int i=2;i<ns;i++){
        if(i<=R){
            int k=i-L+1;
            p[i]=min(z[k],R-i+1);
        }
        while(i+p[i]<ns&&1+p[i]<nt&&s[i+p[i]]==t[1+p[i]])
            p[i]++;
        if(i+p[i]-1>R)
            L=i,R=i+p[i]-1;
    }
    for(int i=1;i<ns;i++)
        ans^=i*(1+p[i]);
    cout<<ans;
}
void solve(){
    string s,t;
    cin>>s>>t;
    s=' '+s;
    t=' '+t;
    getz(s);
    exkmp(s,t);
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