#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
string s;
vector<ll> v;
void solve(){
    cin>>s;
    for(int i=0;i<s.size();i++) if(s[i]=='t') v.push_back(i);
    ll sz=v.back()-v.front()+1;
    ll x=v.size();
    double ans=(x*1.0-2.0)/(sz*1.0-2.0);
    printf("%.3f",ans);
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