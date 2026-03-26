#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n;
string s;
vector<ll> g[N];
map<char,vector<string>> mp;
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s;
        mp[s[0]].push_back(s);
    }
    for(char i='a';i<=){

    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    cin>>T;
    while(T--){
        mp.clear();
        for(int i=1;i<=n;i++) g[i].clear();
        solve();
    }
    return 0;
}