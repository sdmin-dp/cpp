#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=2e4+5;
ll n;
ll idx;
int g[N][30];
ll cnt[N];
void insert(string s){
    ll p=0;
    for(auto i:s){
        ll x=i-'a';
        if(!g[p][x]) g[p][x]=++idx;
        p=g[p][x]; 
    }
    cnt[p]++;
}
ll find(string s){
    ll p=0;
    for(auto i:s){
        ll x=i-'a';
        if(!g[p][x]) return 0;
        p=g[p][x]; 
    }
    return cnt[p];
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        char c;
        string s;
        cin>>c>>s;
        if(c=='I'){
            insert(s);
        }
        else{
            cout<<find(s)<<el;
        }
    }
}

int main() {
    //ios::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}