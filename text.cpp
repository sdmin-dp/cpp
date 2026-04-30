#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n;
ll idx;
ll trie[N][30];
ll cnt[N];
void insert(string s){
    ll p=0;
    for(auto &i:s){
        ll x=i-'a';
        if(trie[p][x]!=0)p=trie[p][x];
        else{trie[p][x]=++idx;p=idx;}
    }
    cnt[p]++;
}
ll query(string s){
    ll p=0;
    for(auto &i:s){
        ll x=i-'a';
        if(trie[p][x]!=0)p=trie[p][x];
        else return 0;
    }
    return cnt[p];
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        ll op;string s;
        cin>>op>>s;
        if(op=='I') insert(s);
        else cout<<query(s)<<el;
    }
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