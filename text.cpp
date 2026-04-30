#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
string s,t;
ll nxt[N];
void solve(){
    while(1){
        cin>>s;
        if(s=="#") break;
        cin>>t;
        for(int i=1,j=0;i<t.size();i++){
            while(j>0&&t[i]!=t[j]) j=nxt[j-1];
            if(t[i]==t[j]) j++;
            nxt[i]=j;
        }
        ll cnt=0;
        for(int i=0,j=0;i<s.size();i++){
            while(j>0&&s[i]!=t[j]) j=nxt[j-1];
            if(s[i]==t[j]) j++;
            if(j==t.size()){
                j=0;
                cnt++;
            }
        }
        cout<<cnt<<el;
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