#include<bits/stdc++.h>
using namespace std;
string s;
void solve(){
    cin>>s;
    string t="";
    for(int i=0;i<s.size();i++){
        if(i>0&&s[i]>='A'&&s[i]<='Z'&&s[i-1]!='.'){
            t+='.';
        }
        t+=s[i];
    }
    if(t.back()!='.')t+='.';
    if(t[0]>='a'&&t[0]<='z')t[0]=t[0]-'a'+'A';
    for(int i=1;i<t.size();i++){
        if(t[i-1]=='.'&&t[i]>='a'&&t[i]<='z'){
            t[i]=t[i]-'a'+'A';
        }
    }
    cout<<t;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    int T=1;
    while(T--){
        solve();
    }
    return 0;
}