#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n;
string s;
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        string s;cin>>s;
        ll x=(s[0]-'a'+1);
        ll c=0;
        if(x>=1&&x<=3) c=2;
        if(x>=4&&x<=6) c=3;
        if(x>=7&&x<=9) c=4;
        if(x>=10&&x<=12) c=5;
        if(x>=13&&x<=15) c=6;
        if(x>=16&&x<=19) c=7;
        if(x>=20&&x<=22) c=8;
        if(x>=23&&x<=26) c=9;
        cout<<c;
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