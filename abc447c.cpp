#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
string s,t;
string s1,t1;
void solve(){
    cin>>s>>t;
    for(auto i:s) if(i!='A') s1.push_back(i);
    for(auto i:t) if(i!='A') t1.push_back(i);
    if(s1!=t1) cout<<0;

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