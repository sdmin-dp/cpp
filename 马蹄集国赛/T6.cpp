#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=300+5;
ll n;
string s[N];
ll qianzhui(string s,string t){
    ll cnt=0;
    for(int i=0;i<min(s.size(),t.size());i++){
        if(s[i]==t[i]) cnt++;
        else break;
    }
    return cnt;
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ll cnt=qianzhui(s[i],s[j]);
            ans^=cnt;
        }
    }
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