#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;

void solve(){
    string s;
    cin>>s;
    ll last1=0,last2=0;
    //1:奇a偶b
    //2:奇b偶a
    for(int i=0;i<s.size();i++){
        if(i%2==1&&s[i]=='a'||i%2==0&&s[i]=='b'){

        }else if(i%2==1&&s[i]=='b'||i%2==0&&s[i]=='a'){

        }else{
            
        }
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