#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
const ll mod=11;
string s;
bool f1=0,f2=0;
void solve(){
    cin>>s;
    f1=0,f2=0;
    ll sum=0;
    ll j=1;
    for(auto i:s){
        ll x=0;
        if(i=='X') x=10;
        else x=i-48;
        sum+=(x*(1<<18-j))%mod;
        j++;
    }
    if(sum%mod==1) f1=1;
    for()
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