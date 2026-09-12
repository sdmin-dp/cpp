#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
string s;
ll res;
ll x=1;
void solve(){
    cin>>s;
    for(int i=0;i<s.size()-1;i++){
        if(s[i]>='0'&&s[i]<='9'){
            res+=(s[i]-48)*x;
            x++;
        }
    }
    res%=11;
    char c;
    string t;
    if(res==10) c='X';
    else{t=to_string(res);c=t[0];}
    if(s[s.size()-1]==c){
        cout<<"Right";
    }
    else{
        s.pop_back();
        cout<<s;
        cout<<c;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("xxx.in","r",stdin);
    // freopen("xxx.out","w",stdout);
    ll T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}