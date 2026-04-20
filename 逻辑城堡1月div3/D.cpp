#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
void walk(char &f,ll &s,pair<ll,ll> &x){
    if(f=='U'){x.second+=s;f='R';}
    else if(f=='D'){x.second-=s;f='L';}
    else if(f=='L'){x.first-=s;f='U';}
    else if(f=='R'){x.first+=s;f='D';}
}
void solve(){
    char c;
    ll n;
    pair<ll,ll> ans={0,0};
    cin>>c>>n;
    for(ll i=1;i<=n;i++) walk(c,i,ans);
    cout<<ans.first<<" "<<ans.second<<el;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("xxx.in","r",stdin);
    // freopen("xxx.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}