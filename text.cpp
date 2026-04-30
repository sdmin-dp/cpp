#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
string s,t;
ll nxt[N];
void solve(){
    while(1){
        memset(nxt,0,sizeof(nxt));
        cin>>s;
        if(s=="#")
            return;
        cin>>t;
        ll j=0;
        for(int i=1;i<t.size();i++){
            while(j>0&&t[i]!=t[j]) j=nxt[j-1];
            if(t[i]==t[j]) j++;
            nxt[i]=j;
        }
        
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