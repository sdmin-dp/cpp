#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
string s,t;
stringstream ss;
stack<ll> st;
void solve(){
    getline(cin,s);
    ss<<s;
    while(ss>>s){
        if(s=="*"){
            ll a=st.top();st.pop();
            ss>>s;
            ll b=stoll(s);
            st.push(a*b);
        }
        else if(s=="/"){
            ll a=st.top();st.pop();
            ss>>s;
            ll b=stoll(s);
            st.push(a*b);
        }else if(s=="-"){
            ss>>s;
            ll b=stoll(s);
            st.push(-b);
        }else if(s=="+"){

        }else{
            st.push(stoll(s));
        }
    }
    ll ans=0;
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    cout<<ans;
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