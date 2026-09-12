#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
string s;
ll ans=0;
void solve(){
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='C'){
            ans+=min((ll)(i),(ll)(s.size()-i-1))+1;
        }
    }
    cout<<ans;
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