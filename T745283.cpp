#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
string s;
void solve(){
    cin>>s;
    if(s[0]>='a'&&s[0]<='z') s[0]=s[0]+'A'-'a';
    for(int i=1;i<=s.size()-1;i++){
        if(s[i]>='A'&&s[i]<='Z'){
            s.insert(i,".");
            i++;
        }
        
    }
    for(int i=1;i<=s.size()-1;i++){
        if(s[i-1]=='.'&&s[i]>='a'&&s[i]<='z') s[i]=s[i]+'A'-'a';
    }
    if(s[s.size()-1]!='.') s+='.';
    cout<<s;
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