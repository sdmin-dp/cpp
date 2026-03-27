#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
string s;
/*
小 M 的作文是一个仅包含纯英文字母和 . 的字符串 S，且第一个字符一定是字母，不存在两个相邻的 .。你需要帮助他依次进行这两种操作：
对于所有非首字符的大写字母，如果其前一个字符不是 . 则在其前插入 .。然后如果字符串的最后一个字符不是 .，则在最后加入 .。
对于所有 . 的后一个字母和首字母，如果其为小写，则改为大写。
*/
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