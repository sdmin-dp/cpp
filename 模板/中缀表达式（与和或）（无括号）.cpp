#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
string s;
stack<bool> st;
void solve(){
    cin>>s;
    for(size_t i=0;i<s.size();i++){
        char c=s[i];
        if(c=='0'||c=='1') st.push(c-48);
        else if(c=='&'){
            bool a=st.top();
            char d=s[++i];
            st.push(a&&(d-48));
        }
    }
    while(!st.empty()){
        if(st.top()){
            cout<<1;
            return;
        }
        st.pop();
    }
    cout<<0;
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