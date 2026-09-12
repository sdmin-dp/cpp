#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
string s,t;
//s先，t中
void dfs(ll sl,ll sr,ll tl,ll tr){
    ll x;
    for(int i=tl;i<=tr;i++) if(t[i]==s[sl]){x=i;break;}
    if(x>tl) dfs(sl+1,x-tl+sl,tl,x-1);
    if(tr>x) dfs(x-tl+sl+1,sr,x+1,tr);
    cout<<s[sl];
}
void solve(){
    cin>>s>>t;
    dfs(0,s.size()-1,0,t.size()-1);
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