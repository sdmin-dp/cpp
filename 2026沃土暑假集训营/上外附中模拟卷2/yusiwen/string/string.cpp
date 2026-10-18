#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
string s;
void solve(){
    cin>>s;
    if(s.size()==1){
        cout<<1;
        return;
    }
    if(s.size()==2){
        if(s[0]==s[1]) cout<<1;
        else cout<<0;
        return;
    }
    if(s.size()==3){
        if(s[0]==s[1]&&s[1]==s[2]&&s[2]==s[0]) cout<<6;
        else if((s[0]==s[1]||s[1]==s[2]||s[2]==s[0])) cout<<4;
        else cout<<3;
        return;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}