#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n;
bool ishuiwen(ll x){
    string s=to_string(x);
    string s2=s;
    reverse(s.begin(),s.end());
    return (s2==s);
}
void solve(){
    cin>>n;
    ll cnt=0;
    for(int i=1;i<=n;i++){
        if(ishuiwen(i)){
            cnt++;
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