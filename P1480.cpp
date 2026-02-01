#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
string s;
ll t;
ll a[N];
ll p;
string res;
string chu(){
    for(int i=0;i<s.size();i++){
        p=p*10+s[i]-'0';
        res.push_back(p/t+'0');
        p%=t;
    }
    ll k=0;
    while(res[k]=='0'&&k<res.size()-1) k++;
    res.erase(0,k);
    return res;
}
void solve(){
    cin>>s;
    cin>>t;
    cout<<chu();
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