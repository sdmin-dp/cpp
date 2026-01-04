#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
string s;
char c;
void solve(){
    cin>>s;
    if(s[0]=='-'){
        c='-';
        s.erase(0,1);
    }
    reverse(s.begin(),s.end());
    while(s[0]=='0'&&s.size()>1) s.erase(0,1);
    if(c=='-') s='-'+s;
    cout<<s<<el;
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