#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e6+5;
string s;
ll n;
ll nxt[N];
void solve(){
    cin>>n>>s;
    for(int i=1,j=0;i<n;i++){
        while(j>0&&s[i]!=s[j]) j=nxt[j-1];
        if(s[i]==s[j]) j++;
        nxt[i]=j;
    }
    ll cnt=0;
    for(int i=1;i<n;i++){
        ll j=i;
        while(nxt[j]) j=nxt[j]-1;
        if(nxt[i]!=0) nxt[i]=j+1;
        cnt+=i-j;
    }
    cout<<cnt;
}

int main() {
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