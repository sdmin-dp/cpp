#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
string s,t;
ll n,cnts[2],cntt[2];
void solve(){
    cin>>n>>s>>t;
    cnts[0]=cnts[1]=cntt[0]=cntt[1]=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='1'){
            cnts[i%2]++;
        }
    }
    for(int i=0;i<t.size();i++){
        if(t[i]=='1'){
            cntt[i%2]++;
        }
    }
    cout<<(cnts[0]==cntt[0]&&cnts[1]==cntt[1]?"YES":"NO")<<el;
    
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
