#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n;
ll idx=0;
map<string,ll> mp;
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        if(mp[s]!=0){
            cout<<mp[s]<<el;
        }else{
            mp[s]=++idx;
            cout<<idx<<el;
        }
    }
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