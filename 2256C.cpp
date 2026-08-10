#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,k;
string s;
void solve(){
    cin>>n>>k;
    cin>>s;
    s=" "+s;
    ll sum1=0,sum2=0;
    for(int i=1;i<=2*n;i++){
        if(s[i]=='0') continue;
        if(i%2==1){
            ll nxt=i+1;
            if(nxt==2*n+1) nxt=1;
            if(s[nxt]=='1') sum1++;
            else sum2++;
        }else{
            ll nxt=i+1;
            if(nxt==2*n+1) nxt=1;
            if(s[nxt]=='1') sum2++;
            else sum1++;
        }
    }
    cout<<sum2<<" "<<sum1<<el;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}