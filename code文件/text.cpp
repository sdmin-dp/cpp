#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;

void solve(){
    string t=1;
    reverse(t.begin(),t.end());
    if(t.size()>1&&t[t.size()-1]=='0') t.pop_back();
    reverse(t.begin(),t.end());
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}