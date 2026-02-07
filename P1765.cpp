#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
string s;
map<char,ll> mp;
void solve(){
    mp['a']=1;
    mp['b']=2;
    mp['c']=3;
    mp['d']=1;
    mp['e']=2;
    mp['f']=3;
    mp['g']=1;
    mp['h']=2;
    mp['i']=3;
    mp['j']=1;
    mp['k']=2;  
    mp['l']=3;
    mp['m']=1;
    mp['n']=2;
    mp['o']=3;
    mp['p']=1;
    mp['q']=2;
    mp['r']=3;
    mp['s']=4;
    mp['t']=1;
    mp['u']=2;
    mp['v']=3;
    mp['w']=1;
    mp['x']=2;
    mp['y']=3;
    mp['z']=4;
    mp[' ']=1;
    getline(cin,s);
    ll ans=0;
    for(auto i:s){
        ans+=mp[i];
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