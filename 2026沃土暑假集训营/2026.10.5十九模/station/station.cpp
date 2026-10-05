#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;

void solve(){
    string s;
    getline(cin,s);
    s.push_back('.');
    ll cnt=0;
    string mx="";
    ll res1=0,res2=0;
    for(int i=0;i<s.size();i++){
        string t="";
        ll cnt2=0;
        while((s[i]>='0'&&s[i]<='9')||(s[i]>='a'&&s[i]<='z')){
            t.push_back(s[i]);
            if((s[i]>='0'&&s[i]<='9')) cnt2++;
            i++;
        }
        if(t=="") continue;
        if(cnt2==t.size()) res1++;
        if(cnt2!=0) res2++;
        cnt++;
        if(t.size()>mx.size()) mx=t;
    }
    cout<<cnt<<el<<mx<<el<<res1<<" "<<res2<<el;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("station.in","r",stdin);
    freopen("station.out","w",stdout);
    ll T=1;
    cin>>T;
    string sdfv;
    getline(cin,sdfv);
    while(T--){
        solve();
    }
    return 0;
}