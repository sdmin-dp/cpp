#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
stringstream ss;
string s;
stack<ll> st;
void solve(){
    getline(cin,s);
    reverse(s.begin(),s.end());
    ss<<s;
    while(ss>>s){
        ll x=0;
        if(s.size()==1&&!(s[0]>='1'&&s[0]<='9')){
            ll b=st.top();st.pop();
            ll a=st.top();st.pop();
            if(s=="+") st.push(a+b);
            if(s=="-") st.push(a-b);
            if(s=="*") st.push(a*b);
            if(s=="/") st.push(a/b);
            if(s=="%") st.push(b%a);
        }
        else{
            reverse(s.begin(),s.end());
            x=stoll(s);
            st.push(x);
        }
    }
    cout<<st.top();
}

int main() {
    //ios::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}