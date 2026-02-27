#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
string s;
void solve(){
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='0'||s[i]=='u'){
            s.insert(i+1," ");
        }
    }
    stringstream ss;
    ss<<s;
    while(ss>>s){
        cout<<char(s[0]-32);
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
        solve();
    }
    return 0;
}