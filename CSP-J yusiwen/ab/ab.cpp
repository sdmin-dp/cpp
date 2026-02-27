#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=10+5;
string s;
void solve(){
    ll cnt=0,ans=0;
    for(auto i:s){
        if(i=='B'){
            cnt++;
        }
        if(i=='A'){
            ans+=cnt;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("ab.in","r",stdin);
    freopen("ab.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}