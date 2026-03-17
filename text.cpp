#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll cnt;
void dfs(string s){
    if(s.size()==3){
        ll r=0,g=0,b=0;
        for(auto i:s){
            if(i=='r') r++; 
            else if(i=='g') g++;
            else b++;
        }
        if(r<=1&&b<=1){cnt++;cout<<s<<el;}
        return;
    }
    dfs(s+'r');
    dfs(s+'g');
    dfs(s+'b');
}
void solve(){
    dfs("");
    cout<<cnt;
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