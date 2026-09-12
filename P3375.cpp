#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e6+5;
string s,t;
ll nxt[N];
ll n,m;
void solve(){
    cin>>s>>t;
    n=s.size(),m=t.size();
    for(int i=1,j=0;i<m;i++){
        while(j>0&&t[i]!=t[j]) j=nxt[j-1];
        if(t[i]==t[j]) j++;
        nxt[i]=j;
    }
    for(int i=0,j=0;i<n;i++){
        while(j>0&&s[i]!=t[j]) j=nxt[j-1];
        if(s[i]==t[j]) j++;
        if(j==m){
            cout<<i-m+1+1<<el;
            j=nxt[j-1];
        }
    }
    for(int i=0;i<m;i++) cout<<nxt[i]<<" ";
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